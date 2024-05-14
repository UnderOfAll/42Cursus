/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 15:02:13 by karocha-          #+#    #+#             */
/*   Updated: 2024/05/04 16:20:42 by karocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	check(char const *s1, char const *set, size_t pos)
{
	size_t	i;

	i = -1;
	while (set[++i])
	{
		if (s1[pos] == set[i])
			return (0);
	}
	return (1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*string;

	if (!s1)
		return (NULL);
	i = -1;
	j = -1;
	string = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!string)
		return (NULL);
	while (s1[++i])
	{
		if (check(s1, set, i) == 1)
			string[++j] = s1[i];
	}
	string[++j] = '\0';
	return (string);
}

/*int main()
{
	char const *s1 = "jorge";
	char const *set = "o";
	char *result = ft_strtrim(s1, set);
	printf("%s", result);
	free(result);
}*/