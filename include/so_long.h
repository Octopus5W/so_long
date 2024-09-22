/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelbecq <hdelbecq@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 15:13:21 by hdelbecq          #+#    #+#             */
/*   Updated: 2024/09/22 16:24:16 by hdelbecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// includes
# include "../get_next_line/get_next_line.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

// keys
# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define KEY_D 100
# define KEY_ESC 65307
# define EXIT 17

// image
# define IMG_SIZE 64
# define WALL_FOLDER "sprite/wall.xpm"
# define FLOOR_FOLDER "sprite/floor.xpm"
# define PLAYER_FOLDER "sprite/player.xpm"
# define COLLECTIBLE_FOLDER "sprite/collectible.xpm"
# define EXIT_FOLDER "sprite/exit.xpm"

typedef struct s_game
{
	void	*mlx;
	void	*win;
	int		screen_width;
	int		screen_height;
	int		nb_move;
	int		count_player;
	int		count_exit;
	int		count_collectibles;
	int		exit_x;
	int		exit_y;
	int		player_x;
	int		player_y;
	char	**map;
	int		map_width;
	int		map_height;
	char	*img;
	int		img_width;
	int		img_height;
	void	*player;
	void	*wall;
	void	*floor;
	void	*collectible;
	void	*exit;
}			t_game;

int			init_game(t_game *game, const char *map_file);

void		render_game(t_game *game);

// player
void		set_player_position(t_game *game);

// check_map
int			check_wall(t_game *game);
int			count_pec(t_game *game);
void		back_track(char **map, int y, int x);
int			check_map(char **map);
int			is_possible(t_game *game);

// clean
int			close_game(t_game *game, char *message, int exit_mod);
int			close_game_click(t_game *game);

// hook
void		count_moves(int key, t_game *game);
void		bind_hooks(t_game *game);

// spite
void		set_sprite(t_game *game);
int			check_sprite(t_game *game);
void		put_sprite(t_game *game, int map_x, int map_y, char *sprite);

// utils
int			ft_strlen(const char *s);
void		ft_free(char **tab, int size);
int			ft_strchr(const char *s, int c);
char		*ft_strdup(const char *s);
char		**ft_dup_tab(char **tab, int size);
void		ft_putnbr(int n);

#endif