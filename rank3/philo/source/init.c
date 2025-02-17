/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:53:57 by karocha-          #+#    #+#             */
/*   Updated: 2025/02/17 19:09:38 by karocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	init_table(t_table *table, int ac, char ** av)
{
	table->n_philos = ft_atoi(av[1]);
	table->time_to_die = ft_atoi(av[2]);
	table->time_to_eat = ft_atoi(av[3]);
	table->time_to_sleep = ft_atoi(av[4]);
	table->dead = 0;
	if (ac = 6)
		table->n_to_eat = ft_atoi(av[5]);
	else
		table->n_to_eat = 0;
}

int	init_philos(t_table *table)
{
	int	i;

	i = -1;
	table->philos = ft_calloc(sizeof(t_philos), table->n_philos);
	if (!table->philos)
		return (0);
	table->forks = ft_calloc(sizeof(pthread_mutex_t), table->n_philos );
	if (!table->forks)
		return (0);
	while (++i < table->n_philos)
	{
		table->philos[i].index = i + 1;
		table->philos[i].last_time_eaten = 0;
		table->philos[i].n_ate = 0;
		pthread_mutex_init(&table->forks[i], NULL);
	}
	return (1);
}
