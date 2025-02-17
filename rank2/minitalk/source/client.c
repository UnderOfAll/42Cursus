/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 15:26:37 by karocha-          #+#    #+#             */
/*   Updated: 2025/01/26 23:29:19 by karocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

/*this one works pretty hard to understand, but basically, it checks for each
bit of the whole byte to send either SIGUSR1(1) or SIGUSR2(0) which are the bits
by iterating through each bit of the respective character.
*/
static	void	null_handler(int pid, int aux, int bit)
{
	aux = 0;
	bit = 0;
	while (bit < 8)
	{
		if ((aux << bit) & 0b10000000)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit++;
		usleep(100);
	}
}

void	action(int pid, char *message)
{
	int	bit;
	int	aux;

	bit = 0;
	while (*message)
	{
		aux = *(message);
		while (bit < 8)
		{
			if (aux << bit & 0b10000000)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			bit++;
			usleep(100);
		}
		message++;
		bit = 0;
	}
	null_handler(pid, aux, bit);
}

int	main (int ac, char **av)
{
	if (ac != 3)
	{
		ft_printf("Invalid number of arguments\n");
		exit (1);
	}
	else
		action(ft_atoi(av[1]), av[2]);
	return (0);
}
