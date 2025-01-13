/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:06:42 by karocha-          #+#    #+#             */
/*   Updated: 2025/01/11 18:05:27 by karocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libraries/libft/libft.h"
# include "libraries/minilibx/mlx.h"
# include <fcntl.h>
# include <limits.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_game
{
	char	**map;
	char	*file_map;

	void	*bakg;
	void	*wall;
	void	*player;
	void	*collectable;
	void	*exit;

	int		map_x;
	int		map_y;

	int		img_x;
	int		img_y;

	int		player_x;
	int		player_y;

	int		fd;
	int		moves;
	int		endgame;
}			t_game;

//parse_map
int	map_name(char *map);
void	read_map(char *av, t_game *game);
void	wall_check(t_game *game);

//helpers
int	horizontal_map(char *str);
int	vertical_map(char *str);
int	line_mod(t_game *game, char *line);
void	print_map(t_game *game);
int	is_rectangle(t_game *game);
int	valid_chars(t_game *game);

//frees
void	free_memory(t_game *game);
void	error_message(t_game *game, char *str);	

#endif