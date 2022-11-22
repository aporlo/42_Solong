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

#define PIXEL   32
typedef struct s_vector
{
    int     x;
    int     y;
}   t_vector;

typedef struct s_map
{
    char    **grid;
    int     width;
    int     height;
    int     P;
    int     C;
    int     E;

}   t_map;

typedef struct s_image
{
    void	*img;
	char	*addr;
    int     w;
    int     h;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}   t_image;


typedef struct s_data
{
    t_map   map;
    char    *filedata;
    void	*mlx;
	void	*mlx_win;
}   t_data;

void    error_line(char *msg, char *line);
void    error_file(char *msg);
size_t  ft_strlenn(const char *s);

void    read_map(t_data *data, char *file);
int     check_fextension(char *file);
void    validate_map(t_data data);
void    print_grid(t_map mapdata);
void    create_wall(t_data *data, t_image image);
void    create_floor(t_data *data, t_image image);
void    create_item(t_data *data, t_image image);
void    create_tree(t_data *data, t_image image);

#endif