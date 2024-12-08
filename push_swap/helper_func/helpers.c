/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:56:00 by karocha-          #+#    #+#             */
/*   Updated: 2024/12/06 11:56:12 by karocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	smallest(t_list *a)
{
	long	i;

	if (!(a))
		return (0);
	i = LONG_MAX;
	while ((a)->next)
	{
		if (i > (a)->nbr)
			i = (a)->nbr;
		a = (a)->next;
	}
	return (i);
}
int	nb_avg(t_list **a)
{
	long	i;
	long	base;
	long	counter;
	t_list	*aux;

	aux = *a;
	base = 0;
	counter = 0;
	while (aux)
	{
		base += aux->nbr;
		counter++;
		aux = aux->next;
	}
	i = (long)(base / counter);
	return (i);
}

void	index_mod(t_list **lst)
{
	t_list	*aux;
	int		i;

	aux = *lst;
	i = 1;
	while (aux)
	{
		aux->index = i;
		i++;
		aux = aux->next;
	}
}

// this function calculates the cost for the best move of each bff, doing it
// upwards or downwards
void	cost_mod(t_list *a, t_list *b)
{
	int	moves_a;
	int	moves_b;
	int	size_a;
	int	size_b;

	size_a = ft_lstsize2(a);
	size_b = ft_lstsize2(b);
	while (b)
	{
		if ((size_a - b->bst_frn) < (b->bst_frn - 1))
			moves_a = size_a - b->bst_frn;
		else
			moves_a = b->bst_frn - 1;
		if ((size_b - b->bst_frn) < (b->bst_frn - 1))
			moves_b = size_b - b->bst_frn;
		else
			moves_b = b->bst_frn - 1;
		b->cost = moves_a + moves_b;
		b = b->next;
	}
}
// this function finds the cheapest cost element in the stack
int	cheapest_cost(t_list **a)
{
	t_list	*aux;
	int		small_cost;
	int		index;

	small_cost = INT_MAX;
	index = 0;
	aux = *a;
	while (aux)
	{
		if (aux->cost < small_cost)
		{
			small_cost = aux->cost;
			index = aux->index;
		}
		aux = aux->next;
	}
	return (index);
}
