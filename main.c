#include "so_long.h"

void init_game(t_game *game) {
    game->mlx = NULL;
    game->mlx_win = NULL;
    game->map = NULL;
    game->rows = 0;
    game->cols = 0;
    game->player_row = -1;
    game->player_col = -1;
    game->collected_items = 0;
    game->total_collectables = 0;
    game->movements = 0;
}

/* Main function to start the game */
int main(int argc, char **argv) {
    t_game game;

    if (argc != 2) {
        write(2, "Error\nInvalid number of arguments\n", 35);
        return (1);
    }
    
    init_game(&game);
    read_map_size(&game, argv[1]);
    allocate_map(&game, argv[1]);
    validate_map(&game);
    process_map(&game);
    init_mlx(&game);
    draw_map(&game);

    mlx_loop(game.mlx);
    return (0);
}
