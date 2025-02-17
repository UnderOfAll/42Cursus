/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 18:27:16 by karocha-          #+#    #+#             */
/*   Updated: 2025/01/17 19:44:23 by karocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static	int	is_rectangle(t_game *game)
{
	int	j;
	int	i;
	int	k;

	i = horizontal_map(game->map[0]);
	j = -1;
	while (game->map[++j])
	{
		k = 0;
		while (game->map[j][k++])
			if (game->map[j][k] == '\n' || game->map[j][k] == '\0')
				break;
		if (k != i)
			{
				error_message(game, "Map is not a rectangle.\n");
				return (0);
			}
	}
	return (1);
}

int	horizontal_map(char *str)
{
	int	x;

	x = 0;
	if (!str)
		return (0);
	while (str[x] != '\0' && str[x] != '\n')
		x++;
	return (x);
}

int	vertical_map(char *str)
{
	int		counter;
	int		fd;
	char	*aux;

	aux = "jorge";
	fd = open(str, O_RDONLY);
	counter = 0;
	while (aux)
	{
		if (counter != 0)
			free(aux);
		aux = get_next_line(fd);
		counter++;
	}
	return (counter);
}

static	void	check_valid(t_game *game, int i)
{
	if (!game->map[0])
		error_message(game, "Map is empty\n");
	game->map_y = i - 2;
	game->map_x = horizontal_map(game->map[0]);
	wall_check(game);
	is_rectangle(game);
	valid_chars(game);
	doable_map(game);
}

t_game	*read_map(char *av, t_game *game)
{
	int		fd;
	char	*mapper;
	int		i;
	if (map_name(av) != 1)
		error_message(game, "Incorrect file name.\n");
	i = 0;
	fd = open(av, O_RDONLY);
	if (fd < 0)
		error_message(game, "File is not in the repository.\n");
	game = malloc(sizeof(t_game));
	game->map = malloc(sizeof(char *) * vertical_map(av));
	if (!game || !game->map)
		return NULL;
	mapper = "romario";
	while (mapper)
	{
		mapper = get_next_line(fd);
		game->map[i++] = mapper;
	}
	check_valid(game, i);
	close (fd);
	return (game);
}
