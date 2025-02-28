#include "so_long.h"

void draw_map(t_game *game) {
    void *img;
    int r = 0;
    int c = 0;

    while (r < game->rows) {
        c = 0;
        while (c < game->cols) {
            img = load_image(game, game->map[r][c]);
            mlx_put_image_to_window(game->mlx, game->mlx_win, img, c * WIN_WIDTH, r * WIN_HEIGHT);
            c++;
        }
        r++;
    }
}

/* Loads the image for each tile */
void *load_image(t_game *game, char tile) {
    char *file_path;

    if (tile == PLAYER) file_path = "player.xpm";
    else if (tile == COLLECTABLE) file_path = "collectable.xpm";
    else if (tile == WALL) file_path = "wall.xpm";
    else if (tile == EXIT) file_path = "exit.xpm";
    else file_path = "empty.xpm";

    return mlx_xpm_file_to_image(game->mlx, file_path, &game->width, &game->height);
}

/* Initializes the mlx window */
void init_mlx(t_game *game) {
    game->mlx = mlx_init();
    game->mlx_win = mlx_new_window(game->mlx, game->cols * WIN_WIDTH, game->rows * WIN_HEIGHT, "so_long");
}

/* Handles keypresses */
int key_hook(int keycode, void *param) {
    t_game *game = (t_game *)param;

    if (keycode == 53) {
        mlx_destroy_window(game->mlx, game->mlx_win);
        exit(0);
    }
    if (keycode == 13 || keycode == 126) {
        move_player(game, 'W');
    }
    if (keycode == 1 || keycode == 125) {
        move_player(game, 'S');
    }
    if (keycode == 0 || keycode == 123) {
        move_player(game, 'A');
    }
    if (keycode == 2 || keycode == 124) {
        move_player(game, 'D');
    }
    return (0);
}

/* Displays the number of moves in the window */
void display_moves(t_game *game) {
    char *moves;

    moves = ft_itoa(game->movements);
    mlx_string_put(game->mlx, game->mlx_win, 10, 10, 0xFFFFFF, "Moves: ");
    mlx_string_put(game->mlx, game->mlx_win, 70, 10, 0xFFFFFF, moves);
    free(moves);
}

