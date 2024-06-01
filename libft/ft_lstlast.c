/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:07:07 by karocha-          #+#    #+#             */
/*   Updated: 2024/05/17 17:22:45 by karocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

/*int	main(void)
{
	t_list node1;
	t_list node2;
	t_list node3;
	int val1 = 10;
	int val2 = 12;
	int val3 = 20;
	node1.content = &val1;
	node2.content = &val2;
	node3.content = &val3;

	t_list *lst;
	lst = &node1;
	node1.next = &node2;
	node2.next = &node3;
	node3.next = NULL;
	t_list *last = ft_lstlast(lst);

	printf("%d", *(int *)(last->content));
}*/