#include "../include/so_long.h"

void free_game(t_game *game)
{
    int y = 0;

    while (game->map[y])
    {
        free(game->map[y]);
        game->map[y++] = NULL;
    }
    free(game->map);
    game->map = NULL;
    mlx_destroy_window(game->mlx, game->win);
    mlx_destroy_display(game->mlx);
    game->mlx = NULL;
}

int close_game(t_game *game)
{
    free_game(game);
    exit(0);
}
