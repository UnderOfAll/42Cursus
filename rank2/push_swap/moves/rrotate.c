/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:31:06 by karocha-          #+#    #+#             */
/*   Updated: 2024/11/25 23:40:26 by karocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	rra(t_list **a)
{
	rrotate(a);
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_list **b)
{
	rrotate(b);
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_list **a, t_list **b)
{
	rrotate(a);
	rrotate(b);
	ft_putstr_fd("rrr\n", 1);
}

void	rrotate(t_list **lst)
{
	t_list	*last;
	t_list	*swp;

	if (!(*lst) || !(*lst)->next)
		return ;
	last = ft_lstlast(*lst);
	last->next = *lst;
	swp = *lst;
	while (swp->next != last)
		swp = swp->next;
	swp->next = NULL;
	*lst = last;
}
