#include "../include/so_long.h"

void render_game(t_game *game)
{
    int i;
    int j;

    i = -1;
    while (game->map[++i])
    {
        j = -1;
        while (game->map[i][++j])
        {
            if (game->map[i][j] == '1')
                put_sprite(game, j, i, game->wall);
            else if (game->map[i][j] == '0')
                put_sprite(game, j, i, game->floor);
            else if (game->map[i][j] == 'C')
            {
                put_sprite(game, j, i, game->floor);
                put_sprite(game, j, i, game->collectible);
            }
            else if (game->map[i][j] == 'E')
                put_sprite(game, j, i, game->exit);
            else if (game->map[i][j] == 'P')
                put_sprite(game, j, i, game->floor);
        }
    }
    put_sprite(game, game->player_x, game->player_y, game->player);
}
