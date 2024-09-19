/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelbecq <hdelbecq@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:14:35 by hdelbecq          #+#    #+#             */
/*   Updated: 2024/09/19 12:14:36 by hdelbecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	count_lines(const char *map_file)
{
	int		fd;
	char	*line;
	int		count_lines;
	int		lenght;

	count_lines = 0;
	lenght = -1;
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		return (0);
	while ((line = get_next_line(fd)) != NULL)
	{
		if (lenght == -1)
			lenght = ft_strlen(line);
		else if ((ft_strlen(line) != lenght && ft_strchr(line, '\n'))
			|| (ft_strlen(line) + 1 != lenght && ft_strchr(line, '\0')))
			return (close(fd), 0);
		count_lines++;
		free(line);
	}
	close(fd);
	return (count_lines);
}

static int	count_width(const char *map_file)
{
	int		fd;
	char	*line;
	int		lenght;

	lenght = -1;
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	if (line)
		lenght = ft_strlen(line);
	while ((line = get_next_line(fd)) != NULL)
		free(line);
	close(fd);
	return (lenght);
}

static int	alloc_map(t_game *game, const char *map_file)
{
	int	i;
	int	fd;

	game->map = malloc(sizeof(char *) * (game->map_height + 1));
	if (!game->map)
		return (0);
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		return (0);
	i = -1;
	while (++i < game->map_height)
	{
		game->map[i] = get_next_line(fd);
		if (!game->map[i])
			return (close(fd), ft_free(game->map, i), 0);
		if (i == 0)
			game->map_width = ft_strlen(game->map[i]);
	}
	close(fd);
	game->map[game->map_height] = NULL;
	return (1);
}

int	init_game(t_game *game, const char *map_file)
{
	game->map_height = count_lines(map_file);
	if (game->map_height < 3)
		return (0);
	game->map_width = count_width(map_file);
	if (game->map_width < 5)
		return (ft_free(game->map, game->map_height), 0);
	if (!alloc_map(game, map_file))
		return (0);
	set_player_position(game);
	if (!is_possible(game))
		return (ft_free(game->map, game->map_height), 0);
	game->mlx = mlx_init();
	mlx_get_screen_size(game->mlx, &game->screen_width, &game->screen_height);
	if (game->screen_height < (game->map_height * 64)
		|| game->screen_width < (game->map_width * 64))
		return (ft_free(game->map, game->map_height),
			mlx_destroy_display(game->mlx), 0);
	game->win = mlx_new_window(game->mlx, (game->map_width * 64),
			(game->map_height * 64), "SO_LOOOOONG");
	bind_hooks(game);
	return (1);
}
