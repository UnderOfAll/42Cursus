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
		return (1);
	}
	len = ft_strlen(map_name);
	if (len < 4 || ft_strncmp(&map[len -4], ".ber", 4) != 0)
	{
		ft_printf("Map name doesn't end with .ber\n");
		return (1);
	}
	return (0);
}*/
static	int	walls_x(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_x)
	{
		if ((game->map[0][i] != '1' || game->map[game->map_y - 1][i] != '1'))
			return (0);
		i++;
	}
	return (1);
}

static	int	walls_y(t_game *game)
{
	int	y;

	y = 0;
	ft_printf("game->map_x :%i\n", game->map_x);
	ft_printf("game->map_y :%i\n", game->map_y);
	//ft_printf("game->map_y last: %c\n", game->map[game->map_y][game->map_x]);
	while (y < game->map_y)
	{
		if (game->map[y][0] != '1' || game->map[y][game->map_x - 1] != '1')
		{
			//ft_printf("game->map[%i][%i] '%c' != 1\n", y, 0, game->map[y][0]);
			//ft_printf("game->map[%i][%i] '%c' != 1\n", y, game->map_x - 1, game->map[y][game->map_x - 1]);
			return (0);
		}
		y++;
	}
	return (1);
}

void	wall_check(t_game *game)
{
	int	walls_horizontal;
	int	walls_vertical;

	walls_vertical = walls_x(game);
	walls_horizontal = walls_y(game);
	//ft_printf("y:%i\n", walls_vertical);
	//ft_printf("x:%i\n", walls_horizontal);
	if (!walls_horizontal || !walls_vertical)
	{
		ft_printf("Invalid map, not rounded by walls\n");
	}
}

void	read_map(char *av, t_game *game)
{
	int		fd;
	char	*mapper;
	int		i;

	i = 0;
	game = malloc(sizeof(t_game));
	game->map = malloc(sizeof(char *) * vertical_map(av));
	mapper = "romario";
	fd = open(av, O_RDONLY);
	if (fd < 0)
		return ;
	while (mapper)
	{
		mapper = get_next_line(fd);
		game->map[i++] = mapper;
	}
	game->map_y = i - 1;
	game->map_x = horizontal_map(game->map[0]);
	wall_check(game);
	print_map(game);
}
