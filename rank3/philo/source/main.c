/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 19:07:22 by karocha-          #+#    #+#             */
/*   Updated: 2025/04/06 19:44:58 by karocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static	void	exit_program(t_table *table)
{
	int	i;

	i = -1;
	pthread_mutex_destroy(&table->print);
	pthread_mutex_destroy(&table->reaper);
	pthread_mutex_destroy(&table->ate);
	while(table->n_philos > ++i)
		pthread_mutex_destroy(&table->forks[i]);
	free(table->forks);
	free(table->philos);
	free(table);
}

int	main(int ac, char **av)
{
	static t_table	*table;

	table = ft_calloc(sizeof(t_table), 1);
	if (!table)
		return (0);
	if (ac != 5 && ac != 6)
		return (ft_putstr_fd("Wrong number of arguments\n", 2), 1);
	if (parser(av))
		return (free(table), 0);
	init_table(table, ac, av);
	if (!init_philos(table))
		return (free(table), 0);
	threads(table);
	printf("good\n");
	exit_program(table);
	return (0);
}
