/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:50:45 by karocha-          #+#    #+#             */
/*   Updated: 2025/01/14 20:53:09 by karocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static	char	**copy_map(char **map, int map_x, int map_y)
{
	char	**aux;
	int		x;
	int		y;

	aux = malloc(sizeof(char *) * map_x + 1);
	if (!aux)
		return (NULL);
	y = -1;
	while (++y < map_x)
	{
		aux[y] = malloc((sizeof (char *) * map_y + 1));
		if (!aux[y])
			free_arr_str(aux);
		x = -1;
		while (++x < map_y)
			aux[y][x] = map [y][x];
		aux[y][x] = '\0';
	}
	aux[y] = NULL;
	return (aux);
}

static	void	flood_fill(t_game *game, char **aux, int x, int y)
{
	if (aux[y][x] == '1' || aux[y][x] == '2')
		return ;
	else if (aux[y][x] == 'C')
		game->collectable_aux--;
	else if (aux[y][x] == 'E')
	{
		game->aux_exit = 1;
		return ;
	}
	aux[y][x] = '2';
	flood_fill(game, aux, y - 1, x);
	flood_fill(game, aux, y + 1, x);
	flood_fill(game, aux, y, x - 1);
	flood_fill(game, aux, y, x + 1);
}

static	void	ff_checker(char **aux, t_game *game)
{
	if (game->collectable_aux != 0 || game->aux_exit != 1)
	{
		free_arr_str(aux);
		error_message(game, "Collectables or Exit inaccessible.\n");
	}
	free_arr_str(aux);
}

void	doable_map(t_game *game)
{
	char	**aux;

	aux = copy_map(game->map, game->map_x, game->map_y);
	game->collectable_aux = game->nb_collectable;
	flood_fill(game, aux, game->player_x, game->player_y);
	ff_checker(aux, game);
}
