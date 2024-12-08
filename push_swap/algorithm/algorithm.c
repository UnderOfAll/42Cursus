/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 19:35:01 by karocha-          #+#    #+#             */
/*   Updated: 2024/12/08 23:16:58 by karocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

// this is the core function, it calculates the bff by calculating the smallest
// difference in the current nbr of each stack, and returns it bff
void	best_friend(t_list **a, t_list **b)
{
	t_list	*aux_a;
	t_list	*aux_b;
	long	curr_nb;
	long	small_nb;

	aux_b = *b;
	while (aux_b)
	{
		aux_a = *a;
		curr_nb = 0;
		small_nb = LLONG_MAX;
		while (aux_a)
		{
			curr_nb = (long long)aux_a->nbr - (long long)aux_b->nbr;
			if (curr_nb > 0 && curr_nb < small_nb)
			{
				aux_b->bst_frn = aux_a->index;
				small_nb = curr_nb;
			}
			aux_a = aux_a->next;
		}
		aux_b = aux_b->next;
	}
}

void	algorithm(t_list **a, t_list **b)
{
	if (!a || !(*a) || !b)
		return ;
	while (ft_lstsize(a) > 5)
	{
		if ((*a) && (*a)->nbr < nb_avg(a))
			pb(a, b);
		else
			ra(a);
	}
	sort5(a, b);
	while (*b)
	{
		index_mod(a);
		index_mod(b);
		best_friend(a, b);
		cost_mod(*a, *b);
		low_on_top(a, b);
	}
	last_organize(a);
}
