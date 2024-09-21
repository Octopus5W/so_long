/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelbecq <hdelbecq@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:14:41 by hdelbecq          #+#    #+#             */
/*   Updated: 2024/09/21 14:41:29 by hdelbecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_filename(char *filename, char *extension)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (filename && filename[i])
		i++;
	if (i >= 5)
	{
		while (extension + j && *(filename + i - 4 + j) == *(extension + j))
			j++;
	}
	if (j == 5)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	game.nb_move = 0;
	if (argc != 2 || !check_filename(argv[1], ".ber"))
		return (write(2, "Error: ./so_long [map.ber]\n", 27), 1);
	if (!init_game(&game, argv[1]))
		return (write(2, "Error: Failed to init game\n", 27), 1);
	set_sprite(&game);
	if (!check_sprite(&game))
		return (write(2, "Error: Failed to load image\n", 27), 1);
	render_game(&game);
	set_player_position(&game);
	bind_hooks(&game);
	mlx_loop(game.mlx);
	return (0);
}
