/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 20:32:26 by karocha-          #+#    #+#             */
/*   Updated: 2024/06/01 18:23:44 by karocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*new_node;

	if (!lst)
		return (NULL);
	head = NULL;
	while (lst)
	{
		if (f)
			new_node = ft_lstnew(f(lst->content));
		else
			new_node = ft_lstnew(lst->content);
		if (!new_node)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		ft_lstadd_back(&head, new_node);
		lst = lst->next;
	}
	return (head);
}
/*void	del(void *content)
{
	free(content);
}

static void	*f(void *s)
{
	char	*string;
	int		i;

	string = ft_strdup(s);
	i = 0;
	while (string[i])
	{
		string[i] -= 32;
		i++;
	}
	return (string);
}

void	lst_printer(char *a)
{
	printf("%s\n", a);
}

int	main(void)
{
	t_list *jorge = ft_lstnew(ft_strdup("jorge"));
	t_list *jesus = ft_lstnew(ft_strdup("jesus"));
	t_list *romario = ft_lstnew(ft_strdup("romario"));
	t_list *jose = ft_lstnew(ft_strdup("jose"));
	t_list *new;

	ft_lstadd_back(&jorge, jesus);
	ft_lstadd_back(&jorge, romario);
	ft_lstadd_back(&jorge, jose);
	new = ft_lstmap(jorge, f, del);
	ft_lstiter(jorge, (void *)lst_printer);
	ft_lstclear(&jorge, del);
	ft_lstiter(new, (void *)lst_printer);
	ft_lstclear(&new, del);
	return (0);
}*/