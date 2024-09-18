#include "../include/so_long.h"

int set_sprite(t_game *game)
{
    game->wall = mlx_xpm_file_to_image(game->mlx, "sprite/wall.xpm", &game->img_width, &game->img_height);
    game->floor = mlx_xpm_file_to_image(game->mlx, "sprite/floor.xpm", &game->img_width, &game->img_height);
    game->player = mlx_xpm_file_to_image(game->mlx, "sprite/player.xpm", &game->img_width, &game->img_height);
    game->collectible = mlx_xpm_file_to_image(game->mlx, "sprite/collectible.xpm", &game->img_width, &game->img_height);
    game->exit = mlx_xpm_file_to_image(game->mlx, "sprite/exit.xpm", &game->img_width, &game->img_height);
    if (!game->wall || !game->floor || !game->player || !game->collectible || !game->exit)
    {
        if (game->wall)
            mlx_destroy_image(game->mlx, game->wall);
        if (game->floor)
            mlx_destroy_image(game->mlx, game->floor);
        if (game->player)
            mlx_destroy_image(game->mlx, game->player);
        if (game->collectible)
            mlx_destroy_image(game->mlx, game->collectible);
        if (game->exit)
            mlx_destroy_image(game->mlx, game->exit);
        return (0);
    }
    return (1);
}

void put_sprite(t_game *game, int map_x, int map_y, char* sprite)
{
    map_x *= IMG_SIZE;
    map_y *= IMG_SIZE;
    mlx_put_image_to_window(game->mlx, game->win, sprite, map_x, map_y);
}
 
