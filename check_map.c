#include "so_long.h"


int check_rectangular_map(t_game *game) {
    int len = strlen(game->map[0]);
    int i = 1;

    while (i < game->rows) {
        if (strlen(game->map[i]) != len) {
            return (0);
        }
        i++;
    }
    return (1);
}


int check_surrounding_walls(t_game *game) {
    int i = 0;

    while (i < game->cols) {
        if (game->map[0][i] != WALL || game->map[game->rows - 1][i] != WALL)
            return (0);
        i++;
    }

    i = 0;
    while (i < game->rows) {
        if (game->map[i][0] != WALL || game->map[i][game->cols - 1] != WALL)
            return (0);
        i++;
    }

    return (1);
}


int check_exit_and_collectables(t_game *game) {
    int exit_count = 0;
    int start_count = 0;
    int collect_count = 0;
    int i = 0;
    int j = 0;

    while (i < game->rows) {
        j = 0;
        while (j < game->cols) {
            if (game->map[i][j] == EXIT)
                exit_count++;
            else if (game->map[i][j] == PLAYER)
                start_count++;
            else if (game->map[i][j] == COLLECTABLE)
                collect_count++;
            j++;
        }
        i++;
    }

    if (exit_count != 1 || start_count != 1 || collect_count == 0)
        return (0);
    
    return (1);
}

