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

void	print_linklist(t_list *profile);

void	create_floor(t_data *data, t_image image)
{
	int			x;
	int			y;
	t_pix		*content;
	t_list		*new_data;

	y = 0;
	data->floor = NULL;
	while (y < data->map.height)
	{
		x = 0;
		while (x < data->map.width)
		{
			if (data->map.grid[y][x])
			{
				content = malloc(sizeof(t_pix));
				content->is_show = 1;
				content->v.x = x;
				content->v.y = y;
				content->img.ptr = mlx_xpm_file_to_image(data->mlx,
						"images/floor.xpm", &image.w, &image.h);
				new_data = ft_lstnew(content);
				ft_lstadd_back(&data->floor, new_data);
			}
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
				{
					content = malloc(sizeof(t_pix));
					content->is_show = 1;
					content->v.x = x;
					content->v.y = y;
					content->img.ptr = mlx_xpm_file_to_image(data->mlx,
							"images/wall.xpm", &image.w, &image.h);
					new_data = ft_lstnew(content);
					ft_lstadd_back(&data->wall, new_data);
				}
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
	printf("C%d\n", data->map.C);
	while (y < data->map.height)
	{
		x = 0;
		while (x < data->map.width)
		{
			if (data->map.grid[y][x])
			{
				if (data->map.grid[y][x] == 'C')
				{
					content = malloc(sizeof(t_pix));
					content->is_show = 1;
					content->v.x = x;
					content->v.y = y;
					content->img.ptr = mlx_xpm_file_to_image(data->mlx,
							"images/carrot01.xpm", &image.w, &image.h);
					new_data = ft_lstnew(content);
					ft_lstadd_back(&data->item, new_data);
				}
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
				{
					data->p.addr = "images/01-player.xpm";
					data->p.v.x = x;
					data->p.v.y = y;
					data->p.item = 0;
					data->p.moved = 0;
					data->p.img.ptr = mlx_xpm_file_to_image(data->mlx,
							"images/01-player.xpm", &image.w, &image.h);
				}
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

void	print_linklist(t_list *profile)
{
	t_pix	*temp;

	while (profile != NULL)
	{
		temp = (t_pix *)profile->content;
		printf("vector x is %d ,", temp->v.x);
		printf(" %d\n", temp->v.y);
		printf("show is%d\n", temp->is_show);
		profile = profile->next;
	}
	printf("NULL\n");
}
