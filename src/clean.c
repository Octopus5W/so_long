#include "../include/so_long.h"

int close_game(t_game *game)
{
    int y = 0;

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
    system("leaks so_long");
    exit(0);
}
