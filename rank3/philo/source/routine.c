/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 21:41:16 by karocha-          #+#    #+#             */
/*   Updated: 2025/03/30 21:13:32 by karocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	sleep(t_table *table)
{
	output_event(table, 2);
	usleep(table->time_to_sleep * 850);
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


