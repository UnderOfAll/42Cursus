/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:33:55 by karocha-          #+#    #+#             */
/*   Updated: 2025/04/21 18:22:40 by karocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = -1;
	while (s[++i])
		write(fd, &s[i], 1);
}
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*arr;
	size_t	i;
	size_t	len;	

	if (nmemb == 0 || size == 0)
		return (malloc(1));
	if (nmemb > SIZE_MAX / size)
		return (NULL);
	len = nmemb * size;
	arr = malloc(len);
	if (!arr)
		return (NULL);
	i = -1;
	while (++i < len)
		((unsigned char *)arr)[i] = '\0';
	return (arr);
}
