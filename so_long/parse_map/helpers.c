/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 21:16:53 by karocha-          #+#    #+#             */
/*   Updated: 2025/01/07 18:31:24 by karocha-         ###   ########.fr       */
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

int	map_y(char *str)
{
	int		counter;
	int		fd;
	char	*aux;

	aux = "jorge";
	fd = open(str, O_RDONLY);
	counter = 0;
	while(aux)
	{
		aux = get_next_line(fd);
		counter++;
	}
	return (counter);
}

/*int	line_mod(t_game *game, char *line)
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
}*/

void	print_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		ft_printf("%s", game->map[i++]);
	}
}
