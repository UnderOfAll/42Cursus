/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:30:53 by karocha-          #+#    #+#             */
/*   Updated: 2024/11/25 23:42:49 by karocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	sa(t_list **a)
{
	swap(a);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_list **b)
{
	swap(b);
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_list **a, t_list **b)
{
	swap(a);
	swap(b);
	ft_putstr_fd("ss\n", 1);
}

void	swap(t_list **lst)
{
	t_list	*head;
	t_list	*third;

	if (!(*lst) || !(*lst)->next)
		return ;
	head = *lst;
	third = (*lst)->next->next;
	*lst = (*lst)->next;
	(*lst)->next = head;
	(*lst)->next->next = third;
}
