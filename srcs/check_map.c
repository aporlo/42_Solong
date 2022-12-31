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

static int	fill(t_map map, int x, int y, char to_fill)
{
	static int door = 0;

	if (map.grid[y][x] == to_fill)
		door = 1;
	map.grid[y][x] = '1';
	if (map.grid[y][x - 1] != '1' && door == 0)
		fill(map, (x - 1), y, to_fill);
	if (map.grid[y][x + 1] != '1' && door == 0)
		fill(map, (x + 1), y, to_fill);
	if (map.grid[y - 1][x] != '1' && door == 0)
		fill(map, x, (y - 1), to_fill);
	if (map.grid[y + 1][x] != '1' && door == 0)
		fill(map, x, (y + 1), to_fill);
	return (door);
}

static int	check_validpath(t_data *data)
{
	int		x;
	int		y;
	int		i;
	t_image	image;
	t_data	copydata;

	i = 0;
	copydata.map.grid = malloc(sizeof(char **) * data->map.height);
	while(i < data->map.height)
	{
		copydata.map.grid[i] = ft_strdup(data->map.grid[i]);
		i++;
	}	
	x = data->p.v.x;
	y = data->p.v.y;
	copydata.map.height = data->map.height;
	if (fill(copydata.map, x, y, 'E') > 0)
	{
		free_map(&copydata);
		return (1);
	}
	free_map(&copydata);
	return (0);
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
	if (check_validpath(data) == 0)
		error_file("Error\n The map not valid path\n");
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
