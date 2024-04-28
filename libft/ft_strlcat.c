/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 14:57:41 by karocha-          #+#    #+#             */
/*   Updated: 2024/04/28 19:36:32 by karocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	idest;

	idest = ft_strlen(dest);
	i = -1;
	if (size == 0 || size < idest)
		return (ft_strlen(src) + size);
	while (src[++i] && i < size - idest - 1)
		dest[i + idest] = src[i];
	dest[i + idest] = '\0';
	return (ft_strlen(src) + idest);
}

void	ft_print_result(int n)
{
	char c;

	if (n >= 10)
		ft_print_result(n / 10);
	c = n % 10 + '0';
	write (1, &c, 1);
}

int		main(int argc, const char *argv[])
{
	char	*dest;
	int		arg;

	alarm(5);
	if (!(dest = (char *)malloc(sizeof(*dest) * 15)) || argc == 1)
		return (0);
	memset(dest, 0, 15);
	memset(dest, 'r', 6);
	if ((arg = atoi(argv[1])) == 1)
	{
		dest[11] = 'a';
		ft_print_result(ft_strlcat(dest, "lorem", 15));
		write(1, "\n", 1);
		write(1, dest, 15);
	}
	else if (arg == 2)
	{
		ft_print_result(ft_strlcat(dest, "", 15));
		write(1, "\n", 1);
		write(1, dest, 15);
	}
	else if (arg == 3)
	{
		dest[0] = '\0';
		dest[11] = 'a';
		ft_print_result(ft_strlcat(dest, "lorem ipsum", 15));
		write(1, "\n", 1);
		write(1, dest, 15);
	}
	else if (arg == 4)
	{
		dest[14] = 'a';
		ft_print_result(ft_strlcat(dest, "lorem ipsum dolor sit amet", 15));
		write(1, "\n", 1);
		write(1, dest, 15);
	}
	else if (arg == 5)
	{
		dest[10] = 'a';
		ft_print_result(ft_strlcat(dest, "lorem ipsum dolor sit amet", 0));
		write(1, "\n", 1);
		write(1, dest, 15);
	}
	else if (arg == 6)
	{
		dest[10] = 'a';
		ft_print_result(ft_strlcat(dest, "lorem ipsum dolor sit amet", 1));
		write(1, "\n", 1);
		write(1, dest, 15);
	}
	else if (arg == 7)
	{
		memset(dest, 'r', 15);
		ft_print_result(ft_strlcat(dest, "lorem ipsum dolor sit amet", 5));
		write(1, "\n", 1);
		write(1, dest, 15);
	}
	else if (arg == 8)
	{
		dest[10] = 'a';
		ft_print_result(ft_strlcat(dest, "lorem ipsum dolor sit amet", 6));
		write(1, "\n", 1);
		write(1, dest, 15);
	}
	else if (arg == 9)
	{
		memset(dest, 'r', 14);
		ft_print_result(ft_strlcat(dest, "lorem ipsum dolor sit amet", 15));
		write(1, "\n", 1);
		write(1, dest, 15);
	}
	return (0);
}