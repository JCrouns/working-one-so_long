#include "so_long.h"


int move_player(t_game *game, char direction) {
    int new_row = game->player_row;
    int new_col = game->player_col;

    if (can_move(game, new_row, new_col, direction)) {
        if (direction == 'W') new_row--;
        else if (direction == 'S') new_row++;
        else if (direction == 'A') new_col--;
        else if (direction == 'D') new_col++;

        move_and_collect(game, new_row, new_col);
        return (1);
    }
    return (0);
}


int can_move(t_game *game, int new_row, int new_col, char direction) {
    if (direction == 'W' && new_row > 0 && game->map[new_row - 1][new_col] != WALL) return (1);
    if (direction == 'S' && new_row < game->rows - 1 && game->map[new_row + 1][new_col] != WALL) return (1);
    if (direction == 'A' && new_col > 0 && game->map[new_row][new_col - 1] != WALL) return (1);
    if (direction == 'D' && new_col < game->cols - 1 && game->map[new_row][new_col + 1] != WALL) return (1);
    return (0);
}

void move_and_collect(t_game *game, int new_row, int new_col) {
    if (game->map[new_row][new_col] == COLLECTABLE) {
        game->collected_items++;
    }
    game->map[game->player_row][game->player_col] = SPACE;
    game->player_row = new_row;
    game->player_col = new_col;
    game->map[game->player_row][game->player_col] = PLAYER;
    game->movements++;
    display_moves(game);
}
