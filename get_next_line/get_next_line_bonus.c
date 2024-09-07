/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 11:57:28 by karocha-          #+#    #+#             */
/*   Updated: 2024/09/07 12:53:44 by karocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[OPEN_MAX][BUFFER_SIZE];
	char		*str;
	int			err;

	str = NULL;
	err = 0;
	if (BUFFER_SIZE <= 0 || fd < 0 || fd >= OPEN_MAX)
		return (NULL);
	if (!buffer[fd][0])
		err = read(fd, buffer[fd], BUFFER_SIZE);
	while (err >= 0 && buffer[fd][0])
	{
		str = strjoin2(str, buffer[fd]);
		if (!str)
			return (NULL);
		if (zero_swap(buffer[fd]) == 1)
			break ;
		if (!buffer[fd][0])
			err = read(fd, buffer[fd], BUFFER_SIZE);
	}
	return (str);
}

/*int main()
{
	int fds[3];
	char *str;
	int i;

	fds[0] = open("test1.txt", O_RDONLY);
	fds[1] = open("test2.txt", O_RDONLY);
	fds[2] = open("test3.txt", O_RDONLY);
	i = 0;
	while (i < 3)
	{
		printf("Lendo do fd %d:\n", fds[i]);
		while ((str = get_next_line(fds[i])) != NULL)
		{
			printf("%s", str);
			free (str);
		}
		printf ("\n");
		i++;
	}

	close (fds[0]);
	close (fds[1]);
	close (fds[2]);
}*/