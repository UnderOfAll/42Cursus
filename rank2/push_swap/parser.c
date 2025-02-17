/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 19:55:32 by karocha-          #+#    #+#             */
/*   Updated: 2024/12/27 18:10:53 by karocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	parser(int ac, char **av)
{
	if (numcheck(av))
		return (1);
	else if (limit(av))
		return (1);
	else if (duplicates(ac, av))
		return (1);
	return (0);
}

int	duplicates(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = i + 1;
		while (j < ac)
		{
			if (ft_atol(av[i]) == ft_atol(av[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	limit(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (ft_atol(av[i]) < INT_MIN || ft_atol(av[i]) > INT_MAX)
			return (1);
		i++;
	}
	return (0);
}

int	numcheck(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		if (av[i][0] == '-' && av[i][1])
			j++;
		else if (av[i][0] == '-' && !av[i][1])
			return (1);
		while (av[i][j])
		{
			if (av[i][j] < 48 || av[i][j] > 57)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
