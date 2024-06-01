/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 13:50:07 by karocha-          #+#    #+#             */
/*   Updated: 2024/05/31 16:46:40 by karocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*string;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	string = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!string)
		return (NULL);
	while (s1[i])
	{
		string[j++] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		string[j] = s2[i];
		i++;
		j++;
	}
	string[j] = '\0';
	return (string);
}

/*void ft_strdel(char *str)
{
	if (str)
		free(str);
}

int	main(void)
{
	char const *s1 = "jorge";
	char const *s2 = " jesus";
	char *result = ft_strjoin(s1, s2);
	printf("%s", result);
	ft_strdel(result);
}*/