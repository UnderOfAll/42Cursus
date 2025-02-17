/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 15:27:11 by karocha-          #+#    #+#             */
/*   Updated: 2025/01/26 23:25:01 by karocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"


//bit-wise operators work like | to adds the respective bit to the amount of 
//bits that we have, and & works for subtracting so we have only the bits that
//are common in both statements
void	converter(int signal_input)
{
	static	int				i;
	static	unsigned char	character;

	if (i == 0)
		character = 0;
	if (signal_input == SIGUSR2)
		character <<= 1;
	else if (signal_input == SIGUSR1)
		character = (character << 1) | 0b00000001;
	i++;
	if (i == 8)
	{
		if (character == '\0')
			ft_printf("\n");
		else
			ft_printf("%c", character);
		i = 0;
		character = 0;
	}
}

//SIGUSR1 sends a 1 bit, and SIGUSR2 sends a 0 bit
int main(void)
{
	ft_printf("PID: %i\n", getpid());
	while (1)
	{
		signal(SIGUSR1, converter);
		signal(SIGUSR2, converter);
	}
	return (0);
}
