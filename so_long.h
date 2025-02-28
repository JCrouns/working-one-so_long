#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

# define PLAYER 'P'
# define COLLECTABLE 'C'
# define WALL '1'
# define SPACE '0'
# define EXIT 'E'

# define WIN_WIDTH 64
# define WIN_HEIGHT 64

typedef struct s_game {
    void    *mlx;
    void    *mlx_win;
    void    *img;
    int     width;
    int     height;
    char    **map;
    int     rows;
    int     cols;
    int     player_row;
    int     player_col;
    int     collected_items;
    int     total_collectables;
    int     movements;
} t_game;

int     open_file(char *file_name);
void    read_map_size(t_game *game, char *file_name);
void    allocate_map(t_game *game, char *file_name);
void    process_map(t_game *game);


void    validate_map(t_game *game);
int     check_rectangular_map(t_game *game);
int     check_surrounding_walls(t_game *game);
int     check_exit_and_collectables(t_game *game);

int     move_player(t_game *game, char direction);
int     can_move(t_game *game, int new_row, int new_col, char direction);
void    move_and_collect(t_game *game, int new_row, int new_col);

void    draw_map(t_game *game);
void    *load_image(t_game *game, char tile);
void    init_mlx(t_game *game);
int     key_hook(int keycode, void *param);
void    display_moves(t_game *game);

void    free_map(char **map, int rows);

#endif
