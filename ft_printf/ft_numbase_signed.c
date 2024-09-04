/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbase_signed.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:59:37 by karocha-          #+#    #+#             */
/*   Updated: 2024/06/18 17:22:15 by karocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c);

int	number_base_signed(long nbr, int base, int upperbase)
{
	int		count;
	char	*bases;

	if (upperbase)
		bases = "0123456789ABCDEF";
	else
		bases = "0123456789abcdef";
	count = 0;
	if (nbr < 0)
	{
		ft_putchar('-');
		return (number_base_signed(-nbr, base, upperbase) + 1);
	}
	else if (nbr < base)
		return (ft_putchar(bases[nbr]));
	else
	{
		count = number_base_signed(nbr / base, base, upperbase);
		return (count + number_base_signed(nbr % base, base, upperbase));
	}
}
