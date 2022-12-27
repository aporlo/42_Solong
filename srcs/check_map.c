/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsomrat <lsomrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 20:42:53 by lsomrat           #+#    #+#             */
/*   Updated: 2022/12/27 20:50:53 by lsomrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	linecount(char *file)
{
	int	line;

	line = 1;
	while (*file)
	{
		if (*file == '\n')
			line++;
		file++;
	}
	return (line);
}

size_t	ft_strlenn(const char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (len);
	while (s[len] != '\n')
		len++;
	return (len);
}

void	validate_map(t_data *data)
{
	check_path(data);
	if (check_charactor(*data) < 0)
		error_file("Error\n The map can be composed of only these 01CEP\n");
	if (data->map.e != 1 || data->map.p != 1)
		error_file("Error\n The map contain 1 exit and 1 starting position\n");
	if (data->map.c < 1)
		error_file("Error\n The map contain  at least 1 collectible\n");
	if (check_rec(*data) < 0)
		error_file("Error\n The map must be rectangular\n");
	if (check_wall(data->map) < 0)
		error_file("Error\n The map must be closed/surrounded by walls\n");
}

void	set_mapdata(t_data *data)
{
	data->map.c = 0;
	data->map.e = 0;
	data->map.p = 0;
	data->map.height = linecount(data->filedata);
	data->map.width = ft_strlenn(data->filedata);
	data->map.grid = creategrid(data->map, data->filedata);
	validate_map(data);
}


