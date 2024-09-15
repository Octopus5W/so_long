#include "../include/so_long.h"

int check_wall(t_game *game)
{
	int i;
	int j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if ((i == 0 || i == game->map_height - 1 || j == 0 || j == game->map_width - 1) && game->map[i][j] != '\n')
			{
				if (game->map[i][j] != '1')
					return(0);
			}
		}
	}
	return (1);
}

int count_PEC(t_game *game)
{
    int i;
    int j;

    i = -1;
    game->player = 0;
    game->collectibles = 0;
    game->exit = 0;
    while (++i < game->map_height)
    {
        j = -1;
        while (++j < game->map_width)
        {
            if (game->map[i][j] == 'P')
                game->player++;
            else if (game->map[i][j] == 'C')
                game->collectibles++;
            else if (game->map[i][j] == 'E')
                game->exit++;
        }
    }
    if (game->player != 1 || game->exit != 1 || game->collectibles < 1)
        return(0);
    else
        return(1);
}

void back_track(char **map, int y, int x)
{
    map[y][x] = '2';
    if (map[y + 1][x] != '1' && map[y + 1][x] != '2')
        back_track( map, y + 1, x);
    if ((map[y - 1][x] != '1' && map[y - 1][x] != '2'))
        back_track(map, y - 1, x);
    if (map[y][x + 1] != '1' && map[y][x + 1] != '2') 
        back_track(map, y, x + 1);
    if (map[y][x - 1] != '1' && map[y][x - 1] != '2')
        back_track(map, y, x - 1);
}

int check_map(char **map)
{
    int i;
    int j;

    i = -1;
    while (map[++i])
    {
        j = -1;
        while (map[i][++j])
        {
            if (map[i][j] == 'E' || map[i][j] == 'C')
                return (0);
        }
    }
    return (1);
}

int is_possible(t_game *game)
{
    char **map;

    map = ft_dup_tab(game->map, game->map_height);
    if (!map)
        return (0);
    if (!check_wall(game) || !count_PEC(game))
        return (ft_free(map, game->map_height), 0);
    back_track(map, game->player_y, game->player_x);
    if (!check_map(map))
        return (ft_free(map, game->map_height), 0);
    return (ft_free(map, game->map_height), 1);
}
