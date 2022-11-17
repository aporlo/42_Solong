#include "so_long.h"

static int  linecount(char *file)
{
    int     line;
    int     fd;
    int     readcount;
    char    str;

    fd = open(file, O_RDONLY);
    if (!fd)
        return (-1);
    line = 1;
    while (fd)
    {
        readcount = read(fd, &str, 1);
        if (readcount == 0)
            break;
        if (readcount < 0)
            return (-1);
        if (str == '\n')
            line++;
    }
    printf("line is %d\n", line);
    printf("fd1 is %d\n", fd);
    close(fd);
    return (line);
}

static char **alloc_columns(char *file)
{
    char    **map;
    int         line_num;
    line_num = linecount(file);
    if (line_num < 0)
        error_file("Error\n the file not be exist");
    map = malloc(sizeof(char *) * line_num + 1);
    if (map == NULL)
        error_file("Error\n malloc error on map");
    return (map);
}

char **read_map(char *file)
{
    // char    **map;
    int     fd;
    int     i;

    // map = alloc_columns(file);
    // if (map == NULL)
    //     return (NULL);
    if (check_fextension(file))
        error_file("Error\n file extention not .ber");
    fd = open(file, O_RDONLY);
    if (fd < 0)
    
    i = linecount(file);
    printf("fd is %d", fd);
    
    // i = 0;
    // *map = get_next_line(fd);
    // while (*map != NULL)
    // {
        
    // }
}