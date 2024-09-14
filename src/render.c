#include "../include/so_long.h"

void render_game(t_game *game)
{
    int x, y;
    char c;

    y = 0;
    while (y < game->map_height)
    {
        x = 0;
        while (x < game->map_width)
        {
            c = game->map[y][x];
            if (c == '1')  // Mur
                mlx_pixel_put(game->mlx, game->win, x * 32, y * 32, 0xFFFFFF);  // Exemple de couleur pour les murs
            else if (c == '0')  // Sol
                mlx_pixel_put(game->mlx, game->win, x * 32, y * 32, 0x000000);  // Exemple de couleur pour le sol
            else if (c == 'C')  // Collectable
                mlx_pixel_put(game->mlx, game->win, x * 32, y * 32, 0x00FF00);  // Exemple de couleur pour les collectables
            else if (c == 'E')  // Sortie
                mlx_pixel_put(game->mlx, game->win, x * 32, y * 32, 0xFF0000);  // Exemple de couleur pour la sortie
            x++;
        }
        y++;
    }
}
