/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 19:55:32 by karocha-          #+#    #+#             */
/*   Updated: 2024/12/19 18:41:43 by karocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <fcntl.h>
# include <limits.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_list
{
	int 			nbr;
	int 			index;
	int 			cost;
	int 			bst_frn;
	struct s_list	*next;
} t_list;

// moves
void	push(t_list **dst, t_list **src);
void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);

void	rotate(t_list **lst);
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);

void	rrotate(t_list **lst);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);

void	swap(t_list **lst);
void	sa(t_list **a);
void	sb(t_list **b);
void	ss(t_list **a, t_list **b);

// parser
int		parser(int ac, char **av);
int		duplicates(int ac, char **av);
int		limit(char **av);
int		numcheck(char **av);

// helper_functions
int		smallest(t_list *a);
int		nb_avg(t_list **a);
void	index_mod(t_list **lst);
void	cost_mod(t_list *a, t_list *b);
int		cheapest_cost(t_list **a);
void	best_rot(t_list **stack, int index, void (*up)(t_list **),
		void (*down)(t_list **));
void	low_on_top(t_list **a, t_list **b);
void	last_organize(t_list **a);

// libft
long	ft_atol(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(long content);
int		ft_lstsize(t_list *lst);
void	ft_putstr_fd(char *s, int fd);

// Algorithm
int	check_sorted(t_list **a);

void	sort2(t_list **a);
void	sort3(t_list **a);
void	sort4(t_list **a, t_list **b);
void	sort5(t_list **a, t_list **b);

void	algorithm(t_list **a, t_list **b);
void	best_friend(t_list **a, t_list **b);

#endif