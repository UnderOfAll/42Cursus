/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 17:15:53 by karocha-          #+#    #+#             */
/*   Updated: 2024/06/02 19:50:59 by karocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*arr;

	if (nmemb == 0 || size == 0)
		return (malloc(1));
	if (nmemb > SIZE_MAX / size)
		return (NULL);
	arr = malloc(nmemb * size);
	if (!arr)
		return (NULL);
	ft_bzero(arr, nmemb * size);
	return (arr);
}

/*int main()
{
	size_t nmemb = 0;
	size_t size = 0;
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