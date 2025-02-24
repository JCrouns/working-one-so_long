#include "so_long.h"

void draw_map(void *mlx, void *mlx_win, char **tab, int rows, int cols)
{
    int x, y;
    int width = 64;
    int height = 64;
    void *img;

    char *player_path = "player.xpm";
    char *wall_path = "wall.xpm";
    char *space_path = "empty.xpm";
    char *collectable_path = "fruite.xpm";
    char *exit_path = "exit.xpm";

    for (y = 0; y < rows; y++)
    {
        for (x = 0; x < cols; x++)
        {
            if (tab[y][x] == WALL)
            {
                img = mlx_xpm_file_to_image(mlx, wall_path, &width, &height);
            }
            else if (tab[y][x] == SPACE)
            {
                img = mlx_xpm_file_to_image(mlx, space_path, &width, &height);
            }
            else if (tab[y][x] == PLAYER)
            {
                img = mlx_xpm_file_to_image(mlx, player_path, &width, &height);
            }
            else if (tab[y][x] == COLLECTABLE)
            {
                img = mlx_xpm_file_to_image(mlx, collectable_path, &width, &height);
            }
            else if (tab[y][x] == EXIT)
            {
                img = mlx_xpm_file_to_image(mlx, exit_path, &width, &height);
            }
            else
            {
                img = NULL;
            }

            if (img)
            {
                mlx_put_image_to_window(mlx, mlx_win, img, x * 64, y * 64);
                mlx_destroy_image(mlx, img);
            }
            else
            {
                fprintf(stderr, "Error: Could not load image for tile %c\n", tab[y][x]);
            }
        }
    }
}

