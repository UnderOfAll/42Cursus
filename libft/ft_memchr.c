/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 12:21:37 by karocha-          #+#    #+#             */
/*   Updated: 2024/06/01 18:05:31 by karocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str;
	size_t				i;

	str = s;
	i = 0;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}

/*int	main(void)
{
	char buffer[] = "0, 1, 2, 3, 4, 5";
	unsigned char *standard = memchr(buffer, 2 + 256, 10000);
	unsigned char *function = ft_memchr(buffer, 2 + 256, 10000);
	if (function != NULL)
		printf("function: %c\n", *function);
	else
		printf("NO\n");
	if (standard != NULL)
		printf("standard: %c", *standard);
	else
		printf("NO\n");
}*/