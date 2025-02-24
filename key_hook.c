#include "so_long.h"
int player_row = -1;
int player_col = -1;
int collected_items = 0;
int total_collectables = 0;


void find_player_position(char **tab, int rows, int cols)
{
    int r = 0;
    while (r < rows)
    {
        int c = 0;
        while (c < cols)
        {
            if (tab[r][c] == PLAYER)
            {
                player_row = r;
                player_col = c;
                return;
            }
            c++;
        }
        r++;
    }
}

*/int move_player(char **tab, int rows, int cols, char direction)
{
    find_player_position(tab, rows, cols);

    int new_row = player_row;
    int new_col = player_col;

    if (direction == 'W' && new_row > 0 && tab[new_row - 1][new_col] != WALL) {
        new_row--;
    }
    else if (direction == 'S' && new_row < rows - 1 && tab[new_row + 1][new_col] != WALL) {
        new_row++;
    }
    else if (direction == 'A' && new_col > 0 && tab[new_row][new_col - 1] != WALL) {
        new_col--;
    }
    else if (direction == 'D' && new_col < cols - 1 && tab[new_row][new_col + 1] != WALL) {
        new_col++;
    }
    else {
        return 0;
    }

    if (tab[new_row][new_col] == COLLECTABLE) {
        collected_items++;
    }

    tab[player_row][player_col] = SPACE;
    player_row = new_row;
    player_col = new_col;
    tab[player_row][player_col] = PLAYER;
    return 1;
}*/

int can_move(char **tab, int rows, int cols, int new_row, int new_col, char direction) {
    if (direction == 'W' && new_row > 0 && tab[new_row - 1][new_col] != WALL) {
        return 1;
    }
    else if (direction == 'S' && new_row < rows - 1 && tab[new_row + 1][new_col] != WALL) {
        return 1;
    }
    else if (direction == 'A' && new_col > 0 && tab[new_row][new_col - 1] != WALL) {
        return 1;
    }
    else if (direction == 'D' && new_col < cols - 1 && tab[new_row][new_col + 1] != WALL) {
        return 1;
    }
    return 0;
}

// Function to handle the movement and collect items
void move_and_collect(char **tab, int new_row, int new_col) {
    if (tab[new_row][new_col] == COLLECTABLE) {
        collected_items++;
    }

    tab[player_row][player_col] = SPACE;
    player_row = new_row;
    player_col = new_col;
    tab[player_row][player_col] = PLAYER;
}

// Main move_player function now using helper functions
int move_player(char **tab, int rows, int cols, char direction) {
    find_player_position(tab, rows, cols);

    int new_row = player_row;
    int new_col = player_col;

    if (can_move(tab, rows, cols, new_row, new_col, direction)) {
        if (direction == 'W') {
            new_row--;
        }
        else if (direction == 'S') {
            new_row++;
        }
        else if (direction == 'A') {
            new_col--;
        }
        else if (direction == 'D') {
            new_col++;
        }
        
        move_and_collect(tab, new_row, new_col);
        return 1;
    }
    return 0;
}    

int key_hook(int keycode, void *param)
{
    static char **map;
    static int rows;
    static int cols;
    static int *game_status;
    static void *mlx;
    static void *mlx_win;

    if (!map)
        map = ((void **)param)[0];
    if (!rows)
        rows = (int)(size_t)((void **)param)[1];
    if (!cols)
        cols = (int)(size_t)((void **)param)[2];
    if (!game_status)
        game_status = ((void **)param)[3];
    if (!mlx)
        mlx = ((void **)param)[4];
    if (!mlx_win)
        mlx_win = ((void **)param)[5];

    if (keycode == 53) {
        printf("Exiting the game.\n");
        exit(0);
    }

    char direction = '\0';
    if (keycode == 122)
        direction = 'W';
    if (keycode == 115)
        direction = 'S';
    if (keycode == 113)
        direction = 'A';
    if (keycode == 100)
        direction = 'D';

    if (direction != '0') {
        int move_result = move_player(map, rows, cols, direction);
        if (move_result == 1) {
            printf("Player moved!\n");
            print_map(map, rows, cols);
            mlx_clear_window(mlx, mlx_win);
            draw_map(mlx, mlx_win, map, rows, cols);
        } else {
            printf("Invalid move\n");
        }
    }

    return 0;
}

