/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 19:26:04 by karocha-          #+#    #+#             */
/*   Updated: 2025/02/20 17:47:32 by karocha-         ###   ########.fr       */
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
	while (str[++i])
		if (str[i] < '0' || str[i] > '9')
			return (1);
	return (0);
}

int	parser(char **av)
{
	if (str_nb_only(av[1]) || str_nb_only(av[2]) || str_nb_only(av[3])
		|| str_nb_only(av[4]) || (av[5] && str_nb_only(av[5])))
		return (ft_putstr_fd("Some of the arguments is not a number\n", 2), 1);
	if (ft_atoi(av[1]) > P_MAX || ft_atoi(av[1]) <= 0
		|| str_nb_only(av[1]))
		return (ft_putstr_fd("Please, atleast 1 philo and max 250;-;\n",2), 1);
	if (ft_atoi(av[2]) <= 0 || str_nb_only(av[2]))
		return (ft_putstr_fd("Time to die has to be atleast 1\n", 2), 1);
	if (ft_atoi(av[3]) <= 0 || str_nb_only(av[3]))
		return (ft_putstr_fd("Time to eat has to be atleast 1\n", 2), 1);
	if (ft_atoi(av[4]) <= 0 || str_nb_only(av[4]))
		return (ft_putstr_fd("Time to sleep has to be atleast 1\n", 2), 1);
	if (av[5] && (ft_atoi(av[5]) <= 0 || str_nb_only(av[5])))
		return (ft_putstr_fd("Invalid number of times each philo eat\n", 2), 1);
	return (0);
}
