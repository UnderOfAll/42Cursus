/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 19:07:22 by karocha-          #+#    #+#             */
/*   Updated: 2025/04/23 13:44:19 by karocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/*need this bad boy here, because the prototype of the function routine doesnt
allow me to transfer the table content through t_table *table like i normally
would*/
t_table	*table(void)
{
	static t_table	table;

	return (&table);
}

static	void	exit_program()
{
	int	i;

	i = -1;
	pthread_mutex_destroy(&table()->print);
	pthread_mutex_destroy(&table()->reaper);
	pthread_mutex_destroy(&table()->ate);
	while(table()->n_philos > ++i)
		pthread_mutex_destroy(&table()->forks[i]);
	free(table()->forks);
	free(table()->philos);
}

int	main(int ac, char **av)
{
	if (parser(ac, av))
		return (0);
	init_table(ac, av);
	if (!init_philos())
		return (0);
	threads();
	exit_program();
	return (0);
}
