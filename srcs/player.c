/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsomrat <lsomrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 20:51:07 by lsomrat           #+#    #+#             */
/*   Updated: 2022/12/25 20:51:11 by lsomrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	moved(t_data *data, char vector, int direct);
static void	walk(t_data *data, int direction);
static void	get_item(t_data *data);

void	movement(t_data *data, int direction)
{
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
		moved(data, 'x', -1);
	if (direction == DIR_RIGHT && (data->map.grid[y][x + 1] != '1'))
		moved(data, 'x', 1);
	if (direction == DIR_UP && (data->map.grid[y - 1][x] != '1'))
		moved(data, 'y', -1);
	if (direction == DIR_DOWN && (data->map.grid[y + 1][x] != '1'))
		moved(data, 'y', 1);
}

static void	moved(t_data *data, char vector, int direct)
{
	if (vector == 'x')
	{
		data->p.v.x += 1 * direct;
		data->p.moved += 1;
	}
	else if (vector == 'y')
	{
		data->p.v.y += 1 * direct;
		data->p.moved += 1;
	}
	printf("moved is%d\n", data->p.moved);
}

static void	get_item(t_data *data)
{
	int		x;
	int		y;
	t_list	*temp;

	x = data->p.v.x;
	y = data->p.v.y;
	temp = data->item;
	if (data->map.grid[y][x] == 'C')
	{
		while (temp != NULL)
		{
			if (x == ((t_pix *)temp->content)->v.x
				&& y == ((t_pix *)temp->content)->v.y
				&& ((t_pix *)temp->content)->is_show == 1)
			{
				((t_pix *)temp->content)->is_show = 0;
				data->p.item++;
			}
			temp = temp->next;
		}
	}
}
