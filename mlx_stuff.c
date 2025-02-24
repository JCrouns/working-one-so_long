#include "so_long.h"

void mlx_stuff(char **map , int rows , int cols , void *mlx , void *mlx_win)
{
    void *params[6];
    //void *mlx;
    //void *mlx_win;
    int game_status = 0;
    params[0] = map;
    params[1] = &rows;
    params[2] = &cols;
    params[3] = &game_status;
    params[4] = mlx;
    params[5] = mlx_win;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx , cols * 64 , rows * 64 , "crouns_so_long");
    draw_map(mlx , mlx_win , map , rows , cols);
    mlx_key_hook(mlx_win , key_hook , params);
    mlx_loop(mlx);
}
