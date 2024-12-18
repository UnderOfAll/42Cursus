/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:30:59 by karocha-          #+#    #+#             */
/*   Updated: 2024/12/18 18:12:13 by karocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ra(t_list **a)
{
	rotate(a);
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_list **b)
{
	rotate(b);
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_list **a, t_list **b)
{
	rotate(a);
	rotate(b);
	ft_putstr_fd("rr\n", 1);
}

void	rotate(t_list **lst)
{
	t_list	*swp;
	t_list	*last;

	if (!(*lst) || !(*lst)->next)
		return ;
	swp = *lst;
	*lst = swp->next;
	last = ft_lstlast(*lst);
	last->next = swp;
	swp->next = NULL;
}
