/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 19:35:01 by karocha-          #+#    #+#             */
/*   Updated: 2024/12/27 18:16:35 by karocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	algorithm(t_list **a, t_list **b)
{
	while (ft_lstsize(*a) > 5)
	{
		if ((*a)->nbr < nb_avg(a))
			pb(a, b);
		else
			ra(a);
	}
	sort5(a, b);
	while (*b)
	{
		index_mod(b);
		index_mod(a);
		best_friend(a, b);
		cost_mod(*a, *b);
		low_on_top(a, b);
	}
	last_organize(a);
}

// this is the core function, it calculates the bff by calculating the smallest
// difference in the current nbr of each stack, and returns it bff
void	best_friend(t_list **a, t_list **b)
{
	t_list		*aux_a;
	t_list		*aux_b;
	long int	i;
	long int	j;

	aux_b = *b;
	while (aux_b)
	{
		aux_a = *a;
		i = 0;
		j = LLONG_MAX;
		while (aux_a)
		{
			i = (long long)aux_a->nbr - (long long)(aux_b)->nbr;
			if (i > 0 && i < j)
			{
				(aux_b)->bst_frn = aux_a->index;
				j = i;
			}
			aux_a = aux_a->next;
		}
		aux_b = aux_b->next;
	}
}
