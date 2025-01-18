/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karocha- <karocha-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:02:45 by karocha-          #+#    #+#             */
/*   Updated: 2025/01/18 15:17:03 by karocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
		free(game->map[i++]);
	free(game->map);
}

static	void	free_images(t_game *game)
{
	if (game->bakg)
		mlx_destroy_image(game->mlx, game->bakg);
	if (game->collectable)
		mlx_destroy_image(game->mlx, game->collectable);
	if (game->exit_closed)
		mlx_destroy_image(game->mlx, game->exit_closed);
	if (game->exit_open)
		mlx_destroy_image(game->mlx, game->exit_open);
	if (game->player)
		mlx_destroy_image(game->mlx, game->player);
	if (game->wall)
		mlx_destroy_image(game->mlx, game->wall);
}

void	error_message(t_game *game, char *str)
{
	if (str && str[0] != '\0')
		ft_putstr_fd(str, 2);
	if (!game)
		exit(0);
	free_images(game);
	if (game->map)
		free_map(game);
	if (game->mlx_win)
		mlx_destroy_window(game->mlx, game->mlx_win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free (game);
	exit(0);
}

void	free_arr_str(char **str)
{
	int	i;

	i = -1;
	if (!str || !str[0])
		return ;
	while (str[++i])
		free(str[i]);
	free(str);
}
