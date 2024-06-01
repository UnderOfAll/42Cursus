/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:14:10 by karocha-          #+#    #+#             */
/*   Updated: 2024/06/01 18:23:35 by karocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/*static void ft_tupper(void *s)
{
	char	*string;

	string = s;
	int i =-1;
	while(string[++i])
		string[i] -= 32;
}
int	main(void)
{
	t_list *jorge = ft_lstnew(ft_strdup("jorge"));
	t_list *jesus = ft_lstnew(ft_strdup("jesus"));

	printf("normal jorge: %s\n", (char *)jorge->content);
	printf("normal jesus: %s\n", (char *)jesus->content);
	ft_lstiter(jorge, ft_tupper);
	ft_lstiter(jesus, ft_tupper);
	printf("grande jorge: %s\n", (char *)jorge->content);
	printf("grande jesus: %s\n", (char *)jesus->content);
}*/