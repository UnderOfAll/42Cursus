/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:02:45 by karocha-          #+#    #+#             */
/*   Updated: 2025/01/15 23:11:52 by karocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	if (game->map)
	{
		while(i < game->map_y)
			free(game->map[i++]);
		free(game->map);
	}
	free(game);
}

void	error_message(t_game *game, char *str)
{
	if (str && str[0] != '\0')
		ft_putstr_fd(str, 2);
	if (!game)
		exit(0);
	free_map(game);
	exit(1);
}

void	free_arr_str(char **str)
{
	int	i;

	i = -1;
	if (!str || !str[0])
		return ;
	while (str[++i])
		free(str[i]);
	free(str);
}
