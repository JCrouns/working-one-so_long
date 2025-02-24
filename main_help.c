#include "so_long.h"

int check_argc(int c)
{
    if(c != 2)
    {
        write(2 , "error : Number of args not on point\n" , 36);
        exit(1);
    }
}

int open_file(char *file_name)
{
    int fd = open(file_name , O_RDONLY);
    if(fd < 0)
    {
        write(2 , "error : error on opining file\n" , 30);
        exit(1);
    }
}

