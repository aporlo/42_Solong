/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsomrat <lsomrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 20:52:47 by lsomrat           #+#    #+#             */
/*   Updated: 2022/12/27 20:55:52 by lsomrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_one(t_data *data, t_player *obj)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win, obj->img.ptr, obj->v.x*PIXEL, obj->v.y*PIXEL);
}

void	render_multi(t_data *data, t_list *obj)
{
	t_pix	*temp;
	
	while (obj != NULL)
	{
		temp = (t_pix *)obj->content;
		mlx_put_image_to_window(data->mlx, data->mlx_win, temp->img.ptr, temp->v.x*PIXEL, temp->v.y*PIXEL);
		obj = obj->next;
	}
}

void	render_item(t_data *data, t_list *obj)
{
	t_pix	*temp;
	
	while (obj != NULL)
    {
		temp = (t_pix *)obj->content;
		if (temp->is_show == 1)
			mlx_put_image_to_window(data->mlx, data->mlx_win, temp->img.ptr, temp->v.x*PIXEL, temp->v.y*PIXEL);
		obj = obj->next;
	}
}
void	render_all(t_data *data)
{
	t_player	p;
	t_player	e;
    t_list		*f;
    t_list		*w;
    t_list		*c;

	p = data->p;
	e = data->e;
	c = data->item;
	f = data->floor;
	w = data->wall;

	render_multi(data, f);
	render_multi(data, w);
	render_item(data, c);
	render_one(data, &e);
	render_one(data, &p);
}
