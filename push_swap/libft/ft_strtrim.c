/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 15:02:13 by karocha-          #+#    #+#             */
/*   Updated: 2024/05/31 17:44:20 by karocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	check(char strpos, char const *set)
{
	size_t	i;

	i = -1;
	while (set[++i])
	{
		if (strpos == set[i])
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	init;
	size_t	end;
	char	*string;

	if (!s1)
		return (NULL);
	i = 0;
	init = 0;
	end = ft_strlen(s1);
	while (s1[init] && check(s1[init], set))
		init++;
	while (end > init && check(s1[end - 1], set))
		end--;
	string = (char *)malloc(sizeof(char) * (end - init + 1));
	if (!string)
		return (NULL);
	while (init < end)
		string[i++] = s1[init++];
	string[i] = '\0';
	return (string);
}

/*int main()
{
	char const *s1 = "jorge or gabigol";
	char const *set = "jorgol";
	char *result = ft_strtrim(s1, set);
	printf("%s", result);
	free(result);
}*/