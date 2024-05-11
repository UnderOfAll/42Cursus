/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 17:32:33 by karocha-          #+#    #+#             */
/*   Updated: 2024/05/11 17:28:58 by karocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*string;
	size_t	i;

	if (!s)
		return (NULL);
	string = (char *)s;
	i = -1;
	string = malloc(sizeof(char) * ft_strlen(string));
	if (!string)
		return (NULL);
	while (s[++i])
		string[i] = f(i, s[i]);
	string[i] = '\0';
	return (string);
}

/*static char	f_tolower(unsigned int i, char a)
{
	i = 32;
	if (a > 64 && a < 91)
		a += i;
	return (a);
}

int	main(void)
{
	char *s = "JORGE";
	char *buffer = ft_strmapi(s, f_tolower);
		printf("%s", buffer);
		free (buffer);
}*/