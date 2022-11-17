#include "so_long.h"


int main(int argc, char **argv)
{
    char    **map;
    if (argc == 1)
        error_file("Error\n no args");
    if (argc == 2)
        map =  read_map(argv[1]);
    if (!map)
        return (NULL);
    
}