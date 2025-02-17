/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:51:09 by karocha-          #+#    #+#             */
/*   Updated: 2024/05/31 19:49:21 by karocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	counter;

	counter = 0;
	while (lst != NULL)
	{
		counter++;
		lst = lst->next;
	}
	return (counter);
}

/*int main()
{
	t_list	node1;
	t_list	node2;
	t_list	node3;
	int	val1 = 1;
	int	val2 = 2;
	int	val3 = 3;
	node1.content = &val1;
	node2.content = &val2;
	node3.content = &val3;

	t_list *lst;
	lst = &node1;
	node1.next = &node2;
	node2.next = &node3;
	node3.next = NULL;

	printf("%d", ft_lstsize(lst));
}*/