/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:25:44 by karocha-          #+#    #+#             */
/*   Updated: 2024/09/07 12:20:36 by karocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

char	*strjoin2(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*string;

	if (!s1 && !s2)
		return (NULL);
	i = 0;
	j = 0;
	string = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!string)
		return (NULL);
	if (s1)
	{
		while (s1[i])
			string[j++] = s1[i++];
		free(s1);
	}
	i = 0;
	while (s2[i] && s2[i] != '\n')
		string[j++] = s2[i++];
	if (s2[i] == '\n')
		string[j++] = '\n';
	string[j] = '\0';
	return (string);
}

int	zero_swap(char *buffer)
{
	int	id_nl;
	int	oldl_id;
	int	nl_sign;

	id_nl = 0;
	oldl_id = 0;
	nl_sign = 0;
	while (buffer[oldl_id])
	{
		if (nl_sign == 1)
			buffer[id_nl++] = buffer[oldl_id];
		if (buffer[oldl_id] == '\n')
			nl_sign = 1;
		buffer[oldl_id++] = '\0';
	}
	return (nl_sign);
}
