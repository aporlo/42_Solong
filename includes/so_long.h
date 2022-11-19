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

typedef struct s_map
{
    char    **grid;
    int     width;
    int     hight;
    int     P;
    int     C;
    int     E;

}   t_map;

typedef struct s_data
{
    t_map     map;
    char        *filedata;
}   t_data;

void    error_line(char *msg, char *line);
void    error_file(char *msg);

char   **read_map(t_data data, char *file);
int     check_fextension(char *file);
void    validate_map(t_data data);
void    print_grid(t_map mapdata);
size_t  ft_strlenn(const char *s);
#endif