/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelbecq <hdelbecq@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:14:24 by hdelbecq          #+#    #+#             */
/*   Updated: 2024/09/19 14:12:18 by hdelbecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	close_game(t_game *game, char *message, int exit_mod)
{
	int	y;

	y = 0;
	while (game->map[y])
	{
		free(game->map[y]);
		game->map[y++] = NULL;
	}
	free(game->map);
	game->map = NULL;
	mlx_destroy_image(game->mlx, game->wall);
	mlx_destroy_image(game->mlx, game->floor);
	mlx_destroy_image(game->mlx, game->player);
	mlx_destroy_image(game->mlx, game->collectible);
	mlx_destroy_image(game->mlx, game->exit);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	game->mlx = NULL;
	if (message && *message && exit_mod == 0)
		printf("%s\n", message);
	else if (message && *message && exit_mod)
		write(2, message, ft_strlen(message));
	system("leaks so_long");
	exit(exit_mod);
}

int close_game_click(t_game *game)
{
	close_game(game, "You lose\n", 0);
	return (0);
}
