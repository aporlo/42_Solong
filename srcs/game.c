/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsomrat <lsomrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 21:17:00 by lsomrat           #+#    #+#             */
/*   Updated: 2022/12/25 21:17:01 by lsomrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	game_exit(t_data *data, int key)
{
	int	x;
	int	y;

	x = data->p.v.x;
	y = data->p.v.y;
	if ((data->map.grid[y][x] == 'E' && data->p.item == data->map.c)
		|| key == KEY_ESC)
	{
		free_pix(data, data->item);
		free_pix(data, data->wall);
		free_pix(data, data->floor);
		mlx_destroy_image(data->mlx, data->p.img.ptr);
		mlx_destroy_image(data->mlx, data->e.img.ptr);
		free_map(data);
		free(data->filedata);
		mlx_destroy_window(data->mlx, data->mlx_win);
		exit(0);
	}
}
