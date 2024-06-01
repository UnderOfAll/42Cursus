/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 14:57:41 by karocha-          #+#    #+#             */
/*   Updated: 2024/05/31 20:11:42 by karocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	sizedest;

	sizedest = ft_strlen(dest);
	i = -1;
	if (size == 0 || size < sizedest)
		return (ft_strlen(src) + size);
	while (src[++i] && i + sizedest < size - 1)
		dest[i + sizedest] = src[i];
	dest[i + sizedest] = '\0';
	return (ft_strlen(src) + sizedest);
}

/*int main()
{
	const char	src[] = "jorge jesus";
	char		dest[10];
	char		c;

	printf("%s\n", dest);
	printf("source: %s\n", src);
	printf("%zu\n", ft_strlcat(dest, src, 12));
	printf("dest: %s\n", dest);
}*/