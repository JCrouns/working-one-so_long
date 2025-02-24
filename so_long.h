#ifndef SO_LONG_H
#define SO_LONG_H
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "/usr/include/minilibx-linux/mlx.h"
#define WALL '1'
#define PLAYER 'P'
#define SPACE '0'
#define EXIT 'E'
#define COLLECTABLE 'C'

/*extern int player_row;
extern int player_col;
extern int collected_items ;
extern int total_collectables ;
*/

int check_argc(int c);
int open_file(char *file_name);
void process_map(char **map, int rows, int cols);
void free_map(char **map , int rows);
void print_map(char **tab , int rows , int cols);
void draw_map(void *mlx , void *mlx_win , char **tab , int rows , int cols);
void find_player_position(char **tab , int rows , int cols);
int move_player(char **tab , int rows ,  int cols , char direction);
int key_hook(int keycode , void *param);
void mlx_stuff(char **map , int rows , int cols , void *mlx ,void *mlx_win);
#endif

