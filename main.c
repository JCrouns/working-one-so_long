#include "so_long.h"


int main(int argc, char **argv)
{
    check_argc(argc);
    int fd = open_file(argv[1]);

    char *line = NULL;
    char **map = NULL;
    int rows = 0;
    int cols = 0;

    while ((line = get_next_line(fd)) != NULL)
    {
        rows++;
        if (cols == 0)
        {
            cols = strlen(line) - 1;
        }
        free(line);
    }

    close(fd);
    fd = open_file(argv[1]);

    map = (char **)malloc(sizeof(char *) * rows);
    if (!map)
    {
        perror("Error allocating memory for map");
        close(fd);
        return EXIT_FAILURE;
    }

    int r = 0;
    while ((line = get_next_line(fd)) != NULL)
    {
        map[r] = (char *)malloc(sizeof(char) * (cols + 1));
        if (!map[r])
        {
            perror("Error allocating memory for map row");
            close(fd);
            free_map(map, r);
            return EXIT_FAILURE;
        }
        strncpy(map[r], line, cols);
        map[r][cols] = '\0';
        free(line);
        r++;
    }

    close(fd);

    process_map(map , rows , cols);
    printf("Map checked and it is success!\n");

    find_player_position(map, rows, cols);

    int game_status = 0;
    void *mlx;
    void *mlx_win;
    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, cols * 64, rows * 64, "so_long");

    draw_map(mlx, mlx_win, map, rows, cols);

    void *params[6];
    params[0] = map;
    params[1] = (void *)(size_t)rows;
    params[2] = (void *)(size_t)cols;
    params[3] = &game_status;
    params[4] = mlx;
    params[5] = mlx_win;

    mlx_key_hook(mlx_win, key_hook, params);

    mlx_loop(mlx);

//    mlx_stuff(map , rows , cols, mlx, mlx_win);
    free_map(map, rows);

    return EXIT_SUCCESS;
    }
