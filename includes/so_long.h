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
#  define DIR_LEFT          0
#  define DIR_RIGHT         1
#  define DIR_UP            2
#  define DIR_DOWN          3

typedef struct s_vector
{
    int     x;
    int     y;
}   t_vector;

typedef struct s_image
{
    void	*ptr;
    int     w;
    int     h;
	int		bpp;
	int		line;
	int		endian;
}   t_image;


typedef struct s_pix
{
    int             is_show;
    char	        *addr;
    t_vector        v;
    t_image         img;
    struct s_pix    *next;
}   t_pix;


typedef struct s_map
{
    char    **grid;
    int     width;
    int     height;
    int     P;
    int     C;
    int     E;
}   t_map;

typedef struct s_player
{
    char	    *addr;
    t_image     img;
    t_vector    v;
    int         moved;
    int         item;
}   t_player;

typedef struct s_data
{
    t_map       map;
    char        *filedata;
    void	    *mlx;
	void	    *mlx_win;
    t_player    p;
    t_player    e;
    t_list      *wall;
    t_list      *floor;
    t_list      *item;
}   t_data;

void    error_line(char *msg, char *line);
void    error_file(char *msg);
size_t  ft_strlenn(const char *s);
void	*delete_node(t_pix *content);

void    read_map(t_data *data, char *file);
int     check_fextension(char *file);
void    validate_map(t_data *data);
void    render_one(t_data *data, t_player *obj);
void    render_multi(t_data *data, t_list *obj);
void    render_all(t_data *data);
void    print_grid(t_map mapdata);
void    create_wall(t_data *data, t_image image);
void    create_floor(t_data *data, t_image image);
void    create_item(t_data *data, t_image image);
void    create_player(t_data *data, t_image image);
void    create_exit(t_data *data, t_image image);

#endif