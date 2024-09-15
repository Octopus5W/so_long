#include "../include/so_long.h"

void set_player_position(t_game *game)
{
	int i;
	int j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == 'P')
			{
				game->player_x = j;
				game->player_y = i;
				return ;
			}
		}
	}
}