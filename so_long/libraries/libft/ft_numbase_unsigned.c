/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbase_unsigned.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:09:04 by karocha-          #+#    #+#             */
/*   Updated: 2024/08/13 14:18:26 by karocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(int c);
int	ft_putstr(char *str);

int	num_unsigned(unsigned long long nbr, unsigned int base, int upperbase,
		char specifier)
{
	int		count;
	char	*bases;

	if (upperbase)
		bases = "0123456789ABCDEF";
	else
		bases = "0123456789abcdef";
	count = 0;
	if (specifier == 'p' && nbr == 0)
		return (write(1, "(nil)", 5));
	if (specifier == 'p')
	{
		ft_putstr("0x");
		return (num_unsigned(nbr, base, upperbase, 'x') + 2);
	}
	else if (nbr < base)
		return (ft_putchar(bases[nbr]));
	else
	{
		count = num_unsigned(nbr / base, base, upperbase, specifier);
		return (count + num_unsigned(nbr % base, base, upperbase, specifier));
	}
}
