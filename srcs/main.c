/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsomrat <lsomrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 23:27:51 by lsomrat           #+#    #+#             */
/*   Updated: 2022/12/08 23:31:10 by lsomrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
static int	keyhandler(int keycode, t_data *data);
static void	movement(t_data *data, int direction);
static void	walk(t_data *data, int direction);
static void	get_item(t_data *data);
static void	game_exit(t_data *data, int key);
static void	free_pix(t_data *data, t_list *obj);
static void	free_map(t_data *data);

static int	close_window(int keycode, t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	return (0);
}

int	main(int argc, char **argv)
{
	char	**mapfile;
	t_data	data;
	t_image	img;

	if (argc == 1)
		error_file("Error\n no args");
	if (argc == 2)
		read_map(&data, argv[1]);
	img.h = data.map.height * PIXEL;
	img.w = data.map.width * PIXEL;
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, img.w, img.h, "So_long");
	create_floor(&data, img);
	create_wall(&data, img);
	create_item(&data, img);
	create_player(&data, img);
	create_exit(&data, img);
	mlx_loop_hook(data.mlx, render_all, &data);
	mlx_hook(data.mlx_win, 2, 1L << 0, &keyhandler, &data);
	mlx_hook(data.mlx_win, 17, 1L<<0, close_window, &data);
	mlx_loop(data.mlx);
}

static int	keyhandler(int keycode, t_data *data)
{
	int	x;
	int	y;

	x = data->p.v.x;
	y = data->p.v.y;
	if (keycode == KEY_LEFT || keycode == KEY_A)
		movement(data, DIR_LEFT);
	if (keycode == KEY_RIGHT || keycode == KEY_D)
		movement(data, DIR_RIGHT);
	if (keycode == KEY_DOWN || keycode == KEY_S)
		movement(data, DIR_DOWN);
	if (keycode == KEY_UP || keycode == KEY_W)
		movement(data, DIR_UP);	
	if (keycode == KEY_ESC)
		game_exit(data, KEY_ESC);
}

static void	movement(t_data *data, int direction)
{
	int		x;
	int		y;

	walk(data, direction);
	get_item(data);
	game_exit(data, 1);
} 

static void	walk(t_data *data, int direction)
{
	int		x;
	int		y;

	x = data->p.v.x;
	y = data->p.v.y;
	if (direction == DIR_LEFT && (data->map.grid[y][x - 1] != '1'))
	{
		data->p.v.x -= 1;
		data->p.moved += 1;
	}
	if (direction == DIR_RIGHT && (data->map.grid[y][x + 1] != '1'))
	{
		data->p.v.x += 1;
		data->p.moved += 1;
	}
	if (direction == DIR_UP && (data->map.grid[y - 1][x] != '1'))
	{
		data->p.v.y -= 1;
		data->p.moved += 1;
	}
	if (direction == DIR_DOWN && (data->map.grid[y + 1][x] != '1'))
	{
		data->p.v.y += 1;
		data->p.moved += 1;
	}
	// printf("moved is%d\n", data->p.moved);
}

static void	get_item(t_data *data)
{
	int	x;
	int y;
	t_list	*temp;

	x = data->p.v.x;
	y = data->p.v.y;
	temp = data->item;
	if(data->map.grid[y][x] == 'C')
	{
		while(temp != NULL)
		{
			if(x == ((t_pix *)temp->content)->v.x &&
			y == ((t_pix *)temp->content)->v.y &&
			((t_pix *)temp->content)->is_show == 1)
			{
				((t_pix *)temp->content)->is_show = 0;
				data->p.item++;
				// printf("item%d\n", data->p.item);
			}
			temp = temp->next;
		}
	}	
}

static void	game_exit(t_data *data, int key)
{
	int	x;
	int y;

	x = data->p.v.x;
	y = data->p.v.y;
	if((data->map.grid[y][x] == 'E' && data->p.item == data->map.C) ||
		key == KEY_ESC)
	{
		free_pix(data, data->item);
		free_pix(data, data->wall);
		free_pix(data, data->floor);
		mlx_destroy_image(data->mlx, data->p.img.ptr);
		mlx_destroy_image(data->mlx, data->e.img.ptr);
		// if (data->map.grid)
		// 	free(data->map.grid);
		free_map(data);
		printf("hello\n");
		free(data->filedata);
		printf("data%c\n", data->filedata);
		printf("hello\n");
		mlx_destroy_window(data->mlx, data->mlx_win);
		exit(0);
	}
}

static void	free_pix(t_data *data, t_list *obj)
{
	t_list	*temp;

	temp = obj;
	while (temp != NULL)
	{
		if (data->mlx)
			mlx_destroy_image(data->mlx, ((t_pix *)temp->content)->img.ptr);
		temp = temp->next;
	}
	ft_lstclear(&obj, delete_node);
}

static void	free_map(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->map.height)
	{
		free(data->map.grid[y]);
		y++;
	}
	free(data->map.grid);
}