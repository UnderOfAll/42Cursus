/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 18:27:16 by karocha-          #+#    #+#             */
/*   Updated: 2025/01/11 18:09:46 by karocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*int	map_name(char *map)
{
	int	len;

	if (!map_name)
	{
		ft_printf("No name for the map\n");
		return (0);
	}
	len = ft_strlen(map_name);
	if (len < 4 || ft_strncmp(&map[len -4], ".ber", 4) != 0)
	{
		ft_printf("Map name doesn't end with .ber\n");
		return (0);
	}
	return (1);
}*/
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
		error_message(game, "Map is not rounded by walls.");
}

void	read_map(char *av, t_game *game)
{
	int		fd;
	char	*mapper;
	int		i;

	i = 0;
	game = malloc(sizeof(t_game));
	game->map = malloc(sizeof(char *) * vertical_map(av));
	if (!game || !game->map)
		return ;
	mapper = "romario";
	fd = open(av, O_RDONLY);
	if (fd < 0)
		return ;
	while (mapper)
	{
		mapper = get_next_line(fd);
		game->map[i++] = mapper;
	}
	game->map_y = i - 2;
	game->map_x = horizontal_map(game->map[0]);
	wall_check(game);
	is_rectangle(game);
	valid_chars(game);
	print_map(game);
}
