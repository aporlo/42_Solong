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

#  define PIXEL             32
#  define KEY_CTRL			256
#  define KEY_ENTER			36
#  define KEY_SPACE			49
#  define KEY_ESC			53
#  define KEY_LEFT			123
#  define KEY_RIGHT			124
#  define KEY_UP			126
#  define KEY_DOWN			125
#  define KEY_A				0
#  define KEY_S				1
#  define KEY_D				2
#  define KEY_W				13

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
	int		bpp;
	int		line;
	int		endian;
    t_vector    v;
}   t_image;

typedef struct s_player
{
    t_image    img;
}   t_player;

typedef struct s_data
{
    t_map       map;
    char        *filedata;
    void	    *mlx;
	void	    *mlx_win;
    t_player    p;
    t_image     *wall;
    t_image     *floor;
    t_image     *item;
    t_image     *door;
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
void    create_player(t_data *data, t_image image);
void    create_exit(t_data *data, t_image image);

#endif