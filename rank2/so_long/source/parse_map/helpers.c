/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 21:16:53 by karocha-          #+#    #+#             */
/*   Updated: 2025/01/17 18:01:05 by karocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static	void	get_position(t_game *game, int x, int y, char c)
{
	if (c == 'P')
	{
		game->player_x = x;
		game->player_y = y;
	}
	if (c == 'E')
	{
		game->exit_x = x;
		game->exit_y = y;
	}
}

static	void	check_elements(t_game *game, char c)
{
	int	y;
	int	x;
	int counter;

	y = -1;
	counter = 0;
	while (++y < game->map_y)
	{
		x = -1;
		while (++x < game->map_x)
		{
			if (game->map[y][x] == c)
			{
				counter++;
				get_position(game, x, y, c);
			}
		}
	}
	if (counter != 1)
		error_message(game, "Number of players and/or exits are not 1\n");
}

static	void	check_c(t_game *game, char c)
{
	int	i;
	int	j;
	int	counter;

	i = -1;
	counter = 0;
	while (++i < game->map_y)
	{
		j = -1;
		while (++j < game->map_x)
			if (game->map[i][j] == c)
				counter++;
	}
	if (counter < 1)	
		error_message(game, "Number of collectables not 1.\n");
	game->nb_collectable = counter;
}

void	valid_chars(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == '\n')
				break;
			if (game->map[i][j] != '1' && game->map[i][j] != '0' && 
				game->map[i][j] != 'P' && game->map[i][j] != 'C' &&
				game->map[i][j] != 'E')
				error_message(game, "Map does not have only valid chars.\n");
		}
	}
	check_elements(game, 'E');
	check_elements(game, 'P');
	check_c(game, 'C');
}
