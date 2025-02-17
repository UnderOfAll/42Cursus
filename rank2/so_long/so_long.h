/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:06:42 by karocha-          #+#    #+#             */
/*   Updated: 2025/01/21 13:30:15 by karocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libraries/libft/libft.h"
# include "libraries/minilibx/mlx.h"
# include "libraries/minilibx/mlx_int.h"
# include <fcntl.h>
# include <limits.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

#ifndef TILE_SIZE
# define TILE_SIZE 32
# endif

typedef struct s_game
{
	char	**map;
	char	*file_map;
	
	void 	*mlx;
	void	*mlx_win;

	void	*bakg;
	void	*wall;
	void	*player;
	void	*player2;
	void	*collectable;
	void	*exit_open;
	void	*exit_closed;

	int		player_image_x;
	int		player_image_y;
	int		player_image2_x;
	int		player_image2_y;

	int		bakg_x;
	int		bakg_y;
	
	int		wall_x;
	int		wall_y;

	int		player_x;
	int		player_y;

	int		collectable_x;
	int		collectable_y;

	int		exit_open_x;
	int		exit_open_y;
	int		exit_closed_x;
	int		exit_closed_y;

	int		exit_x;
	int		exit_y;
	int		map_x;
	int		map_y;
	int		screen_x;
	int		screen_y;
	int		nb_collectable;
	int		collectable_aux;
	int		aux_exit;
	int		fd;
	int		moves;
	int		endgame;
}			t_game;

//parse_map
t_game	*read_map(char *av, t_game *game);
void	wall_check(t_game *game);
int		map_name(char *map);

//helpers
int		horizontal_map(char *str);
int		vertical_map(char *str);
void	valid_chars(t_game *game);

//flood_fill
void	doable_map(t_game *game);

//frees
void	free_map(t_game *game);
void	error_message(t_game *game, char *str);
void	free_arr_str(char **str);

//display
void	game_start(t_game *game);
void	put_images(t_game *game);
void	start_moves(t_game *game);
void	put_moves(t_game *game);
void	call_hooks(t_game *game);

#endif