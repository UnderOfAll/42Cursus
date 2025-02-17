/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:18:05 by karocha-          #+#    #+#             */
/*   Updated: 2024/12/19 20:03:07 by karocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	check_sorted(t_list **a)
{
	t_list	*aux;
	int		i;

	i = 1;
	aux = *a;
	while (aux->next)
	{
		if (aux->nbr > aux->next->nbr)
			i = 0;
		aux = aux->next;
	}
	return (i);
}

void	make_lst(t_list **a, int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		ft_lstadd_back(a, ft_lstnew(ft_atol(av[i])));
		i++;
	}
}

void	free_lst(t_list **lst)
{
	t_list	*new_node;

	if (!lst || !*lst)
		return ;
	while ((*lst != NULL))
	{
		new_node = (*lst)->next;
		free(*lst);
		*lst = new_node;
	}
}

void	sort_starter(int ac, t_list **a, t_list **b)
{
	if (ac == 3)
		sort2(a);
	else if (ac == 4)
		sort3(a);
	else if (ac == 5)
		sort4(a, b);
	else if (ac == 6)
		sort5(a, b);
	else
		algorithm(a, b);
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (ac < 2)
		return (0);
	if (parser(ac, av))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	make_lst(&a, ac, av);
	if (check_sorted(&a))
	{
		free_lst(&a);
		return (0);
	}
	sort_starter(ac, &a, &b);
	free_lst(&a);
	free_lst(&b);
	return (0);
}
