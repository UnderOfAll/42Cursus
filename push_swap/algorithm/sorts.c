/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:39:04 by karocha-          #+#    #+#             */
/*   Updated: 2024/12/19 20:07:20 by karocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	sort2(t_list **a)
{
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a);
}

void	sort3(t_list **a)
{
	if ((*a)->nbr > (*a)->next->nbr && (*a)->nbr > (*a)->next->next->nbr)
		ra(a);
	if ((*a)->next->nbr > (*a)->next->next->nbr)
		rra(a);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a);
}

void	sort4(t_list **a, t_list **b)
{
	if ((*a)->next->nbr == smallest(*a))
		ra(a);
	else if ((*a)->next->next->nbr == smallest(*a))
	{
		rra(a);
		rra(a);
	}
	else if ((*a)->next->next->next->nbr == smallest(*a))
		rra(a);
	pb(a, b);
	sort3(a);
	pa(a, b);
}

void	sort5(t_list **a, t_list **b)
{
	if (!a || !(*a) || !b)
		return ;
	if ((*a)->next->nbr == smallest(*a))
		ra(a);
	else if ((*a)->next->next->nbr == smallest(*a))
	{
		ra(a);
		ra(a);
	}
	else if ((*a)->next->next->next->nbr == smallest(*a))
	{
		rra(a);
		rra(a);
	}
	else if ((*a)->next->next->next->next->nbr == smallest(*a))
		rra(a);
	pb(a, b);
	sort4(a, b);
	pa(a, b);
}
