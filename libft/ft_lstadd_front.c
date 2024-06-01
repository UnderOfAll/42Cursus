/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:19:18 by karocha-          #+#    #+#             */
/*   Updated: 2024/05/31 19:47:27 by karocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

/*int main()
{
	int i = -10;
	char *buffer;
	t_list *tmp;
	t_list *lst;

	while(i < 11)
	{
		buffer = ft_itoa(i);
        printf("buffer: %s (%i)\n", buffer, i);
		tmp = ft_lstnew(buffer);
		ft_lstadd_front(&lst, tmp);
		i++;
	}
	while (lst->next != NULL)
	{
		printf("%s ", (char *)lst->content);
		lst = lst->next;
	}
}*/