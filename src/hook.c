/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelbecq <hdelbecq@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:14:29 by hdelbecq          #+#    #+#             */
/*   Updated: 2024/09/21 14:40:31 by hdelbecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	count_moves(int key, t_game *game)
{
	if (key == KEY_W && game->map[game->player_y - 1][game->player_x] != '1')
	{
		ft_putnbr(++game->nb_move);
		write(1, "\n", 1);
	}
	else if (key == KEY_A \
		&& game->map[game->player_y][game->player_x - 1] != '1')
	{
		ft_putnbr(++game->nb_move);
		write(1, "\n", 1);
	}
	else if (key == KEY_S \
		&& game->map[game->player_y + 1][game->player_x] != '1')
	{
		ft_putnbr(++game->nb_move);
		write(1, "\n", 1);
	}
	else if (key == KEY_D \
		&& game->map[game->player_y][game->player_x + 1] != '1')
	{
		ft_putnbr(++game->nb_move);
		write(1, "\n", 1);
	}
}

int	key_hook(int key, t_game *game)
{
	count_moves(key, game);
	if (key == KEY_W \
		&& game->map[game->player_y - 1][game->player_x] != '1')
		game->player_y--;
	else if (key == KEY_A \
		&& game->map[game->player_y][game->player_x - 1] != '1')
		game->player_x--;
	else if (key == KEY_S \
		&& game->map[game->player_y + 1][game->player_x] != '1')
		game->player_y++;
	else if (key == KEY_D \
		&& game->map[game->player_y][game->player_x + 1] != '1')
		game->player_x++;
	else if (key == KEY_ESC)
		close_game(game, "You lose\n", 0);
	if (game->map[game->player_y][game->player_x] == 'C')
	{
		game->count_collectibles--;
		game->map[game->player_y][game->player_x] = '0';
	}
	else if (game->map[game->player_y][game->player_x] == 'E'
		&& game->count_collectibles == 0)
		close_game(game, "You win\n", 0);
	return (render_game(game), key);
}

void	bind_hooks(t_game *game)
{
	mlx_key_hook(game->win, key_hook, game);
	mlx_hook(game->win, 17, 0, close_game_click, game);
}
