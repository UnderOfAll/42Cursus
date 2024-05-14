/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 15:57:11 by karocha-          #+#    #+#             */
/*   Updated: 2024/05/10 16:15:49 by karocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	counter(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	verify;

	i = 0;
	j = -1;
	while (s[++j])
	{
		verify = 0;
		while (s[j] && s[j] == c)
			j++;
		while (s[j] && s[j] != c)
		{
			if (verify == 0)
			{
				verify = 1;
				i++;
			}
			j++;
		}
	}
	return (i);
}

static int	mallocer(char **split, int position, size_t lenght)
{
	int	i;

	i = -1;
	split[position] = malloc(lenght);
	if (!split[position])
	{
		while (++i < position)
			free(split[position]);
		free(split);
		return (1);
	}
	return (0);
}

static int	filler(char const *s, char c, char **split)
{
	size_t	lenght;
	size_t	i;
	size_t	position;

	i = 0;
	position = 0;
	while (s[i])
	{
		lenght = 0;
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			lenght++;
			i++;
		}
		if (lenght > 0)
		{
			if (mallocer(split, position, lenght) > 0)
				return (1);
		}
		ft_strlcpy(split[position], s + i - lenght, lenght + 1);
		position++;
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	strings;

	if (!s)
		return (NULL);
	strings = counter(s, c);
	split = malloc(sizeof(char *) * (strings + 1));
	if (!split)
		return (NULL);
	if (filler(s, c, split) > 0)
	{
		free(split);
		return (NULL);
	}
	split[strings] = NULL;
	return (split);
}

/*int main()
{
	char *s = "    Salve quebrada, tamo junto";
	char **v = ft_split(s, ' ');
	int i = 0;
	if (v)
	{
		while (v[i])
		{
			printf("%s\n", v[i]);
			free(v[i]);
			i++;
		}
		free (v);
	}
	return (0);
}*/