/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 19:34:27 by karocha-          #+#    #+#             */
/*   Updated: 2025/01/15 23:12:00 by karocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	map_name(char *map)
{
	int	len;

	if (!map)
		return (0);
	len = ft_strlen(map);
	if (len < 4)
		return (0);
	if (ft_strncmp(&map[len - 4], ".ber", 4) == 0)
		return (1);
	return (0);
}

static	int	walls_x(t_game *game)
{
	int	i;

	i = -1;
	while (++i < game->map_x)
		if ((game->map[0][i] != '1' || game->map[game->map_y][i] != '1'))
			return (0);
	return (1);
}

static	int	walls_y(t_game *game)
{
	int	y;

	y = -1;
	while (++y < game->map_y)
		if (game->map[y][0] != '1' || game->map[y][game->map_x - 1] != '1')
			return (0);
	return (1);
}

void	wall_check(t_game *game)
{
	int	walls_horizontal;
	int	walls_vertical;

	walls_horizontal = walls_x(game);
	walls_vertical = walls_y(game);
	if (!walls_horizontal || !walls_vertical)
		error_message(game, "Map is not rounded by walls.\n");
}


