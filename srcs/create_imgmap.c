/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_imgmap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsomrat <lsomrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 23:22:09 by lsomrat           #+#    #+#             */
/*   Updated: 2022/12/08 23:22:33 by lsomrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_floor(t_data *data, t_image image)
{
	int			x;
	int			y;

	y = 0;
	data->floor = NULL;
	while (y < data->map.height)
	{
		x = 0;
		while (x < data->map.width)
		{
			if (data->map.grid[y][x])
				init_floor(data, x, y, image);
			x++;
		}
		y++;
	}
}

void	create_wall(t_data *data, t_image image)
{
	int			x;
	int			y;
	t_pix		*content;
	t_list		*new_data;

	y = 0;
	data->wall = NULL;
	while (y < data->map.height)
	{
		x = 0;
		while (x < data->map.width)
		{
			if (data->map.grid[y][x])
			{
				if (data->map.grid[y][x] == '1')
					init_wall(data, x, y, image);
			}
			x++;
		}
		y++;
	}
}

void	create_item(t_data *data, t_image image)
{
	int			x;
	int			y;
	t_pix		*content;
	t_list		*new_data;

	y = 0;
	data->item = NULL;
	while (y < data->map.height)
	{
		x = 0;
		while (x < data->map.width)
		{
			if (data->map.grid[y][x])
			{
				if (data->map.grid[y][x] == 'C')
					init_item(data, x, y, image);
			}
			x++;
		}
		y++;
	}
}

void	create_player(t_data *data, t_image image)
{
	int			x;
	int			y;

	y = 0;
	while (y < data->map.height)
	{
		x = 0;
		while (x < data->map.width)
		{
			if (data->map.grid[y][x])
			{
				if (data->map.grid[y][x] == 'P')
					init_player(data, x, y, image);
			}
			x++;
		}
		y++;
	}
}

void	create_exit(t_data *data, t_image image)
{
	int			x;
	int			y;

	y = 0;
	while (y < data->map.height)
	{
		x = 0;
		while (x < data->map.width)
		{
			if (data->map.grid[y][x])
			{
				if (data->map.grid[y][x] == 'E')
				{
					data->e.addr = "images/door.xpm";
					data->e.v.x = x;
					data->e.v.y = y;
					data->e.img.ptr = mlx_xpm_file_to_image(data->mlx,
							data->e.addr, &image.w, &image.h);
				}
			}
			x++;
		}
		y++;
	}
}
