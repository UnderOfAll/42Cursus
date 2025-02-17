/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 11:11:00 by karocha-          #+#    #+#             */
/*   Updated: 2024/04/28 18:14:09 by karocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

// void	*ft_memmove(void *dest, const void *src, size_t n)
// {
// 	size_t		i;
// 	char		*dst;
// 	const char	*source;
// 	char		tmp[n];

// 	i = 0;
// 	dst = (char *)dest;
// 	source = (const char *)src;
// 	while (source[i] && i < n)
// 	{
// 		tmp[i] = source[i];
// 		i++;
// 	}
// 	tmp[i] = '\0';
// 	i = 0;
// 	while (tmp[i])
// 	{
// 		dst[i] = tmp[i];
// 		i++;
// 	}
// 	return (dest);
// }

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*dst;
	const char	*source;

	dst = (char *)dest;
	source = (const char *)src;
	if (source < dst && dst < source + n)
	{
		i = n;
		while (i > 0)
		{
			dst[i - 1] = source [i - 1];
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			dst[i] = source[i];
			i++;
		}
	}
	return (dest);
}

/*int	main(void)
{
	const char	*string = "Test string";
	const char	*string2 = "Test string";
	char		*src;
	char		*src2;

	src = (char *)malloc(strlen(string) + 10);
	src2 = (char *)malloc(strlen(string2) + 1);
	strcpy(src, string);
	strcpy(src2, string2);
	// char dest[50];
	// char dest2[50];
	memmove(src2 + 3, src2, strlen(src2) + 1);
	printf("original memmove: |%s|\n", src2);
	ft_memmove(src + 3, src, strlen(src) + 1);
	printf("ft_memmove: |%s|\n", src);
	free(src);
	free(src2);
}*/
