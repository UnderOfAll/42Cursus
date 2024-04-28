/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 17:15:53 by karocha-          #+#    #+#             */
/*   Updated: 2024/04/27 19:39:23 by karocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	size_t	*arr;

	i = 0;
	arr = malloc(nmemb * size);
	if (!arr)
		return (NULL);
	ft_bzero(arr, nmemb * size);
	return (arr);
}

/*int main()
{
	size_t nmemb = 5;
	size_t size = sizeof(int);
	int *arr = ft_calloc(nmemb, size);
		if (!arr)
				return (0);
	size_t i = 0;
	while(i < nmemb)
	{
		printf("%d", arr[i]);
		i++;
	}
		free(arr);
		return (0);
}*/