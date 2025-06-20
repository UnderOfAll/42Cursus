/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 21:43:07 by karocha-          #+#    #+#             */
/*   Updated: 2025/06/20 20:41:03 by karocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

time_t	time_in_ms(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		return (ft_putstr_fd("Error getting time\n", 2), 0);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	output_event(t_philos *philos, int type)
{
	long	i;

	pthread_mutex_lock(&table()->print);
	i = time_in_ms() - table()->start;
	pthread_mutex_lock(&table()->reaper);
	pthread_mutex_lock(&table()->ate);
	if (!table()->dead && !table()->warn)
	{
		printf("%ld, %d ", i, philos->index);
		if (type == 0)
			printf("took a fork\n");
		else if (type == 1)
			printf("eating..\n");
		else if (type == 2)
			printf("sleeping\n");
		else if (type == 3)
			printf("thinking..\n");
		else if (type == 4)
			printf("it's dead\n");
	}
	pthread_mutex_unlock(&table()->print);
	pthread_mutex_unlock(&table()->reaper);
	pthread_mutex_unlock(&table()->ate);
}

void	ft_eat(t_philos *philos)
{
	output_event(philos, 0);
	output_event(philos, 0);
	output_event(philos, 1);
	pthread_mutex_lock(&table()->ate);
	philos->last_time_eaten = (time_in_ms() - table()->start);
	philos->n_ate++;
	pthread_mutex_unlock(&table()->ate);
	usleep(table()->time_to_eat * 850);
}

int	philo_loop(t_philos *philos)
{
	pthread_mutex_lock(&table()->reaper);
	pthread_mutex_lock(&table()->ate);
	if (table()->dead || table()->warn)
	{
		pthread_mutex_unlock(&table()->reaper);
		pthread_mutex_unlock(&table()->ate);
		return (0);
	}
	pthread_mutex_unlock(&table()->reaper);
	pthread_mutex_unlock(&table()->ate);
	eat(philos);
	do_sleep(philos);
	think(philos);
	return (1);
}

/*void	print_allinfo(int i)
{
	printf("Number of philosophers: %d\n", table()->n_philos);
	printf("Philosopher ID: %d\n", table()->philos[i].index);
	printf("Time to die: %d ms\n", table()->time_to_die);
	printf("Time to eat: %d ms\n", table()->time_to_eat);
	printf("Time to sleep: %d ms\n", table()->time_to_sleep);
	if (table()->dead == 1)
		printf("Is dead: yes is dead\n");
	else
		printf("is alive\n");
	if (table()->n_to_eat > 0)
		printf("Number of times each philosopher must eat: %d\n",
			table()->n_to_eat);
	printf("Number of times eaten: %d\n", table()->philos[i].n_ate);
	printf("Start time: %ld\n", table()->start);
	printf("\n");
}*/
