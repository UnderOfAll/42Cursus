/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:52:56 by karocha-          #+#    #+#             */
/*   Updated: 2024/05/31 18:14:38 by karocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*jorge;
	size_t	i;

	i = -1;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	jorge = malloc(sizeof(char) * (len + 1));
	if (!jorge)
		return (NULL);
	while (s[start + ++i] && i < len)
		jorge[i] = s[start + i];
	jorge[i] = '\0';
	return (jorge);
}

/*int main()
{
	char const *s = "jorge";
	printf("%s", ft_substr(s, 0, 10));
    free (s);
}*/