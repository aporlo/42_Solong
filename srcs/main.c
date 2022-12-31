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

static int	close_window(int keycode, t_data *data)
{
	exit (0);
}

int	main(int argc, char **argv)
{
	char	**mapfile;
	t_data	data;
	t_image	img;

	if (argc != 2)
		error_file("Error\n");
	if (argc == 2)
	{
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
		mlx_loop_hook(data.mlx, &render_all, &data);
		mlx_hook(data.mlx_win, 2, 1L << 0, &keyhandler, &data);
		mlx_hook(data.mlx_win, 17, 1L << 0, &close_window, &data);
		mlx_loop(data.mlx);
	}
	return (0);
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
	return (0);
}
