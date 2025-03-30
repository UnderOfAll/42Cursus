/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 21:43:07 by karocha-          #+#    #+#             */
/*   Updated: 2025/03/30 21:06:06 by karocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

time_t	time_in_ms(void)
{
	struct	timeval	t;

	if (gettimeofday(&time, NULL) == -1)
		return (ft_putstr_fd("Error getting time\n", 2), 0);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

void	output_event(t_table *table, int type)
{
	long	i;

	i = time_in_ms() - table->start;

	pthread_mutex_lock(&table->print);
	pthread_mutex_lock(&table->reaper);
	pthread_mutex_lock(&table->ate);
	if (!table->dead && !table->warn)
	{
		printf("%ld, %d", i,table->philos->index);
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
	pthread_mutex_unlock(&table->print);
	pthread_mutex_unlock(&table->reaper);
	pthread_mutex_unlock(&table->ate);
}

void	ft_eat(t_table *table)
{
	output_event(table, 0);
	output_event(table, 0);
	output_event(table, 1);
	pthread_mutex_lock(&table->ate);
	table->philos->last_time_eaten = (time_in_ms() - table->start);
	table->philos->n_ate + 1;
	pthread_mutex_unlock(&table->ate);
	usleep(table->time_to_eat * 850);
}
