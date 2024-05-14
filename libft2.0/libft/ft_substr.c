/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:52:56 by karocha-          #+#    #+#             */
/*   Updated: 2024/05/04 13:48:55 by karocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	i = -1;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (NULL);
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	while (s[start + ++i] && i < len)
		substr[i] = s[start + i];
	substr[i] = '\0';
	return (substr);
}

/*int main()
{
	char const *s = "jorge";
	printf("%s", ft_substr(s, 0, 10));
}*/