/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:06:42 by karocha-          #+#    #+#             */
/*   Updated: 2024/12/26 20:09:40 by karocha-         ###   ########.fr       */
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

typedef struct
{
	char	**map;
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
	int		moves;
	int		endgame;
}			t_game;

#endif