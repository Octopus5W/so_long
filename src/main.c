#include "../include/so_long.h"

int main(int argc, char **argv)
{
    t_game game;

    if (argc != 2)
        return (write(2, "Usage: ./so_long [map]\n", 23), 1);
    if (!init_game(&game, argv[1]))
        return (write(2, "Failed to init game\n", 21), 1);
    if (!set_sprite(&game))
        return(write(2, "Failed to load image\n", 22), 1);
    render_game(&game);
    set_player_position(&game);
    bind_hooks(&game);
    mlx_loop(game.mlx);
    system("leaks so_long");
    return (0);
}