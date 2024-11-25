/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:51:06 by karocha-          #+#    #+#             */
/*   Updated: 2024/05/28 19:51:49 by karocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!lst || !del)
		return ;
	while ((*lst) != NULL)
	{
		tmp = (*lst)->next;
		ft_lstdelone((*lst), del);
		(*lst) = tmp;
	}
	(*lst) = NULL;
}

/*void	del(void *content)
{
	free(content);
}

int	main(void)
{
	t_list *jorge = ft_lstnew(ft_strdup("jorge"));
	t_list *jesus = ft_lstnew(ft_strdup("jesus"));
	t_list *tmp = jorge;

	ft_lstadd_back(&jorge, jesus);
	while (tmp != NULL)
	{
		printf("string:%s\n", (char *)tmp->content);
		tmp = tmp->next;
	}
	ft_lstclear(&jorge, del);
	if (jorge == NULL)
		printf("list cleared.");
}*/