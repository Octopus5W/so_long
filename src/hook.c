#include "../include/so_long.h"

int key_hook(int key, t_game *game)
{
    if (key == KEY_W && game->player_y > 1)  // Haut
        game->player_y--;
    else if (key == KEY_A && game->player_x > 1)  // Gauche
        game->player_x--;
    else if (key == KEY_S && game->player_y < game->map_height - 2)  // Bas
        game->player_y++;
    else if (key == KEY_D && game->player_x < game->map_width - 2)  // Droite
        game->player_x++;
    else if (key == KEY_ESC)  // Echap
        close_game(game);
    // Redessiner la carte après le déplacement
    render_game(game);
    return (0);
}

void bind_hooks(t_game *game)
{
    mlx_key_hook(game->win, key_hook, game);
    mlx_hook(game->win, 17, 0, close_game, game);
}