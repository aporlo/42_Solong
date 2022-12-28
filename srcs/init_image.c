/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsomrat <lsomrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 09:33:15 by lsomrat           #+#    #+#             */
/*   Updated: 2022/12/26 09:33:16 by lsomrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_floor(t_data *data, int x, int y, t_image image)
{
	t_pix		*content;
	t_list		*new_data;

	content = malloc(sizeof(t_pix));
	content->is_show = 1;
	content->v.x = x;
	content->v.y = y;
	content->img.ptr = mlx_xpm_file_to_image(data->mlx,
			"images/floor.xpm", &image.w, &image.h);
	new_data = ft_lstnew(content);
	ft_lstadd_back(&data->floor, new_data);
}

void	init_wall(t_data *data, int x, int y, t_image image)
{
	t_pix		*content;
	t_list		*new_data;

	content = malloc(sizeof(t_pix));
	content->is_show = 1;
	content->v.x = x;
	content->v.y = y;
	content->img.ptr = mlx_xpm_file_to_image(data->mlx,
			"images/wall.xpm", &image.w, &image.h);
	new_data = ft_lstnew(content);
	ft_lstadd_back(&data->wall, new_data);
}

void	init_item(t_data *data, int x, int y, t_image image)
{
	t_pix		*content;
	t_list		*new_data;

	content = malloc(sizeof(t_pix));
	content->is_show = 1;
	content->v.x = x;
	content->v.y = y;
	content->img.ptr = mlx_xpm_file_to_image(data->mlx,
			"images/carrot01.xpm", &image.w, &image.h);
	new_data = ft_lstnew(content);
	ft_lstadd_back(&data->item, new_data);
}

void	init_player(t_data *data, int x, int y, t_image image)
{
	data->p.addr = "images/01-player.xpm";
	data->p.v.x = x;
	data->p.v.y = y;
	data->p.item = 0;
	data->p.moved = 0;
	data->p.img.ptr = mlx_xpm_file_to_image(data->mlx,
			data->p.addr, &image.w, &image.h);
}

