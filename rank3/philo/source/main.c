/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 19:07:22 by karocha-          #+#    #+#             */
/*   Updated: 2025/02/17 19:09:53 by karocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	main(int ac, char **av)
{
	t_table	*table;

	table = NULL;
	if (ac != 5 && ac != 6)
		return (ft_putstr_fd("Wrong number of arguments\n", 2), 1);
	if (parser(av))
		return (1);
	init_table(table, ac, av);
	if (!init_philos(table))
		return (1);
	printf("good\n");
	return (0);
}
