/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 18:27:16 by karocha-          #+#    #+#             */
/*   Updated: 2024/12/27 21:36:07 by karocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	map_name(char *map)
{
	int	len;

	if (!map_name)
	{
		ft_printf("No name for the map\n");
		return (1);
	}
	len = ft_strlen(map_name);
	if (len < 4 || ft_strncmp(&map[len -4], ".ber", 4) != 0)
	{
		ft_printf("Map name doesn't end with .ber\n");
		return (1);
	}
	return (0);
}

int	read_map(t_game *game)
{
	game->fd = open(game->file_map, O_RDONLY);
	if (game->fd < 0)
		return (0);
	
}
