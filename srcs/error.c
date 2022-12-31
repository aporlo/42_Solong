/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsomrat <lsomrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 23:24:21 by lsomrat           #+#    #+#             */
/*   Updated: 2022/12/08 23:26:34 by lsomrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	error_line(char *msg, char *line)
{
	ft_putstr_fd(msg, STDERR_FILENO);
	free(line);
	exit(EXIT_FAILURE);
}

void	error_file(char *msg)
{
	ft_putstr_fd(msg, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	free_pix(t_data *data, t_list *obj)
{
	t_list	*temp;

	temp = obj;
	while (temp != NULL)
	{
		if (data->mlx)
			mlx_destroy_image(data->mlx, ((t_pix *)temp->content)->img.ptr);
		temp = temp->next;
	}
	ft_lstclear(&obj, &delete_node);
}

void	free_map(t_data *data)
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

void	delete_node(void *content)
{
	free(content);
}
