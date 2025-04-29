/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 21:41:16 by karocha-          #+#    #+#             */
/*   Updated: 2025/04/29 03:29:48 by karocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	do_sleep(t_philos *philos)
{
	output_event(philos, 2);
	usleep(table()->time_to_sleep * 850);
}

void	eat(t_philos *philos)
{
	if (philos->index == table()->n_philos)
	{
		pthread_mutex_lock(&table()->forks[0]);
		pthread_mutex_lock(&table()->forks[philos->index - 1]);
	}
	else
	{
		pthread_mutex_lock(&table()->forks[philos->index - 1]);
		pthread_mutex_lock(&table()->forks[philos->index]);
	}
	ft_eat(philos);
	if (philos->index == table()->n_philos)
    {
        pthread_mutex_unlock(&table()->forks[philos->index - 1]);
        pthread_mutex_unlock(&table()->forks[0]);
    }
    else
    {
        pthread_mutex_unlock(&table()->forks[philos->index]);
        pthread_mutex_unlock(&table()->forks[philos->index - 1]);
    }
}

void	think(t_philos *philos)
{
	output_event(philos, 3);
}

static void	alone(t_philos *philos)
{
	int	i;

	i = philos->index - 1;
	pthread_mutex_lock(&table()->forks[i]);
	output_event(philos, 0);
	pthread_mutex_unlock(&table()->forks[i]);
	usleep(table()->time_to_die * 850);
	output_event(philos, 4);
}

void	*routine(void *arg)
{
	t_philos	*philos;

	philos = (t_philos *)arg;
	if (table()->n_philos == 1)
	{
		alone(philos);
		return (NULL);
	}
	if (philos->index % 2 != 0)
		usleep(table()->n_philos * 850);
	while (1)
	{
		usleep(100);
		if (!philo_loop(philos))
			return (NULL);
	}
	return (NULL);
}
