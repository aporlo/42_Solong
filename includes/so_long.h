#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft.h"
# include "get_next_line.h"
# include "mlx.h"
# include "ft_printf.h"

typedef struct s_vector
{
    int     x;
    int     y;
}   t_vector;

typedef struct s_checkmap
{
    t_vector    size;
    t_vector    point;
}   t_checkmap;

typedef struct s_datamap
{
    char    **map;
}   t_datamap;

void    error_line(char *msg, char *line);
void    error_file(char *msg);

char    **read_map(char *file);
int     check_fextension(char *file);

#endif