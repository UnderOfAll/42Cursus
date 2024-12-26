/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:06:39 by karocha-          #+#    #+#             */
/*   Updated: 2024/12/26 20:15:06 by karocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_arg(char **av)
{
	int	i;

	if (!av)
		return (0);
	i = 0;
	while (av[i])
		i++;
	if (av[i] == 'r' && av[i - 1] == 'e' && av[i - 2] == 'b' && av[i - 3] == '.')
		return (1);
	else
		return (0);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		if (check_arg)
		{
			
		}
	}
	else
	{
		ft_printf("Error, invalid input\n");
		exit (1);
	}
	return (0);
}
