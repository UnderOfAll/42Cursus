/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:24:21 by karocha-          #+#    #+#             */
/*   Updated: 2024/05/20 19:09:16 by karocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = ft_lstlast(*lst);
	tmp->next = new;
}

/*int	main(void)
{
	t_list *jorge;
	t_list *jesus;
	t_list *romario;
	t_list *jose;

	jorge = ft_lstnew("jorge");
	jesus = ft_lstnew("jesus");
	romario = ft_lstnew("romario");
	jose = ft_lstnew("jose");

	ft_lstadd_back(&jorge, jesus);
	ft_lstadd_back(&jorge, romario);
	ft_lstadd_back(&jorge, jose);

	while (jorge != NULL)
	{
		printf("%s\n", (char *)jorge->content);
		jorge = jorge->next;
	}
}*/
