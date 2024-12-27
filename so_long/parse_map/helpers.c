/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 21:16:53 by karocha-          #+#    #+#             */
/*   Updated: 2024/12/27 21:32:25 by karocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	map_x(char *str)
{
	int	x;

	x = 0;
	while (str[x] != '\0')
		x++;
	if (str[x] == '\n')
		x--;
	return (x);
}

int	line_mod(t_game *game, char *line)
{
	char	**aux;
	int		i;

	if (!line)
		return (0);
	i = -1;
	game->y++;
	aux = (char **)malloc(sizeof(char *) * (game->y + 1));
	if (!aux)
		return (NULL);
	aux[game->y] = NULL; 
	while (++i < game->y - 1)
		aux[i] = game->map[i];
	aux[i] = line;
	if (game->map)
		free(game->map);
	game->map = aux;
	return (1);
}
