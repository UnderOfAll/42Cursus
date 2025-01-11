/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:02:45 by karocha-          #+#    #+#             */
/*   Updated: 2025/01/11 18:06:48 by karocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_memory(t_game *game)
{
	int	i;

	i = 0;
	if (game->map)
	{
		while(i < game->map_y)
			free(game->map[i]);
		free(game->map);
	}
}
