/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 20:11:24 by karocha-          #+#    #+#             */
/*   Updated: 2024/05/15 16:18:26 by karocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int contador;

	contador = 1;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	while (contador <= n / 10)
		contador *= 10;
	while (contador > 0)
	{
		ft_putchar_fd(n / contador + '0', fd);
		n %= contador;
		contador /= 10;
	}
}

/*int main()
{
	ft_putnbr_fd(-2147483648, 0);
}*/