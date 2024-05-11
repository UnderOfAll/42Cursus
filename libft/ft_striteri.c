/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 17:04:16 by karocha-          #+#    #+#             */
/*   Updated: 2024/05/11 19:59:19 by karocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = -1;
	while (s[++i])
		f(i, &s[i]);
}

/*static void	f_tolower(unsigned int i, char *a)
{
	(void)i;
	if (*a > 64 && *a < 91)
		*a += 32;
}

int	main(void)
{
	char s[] = "JORGE";
	ft_striteri(s, f_tolower);
	printf("%s", s);
}*/