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
					return(ft_free(game->map, game->map_height), 0);
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
        return(ft_free(game->map, game->map_height), 0);
    else
        return(1);
}
