/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:30:45 by karocha-          #+#    #+#             */
/*   Updated: 2024/12/08 18:24:48 by karocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	pa(t_list **a, t_list **b)
{
	push(a, b);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_list **a, t_list **b)
{
	push(b, a);
	ft_putstr_fd("pb\n", 1);
}
void	push(t_list **dst, t_list **src)
{
	t_list	*swp;

	if (!(*src))
		return ;
	swp = *src;
	*src = (*src)->next;
	swp->next = *dst;
	*dst = swp;
}
