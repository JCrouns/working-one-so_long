#include "so_long.h"

/* Opens the map file */
int open_file(char *file_name) {
    int fd = open(file_name, O_RDONLY);
    if (fd < 0) {
        write(2, "Error\nCould not open map file\n", 30);
        exit(1);
    }
    return fd;
}

/* Reads the map size (rows and columns) */
void read_map_size(t_game *game, char *file_name) {
    char *line;
    game->rows = 0;
    game->cols = 0;

    game->fd = open_file(file_name);
    while ((line = get_next_line(game->fd)) != NULL) {
        game->rows++;
        if (game->cols == 0) {
            game->cols = strlen(line) - 1;
        }
        free(line);
    }
    close(game->fd);
}

/* Allocates memory for the map and reads it */
void allocate_map(t_game *game, char *file_name) {
    char *line;
    int r = 0;

    game->fd = open_file(file_name);
    game->map = (char **)malloc(sizeof(char *) * game->rows);
    if (!game->map) {
        perror("Error allocating memory for map");
        exit(1);
    }

    while ((line = get_next_line(game->fd)) != NULL) {
        game->map[r] = strdup(line);
        free(line);
        r++;
    }
    close(game->fd);
}

/* Validates the map: checks walls, player, collectables, etc. */
void process_map(t_game *game) {
    if (!check_rectangular_map(game)) {
        write(2, "Error\nThe map is not rectangular\n", 34);
        exit(1);
    }
    if (!check_surrounding_walls(game)) {
        write(2, "Error\nThe map is not surrounded by walls\n", 42);
        exit(1);
    }
    if (!check_exit_and_collectables(game)) {
        write(2, "Error\nThe map is missing essential elements (exit/collectables)\n", 65);
        exit(1);
    }
}
