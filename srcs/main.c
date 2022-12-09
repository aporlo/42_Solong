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
static int keyhandler(int  keycode, t_data *data);

static int	close_window(int keycode, t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	return (0);
}

int	main(int argc, char **argv)
{
	char   **mapfile;
	t_data  data;
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
	mlx_hook(data.mlx_win, 2, 1L << 0, &keyhandler, &data);
	mlx_hook(data.mlx_win, 17, 1L<<0, close_window, &data);
	mlx_loop(data.mlx);
}

static int	keyhandler(int  keycode, t_data *data)
{
    // printf("keycode%d\n", keycode);
	if (keycode == KEY_LEFT || keycode == KEY_A)
		ft_printf("left%d\n", keycode);
	if (keycode == KEY_RIGHT || keycode == KEY_D)
		ft_printf("right%d\n", keycode);
	if (keycode == KEY_DOWN || keycode == KEY_S)
		ft_printf("down%d\n", keycode);
	if (keycode == KEY_UP || keycode == KEY_W)
		ft_printf("up%d\n", keycode);
	if (keycode == KEY_ESC)
		ft_printf("exit%d\n", KEY_ESC);
}
