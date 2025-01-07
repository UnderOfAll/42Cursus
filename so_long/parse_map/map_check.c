/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 18:27:16 by karocha-          #+#    #+#             */
/*   Updated: 2025/01/07 19:52:29 by karocha-         ###   ########.fr       */
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


void	read_map(char *av, t_game *game)
{
	int		fd;
	char	*mapper;
	int		i;

	i = 0;
	game = malloc(sizeof(t_game));
	game->map = malloc(sizeof(char *) * map_y(av));
	mapper = "romario";
	fd = open(av, O_RDONLY);
	if (fd < 0)
		return ;
	while (mapper)
	{
		mapper = get_next_line(fd);
		game->map[i++] = mapper;
	}
	print_map(game);
}
