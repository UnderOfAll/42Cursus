/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 19:26:04 by karocha-          #+#    #+#             */
/*   Updated: 2025/06/20 20:01:24 by karocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

long	ft_atoi(const char *str)
{
	size_t	i;
	size_t	res;
	int		sign;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
		res = res * 10 + str[i++] - '0';
	return (res * sign);
}

static	int	str_nb_only(char *str)
{
	int	i;

	i = -1;
	if (!str)
		return (1);
	while (str && str[++i])
		if (str[i] < '0' || str[i] > '9')
			return (1);
	return (0);
}

int	parser(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac < 5 || ac > 6)
	{
		write(2, "Error: Invalid number of arguments.\n", 35);
		return (1);
	}
	while (av[++i])
	{
		if (str_nb_only(av[i]) || ft_atoi(av[i]) > INT_MAX
			|| ft_atoi(av[i]) < INT_MIN || ft_atoi(av[i]) <= 0)
		{
			write(2, "Error: Arguments must be numbers.\n", 34);
			return (1);
		}
	}
	return (0);
}
