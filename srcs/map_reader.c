/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsomrat <lsomrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 20:56:51 by lsomrat           #+#    #+#             */
/*   Updated: 2022/12/28 16:22:06 by lsomrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	get_grid(int i, int j, char **grid, char *filedata);

static char	*get_filedata(char **data, char *file)
{
	char	*str;
	char	*temp;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_file("Error\n file not found");
	*data = ft_calloc(1, sizeof(char *));
	while (1)
	{
		temp = get_next_line(fd);
		if (!temp)
			break ;
		str = *data;
		*data = ft_strjoin(str, temp);
		free(temp);
		free(str);
	}
	close(fd);
	return (*data);
}

void	print_grid(t_map mapdata)
{
	int	i;
	int	j;

	i = 0;
	while (i < mapdata.height)
	{
		j = 0;
		while (j < mapdata.width)
		{
			ft_printf("%c", mapdata.grid[i][j]);
			j++;
		}
		ft_printf("%c", '\n');
		j = 0;
		i++;
	}
}

char	**creategrid(t_map mapdata, char *filedata)
{
	int		i;
	int		j;
	char	**grid;

	grid = malloc(sizeof(char *) * mapdata.height);
	i = 0;
	while (i < mapdata.height)
	{
		grid[i] = malloc(sizeof(char) * (mapdata.width));
		j = 0;
		while (j < mapdata.width)
		{
			get_grid(i, j++, grid, filedata++);
			if (*filedata == '\n')
			{
				filedata += 1;
				break ;
			}
			if (*filedata == '\0')
				break ;
		}
		i++;
	}
	return (grid);
}

static void	get_grid(int i, int j, char **grid, char *filedata)
{
	grid[i][j] = *filedata;
}

void	read_map(t_data *data, char *file)
{
	int		fd;
	char	*str;
	char	*filedata;

	if (check_fextension(file))
		error_file("Error\n file extention not .ber");
	get_filedata(&data->filedata, file);
	set_mapdata(data);
}
