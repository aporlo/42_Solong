/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsomrat <lsomrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 09:57:36 by lsomrat           #+#    #+#             */
/*   Updated: 2022/12/26 14:42:22 by lsomrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

# define PIXEL  	32
# define KEY_CTRL	256
# define KEY_ENTER	36
# define KEY_SPACE	49
# define KEY_ESC	53
# define KEY_LEFT	123
# define KEY_RIGHT	124
# define KEY_UP		126
# define KEY_DOWN	125
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2
# define KEY_W		13
# define DIR_LEFT	0
# define DIR_RIGHT	1
# define DIR_UP 	2
# define DIR_DOWN	3

typedef struct s_vector
{
	int		x;
	int		y;
}	t_vector;

typedef struct s_image
{
	void	*ptr;
	int		w;
	int		h;
	int		bpp;
	int		line;
	int		endian;
}	t_image;

typedef struct s_pix
{
	int				is_show;
	char			*addr;
	t_vector		v;
	t_image			img;
	struct s_pix	*next;
}	t_pix;

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	int		p;
	int		c;
	int		e;
}	t_map;

typedef struct s_player
{
	char		*addr;
	t_image		img;
	t_vector	v;
	int			moved;
	int			item;
}	t_player;

typedef struct s_data
{
	t_map		map;
	char		*filedata;
	void		*mlx;
	void		*mlx_win;
	t_player	p;
	t_player	e;
	t_list		*wall;
	t_list		*floor;
	t_list		*item;
}	t_data;
void	error_line(char *msg, char *line);
void	error_file(char *msg);
size_t	ft_strlenn(const char *s);
int		linecount(char *file);
void	free_pix(t_data *data, t_list *obj);
void	free_map(t_data *data);
void	delete_node(void *content);

void	read_map(t_data *data, char *file);
void	set_mapdata(t_data *data);
char	**creategrid(t_map mapdata, char *filedata);
int		check_fextension(char *file);
int		check_charactor(t_data data);
int		check_wall(t_map mapdata);
int		check_rec(t_data data);
int		fill(t_map map, int x, int y, char to_fill);
void	init_p(t_data *data, int i, int j);
void	check_path(t_data *data);
void	validate_map(t_data *data);
void	render_one(t_data *data, t_player *obj);
void	render_multi(t_data *data, t_list *obj);
int		render_all(t_data *data);
void	print_grid(t_map mapdata);
void	init_floor(t_data *data, int x, int y, t_image image);
void	init_wall(t_data *data, int x, int y, t_image image);
void	init_item(t_data *data, int x, int y, t_image image);
void	init_player(t_data *data, int x, int y, t_image image);
void	create_wall(t_data *data, t_image image);
void	create_floor(t_data *data, t_image image);
void	create_item(t_data *data, t_image image);
void	create_player(t_data *data, t_image image);
void	create_exit(t_data *data, t_image image);
void	movement(t_data *data, int direction);
void	game_exit(t_data *data, int key);

#endif
