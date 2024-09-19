#include "../include/so_long.h"

int key_hook(int key, t_game *game)
{
    printf("%i\n", key);
    if (key == KEY_W && game->map[game->player_y - 1][game->player_x] != '1')
        game->player_y--;
    else if (key == KEY_A && game->map[game->player_y][game->player_x - 1] != '1')
        game->player_x--;
    else if (key == KEY_S && game->map[game->player_y + 1][game->player_x] != '1')
        game->player_y++;
    else if (key == KEY_D && game->map[game->player_y][game->player_x + 1] != '1')
        game->player_x++;
    if (game->map[game->player_y][game->player_x] == 'C')
    {
        game->count_collectibles--;
        game->map[game->player_y][game->player_x] = '0';
    }
    if (key == KEY_ESC || (game->map[game->player_y][game->player_x] == 'E' && game->count_collectibles == 0))
        close_game(game);
    return (render_game(game), key);
}

void bind_hooks(t_game *game)
{
    mlx_key_hook(game->win, key_hook, game);
    mlx_hook(game->win, 17, 0, close_game, game);
}