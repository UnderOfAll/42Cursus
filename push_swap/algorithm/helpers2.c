/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 18:10:09 by karocha-          #+#    #+#             */
/*   Updated: 2024/12/27 18:17:26 by karocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

// this is a complex ft, it does ra or rra depending on whats the
// used needed ft, to calculate what is the best path to rotate
void	best_rot(t_list **stack, int index, void (*up)(t_list **),
		void (*down)(t_list **))
{
	int	lst_size;
	int	back;
	int	front;

	lst_size = ft_lstsize(*stack) + 1;
	back = lst_size - index;
	front = index - 1;
	if (back < front)
	{
		while (back > 0)
		{
			down(stack);
			back--;
		}
	}
	else
	{
		while (front > 0)
		{
			up(stack);
			front--;
		}
	}
}

// this one puts the lowest cost nb in b in the top of a
void	low_on_top(t_list **a, t_list **b)
{
	t_list	*aux;

	aux = *b;
	while (aux)
	{
		if (aux->index == cheapest_cost(b))
		{
			best_rot(a, aux->bst_frn, ra, rra);
			best_rot(b, aux->index, rb, rrb);
			pa(a, b);
			break ;
		}
		aux = aux->next;
	}
}

//this is where it ends, after we put everything organized in stack a
//we most probably wont have it in ascending order as its supposed, so
//we just do what we have done before, find the smallest number and rotate
//it to top
void	last_organize(t_list **a)
{
	t_list	*aux;
	int		smallest_nb;
	int		smallest_index;

	smallest_nb = INT_MAX;
	index_mod(a);
	aux = *a;
	while (aux)
	{
		if (aux->nbr < smallest_nb)
		{
			smallest_nb = aux->nbr;
			smallest_index = aux->index;
		}
		aux = aux->next;
	}
	best_rot(a, smallest_index, ra, rra);
}
