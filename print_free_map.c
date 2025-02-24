#include "so_long.h"

void free_map(char **map, int rows)
{
    int r = 0;
    while (r < rows)
    {
        free(map[r]);
        r++;
    }
    free(map);
}

void print_map(char **tab, int rows, int cols)
{
    int r = 0;
    while (r < rows)
    {
        printf("%s\n", tab[r]);
        r++;
    }
   // printf("Collected Items: %d/%d\n", collected_items, total_collectables);
}

