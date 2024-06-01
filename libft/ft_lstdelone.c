/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 19:09:33 by karocha-          #+#    #+#             */
/*   Updated: 2024/06/01 18:23:33 by karocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

/*void del(void *content)
{
	free(content);
}

int	main(void)
{
	t_list *jorge = ft_lstnew(ft_strdup("jorge"));
	t_list *jesus = ft_lstnew(ft_strdup("jesus"));
	t_list  *tmp;

	ft_lstadd_back(&jorge, jesus);
	tmp = jorge;
	while (tmp != NULL)
	{
		printf("string:%s\n", (char *)tmp->content);
		tmp = tmp->next;
	}
	ft_lstdelone(jesus, del);
	tmp = jorge;
	while (tmp != NULL)
	{
		printf("string after del:%s\n", (char *)tmp->content);
		tmp = tmp->next;
	}
	tmp = jorge;
	while (tmp != NULL)
	{
		t_list *next = tmp->next;
		ft_lstdelone(tmp, del);
		tmp = next;
	}
}*/