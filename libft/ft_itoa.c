/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:34:15 by karocha-          #+#    #+#             */
/*   Updated: 2024/05/10 17:32:22 by karocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr(long nb, char *str, int len)
{
	int	contador;

	contador = 1;
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (contador <= nb / 10)
	{
		contador *= 10;
	}
	while (contador > 0)
	{
		str[len] = (nb / contador + '0');
		nb %= contador;
		contador /= 10;
		len++;
	}
}

char	*ft_itoa(int n)
{
	char string[15];
	int len;

	len = ft_strlen(string);
	string[len] = '\0';
	len = 1;
	if (n == 0)
		return ("0\0");
	ft_putnbr(n, string, len);
	return (ft_strdup(string));
}

/*int main()
{
	char *penis = ft_itoa(-2147483648);
	printf("%s", penis);
	free (penis);
}*/