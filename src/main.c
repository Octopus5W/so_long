/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelbecq <hdelbecq@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:14:41 by hdelbecq          #+#    #+#             */
/*   Updated: 2024/09/19 12:14:42 by hdelbecq         ###   ########.fr       */
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
	t_game game;

	if (argc != 2 || !check_filename(argv[1], ".ber"))
		return (write(2, "Usage: ./so_long [map.ber]\n", 27), 1);
	if (!init_game(&game, argv[1]))
		return (write(2, "Failed to init game\n", 21), 1);
	if (!set_sprite(&game))
		return (write(2, "Failed to load image\n", 22), 1);
	render_game(&game);
	set_player_position(&game);
	bind_hooks(&game);
	mlx_loop(game.mlx);
	system("leaks so_long");
	return (0);
}