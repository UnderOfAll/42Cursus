/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:25:46 by karocha-          #+#    #+#             */
/*   Updated: 2024/09/07 12:17:09 by karocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*str;
	int			err;

	str = NULL;
	err = 0;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	if (!buffer[0])
		err = read(fd, buffer, BUFFER_SIZE);
	while (err >= 0 && buffer[0])
	{
		str = strjoin2(str, buffer);
		if (!str)
			return (NULL);
		if (zero_swap(buffer) == 1)
			break ;
		if (!buffer[0])
			err = read(fd, buffer, BUFFER_SIZE);
	}
	return (str);
}
int	main(void)
{
	int maome = open("test1.txt", O_RDWR);
	int	i;
	char *jorge;

	i = 1;
	while (NULL != (jorge = get_next_line(maome)))
	{
		printf("linha %i: %s", i, jorge);
		free(jorge);
		i++;
	}

	close(maome);
}