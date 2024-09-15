#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx_linux/mlx.h"
# include "../mlx_linux/mlx_int.h"
# include "../get_next_line/get_next_line.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define KEY_D 100
# define KEY_ESC 65307
# define EXIT 17

typedef struct s_texture
{
    char*     wall;
    char*   floor;
    char*     collectible;
    char*     player_img;
}   t_texture;

typedef struct s_game
{
    void    *mlx;         // Pointeur vers l'instance MLX
    void    *win;         // Pointeur vers la fenêtre MLX
    int     screen_width; // Largeur de l'écran
    int     screen_height; // Hauteur de l'écran
    int     player;      // Nombre de joueurs
    int     exit;        // Nombre de sorties
    int     collectibles; // Nombre de collectables
    int     exit_x;      // Position x de la sortie
    int     exit_y;      // Position y de la sortie
    int     player_x;    // Position x du joueur
    int     player_y;    // Position y du joueur
    char    **map;       // La carte du jeu
    int     map_width;   // Largeur de la carte
    int     map_height;  // Hauteur de la carte
    t_texture   texture;         // Les images du jeu
}   t_game;


int     init_game(t_game *game, const char *map_file);
int     load_map(t_game *game, const char *map_file);
void    render_game(t_game *game);
void    handle_player(t_game *game, char input);

//player
void    set_player_position(t_game *game);

//check_map
int     check_wall(t_game *game);
int     count_PEC(t_game *game);
void    back_track(char **map, int y, int x);
int     check_map(char **map);
int     is_possible(t_game *game);

//clean
void    free_game(t_game *game);
int     close_game(t_game *game);

//hook
void    bind_hooks(t_game *game);

// utils
int     ft_strlen(const char *s);
void    ft_free(char **tab, int size);
int     ft_strchr(const char *s, int c);
char    *ft_strdup(const char *s);
char    **ft_dup_tab(char **tab, int size);

#endif