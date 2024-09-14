#include "../include/so_long.h"

int main(int argc, char **argv)
{
    t_game game;

    if (argc != 2)
    {
        write(2, "Usage: ./so_long <map_file>\n", 29);
        return (1);
    }

    if (!init_game(&game, argv[1]))
    {
        write(2, "Failed to initialize game\n", 26);
        return (1);
    }

    mlx_loop(game.mlx);  // Boucle principale de gestion des événements
    free_game(&game);
    return (0);
}