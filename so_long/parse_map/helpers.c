/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 21:16:53 by karocha-          #+#    #+#             */
/*   Updated: 2025/01/11 18:09:08 by karocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	horizontal_map(char *str)
{
	int	x;

	x = 0;
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
		aux = get_next_line(fd);
		counter++;
	}
	return (counter);
}

int	line_mod(t_game *game, char *line)
{
	char	**aux;
	int		i;

	if (!line)
		return (0);
	i = -1;
	game->map_y++;
	aux = (char **)malloc(sizeof(char *) * (game->map_y + 1));
	if (!aux)
		return (0);
	aux[game->map_y] = NULL; 
	while (++i < game->map_y - 1)
		aux[i] = game->map[i];
	aux[i] = line;
	if (game->map)
		free(game->map);
	game->map = aux;
	return (1);
}

int	is_rectangle(t_game *game)
{
	size_t	i;
	int	j;

	i = ft_strlen(game->map[0]);
	j = 0;
	while (game->map[++j])
		if (i != ft_strlen(game->map[j]))
		{
			error_message(game, "map is not a rectangle\n");
			return (0);
		}
	return (1);
}

int	valid_chars(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while(game->map[++i][j])
	{
		j = 0;
		while(game->map[i][j++])
			if (game->map[i][j] != '1' && game->map[i][j] != '0' && 
				game->map[i][j] != 'P' && game->map[i][j] != 'C' &&
				game->map[i][j] != 'E')
				return (0);
	}
	return (1);
}

void	print_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		ft_printf("%s", game->map[i]);
		i++;
	}
	ft_printf("\n");
}
