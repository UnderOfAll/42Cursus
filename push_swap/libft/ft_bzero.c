/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 10:20:55 by karocha-          #+#    #+#             */
/*   Updated: 2024/04/28 18:16:33 by karocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ft_bzero(void *s, size_t n)
{
	int			i;
	char		*ptr;

	ptr = s;
	i = 0;
	while (n > 0)
	{
		ptr[i] = '\0';
		i++;
		n--;
	}
}
/*int main()
{
	char buffer[]= "asdas";
	ft_bzero((char *)buffer, 5);
}*/