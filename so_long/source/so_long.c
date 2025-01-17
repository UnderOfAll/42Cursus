/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:06:39 by karocha-          #+#    #+#             */
/*   Updated: 2025/01/17 18:48:37 by karocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static	void	init_images(t_game *game)
{
	game->moves = 1;
	game->bakg_x = TILE_SIZE;
	game->bakg_y = TILE_SIZE;
	game->wall_x = TILE_SIZE;
	game->wall_y = TILE_SIZE;
	game->collectable_x = TILE_SIZE;
	game->collectable_y = TILE_SIZE;
	game->exit_open_x = TILE_SIZE;
	game->exit_open_y = TILE_SIZE;
	game->exit_closed_x = TILE_SIZE;
	game->exit_closed_y = TILE_SIZE;
	game->player_image_x = TILE_SIZE;
	game->player_image_y = TILE_SIZE;
}

int	main(int ac, char **av)
{
	t_game	*game;

	game = NULL;
	if (ac != 2)
		error_message(game, "Invalid number of arguments");
	game = read_map(av[1], game);
	init_images(game);
	game_start(game);
	free_arr_str(game->map);
	free(game);
}

/* int	main(void)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	(void)mlx_win;
	mlx_loop(mlx);
} */
