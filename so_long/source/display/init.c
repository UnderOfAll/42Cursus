/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 00:02:23 by karocha-          #+#    #+#             */
/*   Updated: 2025/01/16 00:07:27 by karocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	game_start(t_game *game)
{
	game->mlx = mlx_init;
	if (game->mlx == NULL)
		error_message(game, "Mlx failed.\n");
	
	game->mlx_win = mlx_new_window(game->mlx, 1280, 720, "so_long");
}
