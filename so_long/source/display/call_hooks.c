/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 11:49:46 by karocha-          #+#    #+#             */
/*   Updated: 2025/01/18 15:06:10 by karocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static	void	swap_image(t_game *game, int x, int y)
{
	game->map[y][x] = '0';
	game->nb_collectable--;
	if (game->nb_collectable == 0)
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->exit_open, 
				game->exit_x * TILE_SIZE, game->exit_y * TILE_SIZE);
}

static	int	move_allowed(t_game *game, int key)
{
	int	y;
	int	x;

	y = game->player_y;
	x = game->player_x;
	if (key == XK_w || key == XK_Up)
		y--;
	else if (key == XK_s || key == XK_Down)
		y++;
	else if (key == XK_a || key == XK_Left)
		x--;
	else if (key == XK_d || key == XK_Right)
		x++;
	else if (key != XK_Escape)
		return (1);
	if (game->map[y][x] == '1' || (game->map[y][x] == 'E' 
			&& game->nb_collectable != 0))
		return (1);
	else if (game->map[y][x] == 'C')
		return (swap_image(game, x, y), 0);
	else if (game->map[y][x] == 'E' && game->nb_collectable == 0)
		error_message(game, "Game ended. You won! Congratulations.\n");
	return (0);
}

static	int	key_press(int key, t_game *game)
{
	if (move_allowed(game, key) != 0)
		return (0);
	put_moves(game);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->bakg, 
			game->player_x * TILE_SIZE, game->player_y * TILE_SIZE);
	if (key == XK_Escape)
		error_message (game, "Game closed, goodbye!.\n");
	else if (key == XK_w || key == XK_Up)
		game->player_y--;
	else if (key == XK_s || key == XK_Down)
		game->player_y++;
	else if (key == XK_a || key == XK_Left)
		game->player_x--;
	else if (key == XK_d || key == XK_Right)
		game->player_x++;
	game->map[game->player_y][game->player_x] = 'P';
	ft_printf("Moves %d\n", game->moves++);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->player, 
			game->player_x * TILE_SIZE, game->player_y * TILE_SIZE);
	return (0);
}

static	int	close_in_cross(t_game *game)
{
	error_message(game, "Game closed, Goodbye!\n");
	return (0);
}

void	call_hooks(t_game *game)
{
	mlx_hook(game->mlx_win, KeyPress, KeyPressMask, key_press, game);
	mlx_hook(game->mlx_win, DestroyNotify, StructureNotifyMask, close_in_cross, 
			game);
}
