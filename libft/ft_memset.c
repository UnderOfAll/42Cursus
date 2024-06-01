/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:41:31 by karocha-          #+#    #+#             */
/*   Updated: 2024/05/31 18:32:02 by karocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = str;
	i = -1;
	while (++i < n)
		ptr[i] = (unsigned char)c;
	return (ptr);
}

/*int main()
{
	char buffer[] = "Kickoff #7";
	printf("%s", (char *)ft_memset(buffer, '$', 10));
}*/
