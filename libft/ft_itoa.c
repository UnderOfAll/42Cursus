/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:34:15 by karocha-          #+#    #+#             */
/*   Updated: 2024/05/30 17:09:38 by karocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

char	*ft_itoa(int n)
{
	char	string[12];
	long	nb;
	int		len;

	nb = n;
	len = 11;
	string[len] = '\0';
	if (nb == 0)
		return (ft_strdup("0"));
	if (nb < 0)
		nb = -nb;
	while (nb > 0)
	{
		string[--len] = (nb % 10 + '0');
		nb /= 10;
	}
	if (n < 0)
		string[--len] = '-';
	return (ft_strdup(&string[len]));
}

/* int main()
{
	char *jorge = ft_itoa(-2147483648);
	printf("%s\n", jorge);
	free (jorge);
} */