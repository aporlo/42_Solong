/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsomrat <lsomrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 17:59:03 by lsomrat           #+#    #+#             */
/*   Updated: 2022/12/31 17:59:07 by lsomrat          ###   ########.fr       */
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

void	init_p(t_data *data, int i, int j)
{
	data->p.v.y = i;
	data->p.v.x = j;
	data->map.p++;
}

int	fill(t_map map, int x, int y, char to_fill)
{
	static int	door = 0;

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
