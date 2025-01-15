/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:06:39 by karocha-          #+#    #+#             */
/*   Updated: 2025/01/15 21:28:56 by karocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*static int	check_arg(int ac, char **av, t_game *game)
{
	if (ac != 2)
		return (1);
	game->moves = 0;
	if (map_name(av[1]))
		return (1);
	game->file_map = av[1];

}*/

int	main(int ac, char **av)
{
	t_game	*game;

	game = NULL;
	if (ac != 2)
		error_message(game, "Invalid number of arguments");
	game = read_map(av[1], game);
	free_arr_str(game->map);
	free(game);
	return (0);
}
