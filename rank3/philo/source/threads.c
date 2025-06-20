/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 19:56:43 by karocha-          #+#    #+#             */
/*   Updated: 2025/06/20 20:42:19 by karocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	apocalipse(int i)
{
	pthread_mutex_lock(&table()->reaper);
	pthread_mutex_lock(&table()->ate);
	if (table()->dead || table()->warn)
	{
		pthread_mutex_unlock(&table()->reaper);
		pthread_mutex_unlock(&table()->ate);
		return ;
	}
	table()->dead = 1;
	printf("%ld, %d it's dead\n",
		(time_in_ms() - table()->start), table()->philos[i].index);
	pthread_mutex_unlock(&table()->reaper);
	pthread_mutex_unlock(&table()->ate);
}

static void	meal_check(void)
{
	int	i;

	i = -1;
	while (++i < table()->n_philos)
	{
		pthread_mutex_lock(&table()->ate);
		if (table()->philos[i].n_ate < table()->n_to_eat)
		{
			pthread_mutex_unlock(&table()->ate);
			return ;
		}
		pthread_mutex_unlock(&table()->ate);
		i++;
	}
	pthread_mutex_lock(&table()->ate);
	table()->warn = 1;
	pthread_mutex_unlock(&table()->ate);
}

static void	health_monitor(void)
{
	int		i;
	time_t	current;

	while (!table()->dead && !table()->warn)
	{
		i = -1;
		while (++i < table()->n_philos)
		{
			current = time_in_ms() - table()->start;
			pthread_mutex_lock(&table()->ate);
			if (current >= ((table()->philos)[i].last_time_eaten
				+ table()->time_to_die))
			{
				pthread_mutex_unlock(&table()->ate);
				apocalipse(i);
				break ;
			}
			else
				pthread_mutex_unlock(&table()->ate);
			i++;
		}
		if (table()->n_to_eat)
			meal_check();
	}
}

void	threads(void)
{
	int	i;

	i = -1;
	while (++i < table()->n_philos)
		if (pthread_create(&table()->philos[i].thread, NULL, &routine,
				(void *)&table()->philos[i]))
			return ;
	if (table()->n_philos > 1)
		health_monitor();
	i = -1;
	while (++i < table()->n_philos)
		if (pthread_join(table()->philos[i].thread, NULL))
			return ;
}
