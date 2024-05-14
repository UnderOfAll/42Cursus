/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 10:35:15 by karocha-          #+#    #+#             */
/*   Updated: 2024/04/28 18:18:07 by karocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*source;
	char	*dst;

	source = (char *)src;
	dst = (char *)dest;
	i = 0;
	while (i < n)
	{
		dst[i] = source[i];
		i++;
	}
	return (dest);
}

/*int main()
{
	char buffer[] = "dasad";
	char receive[6];
	ft_memcpy(receive, buffer, 120);
	receive[5] = '\0';
	printf("%s", receive);
}*/