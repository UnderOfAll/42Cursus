/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 10:25:49 by karocha-          #+#    #+#             */
/*   Updated: 2025/01/18 13:03:28 by karocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static	void	put_bakg(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			mlx_put_image_to_window(game->mlx, game->mlx_win, game->bakg, 
				x * TILE_SIZE, y * TILE_SIZE);
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->wall, 
					x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
}

static	void	put_environment(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->mlx_win, 
					game->collectable, x * TILE_SIZE, y * TILE_SIZE);
			if (game->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->mlx_win, 
					game->exit_closed, x * TILE_SIZE, y * TILE_SIZE);
			if (game->map[y][x] == 'P')
				mlx_put_image_to_window(game->mlx, game->mlx_win, 
					game->player, x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
}

void	put_images(t_game *game)
{
	put_bakg(game);
	put_environment(game);
}
