/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 00:02:23 by karocha-          #+#    #+#             */
/*   Updated: 2025/01/17 20:16:36 by karocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static	void	load_images(t_game *game)
{
	game->player = mlx_xpm_file_to_image(game->mlx, "images/player.xpm", 
			&game->player_image_x, &game->player_image_y);
	game->bakg = mlx_xpm_file_to_image(game->mlx, "images/bakg.xpm", 
			&game->bakg_x, &game->bakg_y);
	game->wall = mlx_xpm_file_to_image(game->mlx, "images/wall.xpm", 
			&game->wall_x, &game->wall_y);
	game->collectable = mlx_xpm_file_to_image(game->mlx,
	 		"images/collectable.xpm", &game->collectable_x, 
			&game->collectable_y);
	game->exit_open = mlx_xpm_file_to_image(game->mlx, "images/exit_open.xpm", 
			&game->exit_open_x, &game->exit_open_y);
	game->exit_closed = mlx_xpm_file_to_image(game->mlx, 
			"images/exit_closed.xpm", &game->exit_closed_x, 
			&game->exit_closed_y);
	if (game->player == NULL || game->bakg == NULL || game->wall == NULL 
			|| game->collectable == NULL || game->exit_open == NULL 
			|| game->exit_closed == NULL)
			error_message(game, "Failed to load images.\n");
}

void	game_start(t_game *game)
{
	game->mlx = mlx_init();

	if (game->mlx == NULL)
		error_message(game, "Mlx failed.\n");
	mlx_get_screen_size(game->mlx, &game->screen_x, &game->screen_y);
	if (((game->map_x * TILE_SIZE) + 16) > game->screen_y 
		|| ((game->map_y * TILE_SIZE) + 16) > game->screen_x)
		error_message(game, "Window can't be larger then the screen.\n");
	game->mlx_win = mlx_new_window(game->mlx, game->map_x * TILE_SIZE,
					game->map_y * TILE_SIZE, "so_long");
	if (game->mlx_win == NULL)
		error_message(game, "Impossible to create a window.\n");
	load_images(game);
}
