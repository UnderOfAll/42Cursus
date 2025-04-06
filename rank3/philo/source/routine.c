/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 21:41:16 by karocha-          #+#    #+#             */
/*   Updated: 2025/04/06 20:01:27 by karocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	do_sleep(t_table *table)
{
	output_event(table, 2);
	better_usleep(table->time_to_sleep * 850, table);
}

void	eat(t_table *table)
{
	if (table->philos->index == table->n_philos)
	{
		pthread_mutex_lock(&table->forks[0]);
		pthread_mutex_lock(&table->forks[table->philos->index - 1]);
	}
	else
	{
		pthread_mutex_lock(&table->forks[table->philos->index - 1]);
		pthread_mutex_lock(&table->forks[table->philos->index]);
	}
	ft_eat(table);
	if (table->philos->index == table->n_philos)
    {
        pthread_mutex_unlock(&table->forks[table->philos->index - 1]);
        pthread_mutex_unlock(&table->forks[0]);
    }
    else
    {
        pthread_mutex_unlock(&table->forks[table->philos->index]);
        pthread_mutex_unlock(&table->forks[table->philos->index - 1]);
    }
}

void	think(t_table *table)
{
	output_event(table, 3);
}

void	*alone(t_table *table)
{
	int	i;

	i = table->philos->index - 1;
	pthread_mutex_lock(&table->forks[i]);
	pthread_mutex_lock(&table->reaper);
	output_event(table, 0);
	table->dead = 1;
	pthread_mutex_unlock(&table->forks[i]);
	pthread_mutex_unlock(&table->reaper);
	better_usleep(table->time_to_die * 850, table);
	output_event(table, 4);
	return (NULL);
}

void	*routine(void *arg)
{
	t_philos	*philos;
	t_table		*table;

	philos = (t_philos *)arg;
	table = philos->table;
	if (table->n_philos == 1)
		return (alone(table));
	if (philos->index % 2 != 0)
		better_usleep(table->time_to_eat / 2, table);
	while (1)
	{
		philo_loop(table);
		if (should_stop(table))
			break ;
		better_usleep(100, table);
	}
	return (NULL);
}
