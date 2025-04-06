/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 19:56:43 by karocha-          #+#    #+#             */
/*   Updated: 2025/04/06 19:40:53 by karocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	apocalipse(t_table *table)
{
	pthread_mutex_lock(&table->reaper);
	if (!table->dead)
	{
		table->dead = 1;
		output_event(table, 4);
	}
	pthread_mutex_unlock(&table->reaper);
}

static void	meal_check(t_table *table)
{
	int	i;
	int	full;

	if (table->n_to_eat == 0)
		return ;
	full = 1;
	i = -1;
	while (++i < table->n_philos)
	{
		pthread_mutex_lock(&table->ate);
		if (table->philos[i].n_ate < table->n_to_eat)
			full = 0;
		pthread_mutex_unlock(&table->ate);
		if (!full)
			break;
	}
	if (full)
	{
		pthread_mutex_lock(&table->ate);
		table->warn = 1;
		pthread_mutex_unlock(&table->ate);
	}
}

static void	health_monitor(t_table *table)
{
	int		i;
	time_t	current;

	while (!should_stop(table))
	{
		i = -1;
		while (++i < table->n_philos && should_stop(table))
		{
			current = time_in_ms();
			pthread_mutex_lock(&table->ate);
			if (current - table->philos[i].last_time_eaten > table->time_to_die)
			{
				pthread_mutex_unlock(&table->ate);
				apocalipse(table);
				break ;
			}
			pthread_mutex_unlock(&table->ate);
		}
		meal_check(table);
		better_usleep(850, table);
	}
}

void	threads(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->n_philos)
		if (pthread_create(&table->philos[i].thread, NULL, &routine,
			&table->philos[i]))
			return ;
	if (table->n_philos > 1)
		health_monitor(table);
	i = -1;
	while(++i < table->n_philos)
		pthread_join(table->philos[i].thread, NULL);
}
