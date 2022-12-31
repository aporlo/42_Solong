/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsomrat <lsomrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 14:46:08 by lsomrat           #+#    #+#             */
/*   Updated: 2022/12/28 16:33:06 by lsomrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_fextension(char *file)
{
	int		len;
	char	*str;

	len = ft_strlen(file);
	if (len < 4)
		return (0);
	str = file + (len - 4);
	if (!ft_strncmp(".ber", str, 4))
		return (0);
	return (1);
}

int	check_charactor(t_data data)
{
	int	i;

	i = 0;
	while (data.filedata[i])
	{
		if (data.filedata[i] != '\n')
		{
			if (ft_strchr("01CEP", data.filedata[i]) == NULL
				|| ft_strchr(data.filedata, '0') == NULL)
				return (-1);
		}
		i++;
	}
	return (0);
}

int	check_rec(t_data data)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (data.filedata[i])
	{
		if (data.filedata[i] == '\n')
		{
			if (len != data.map.width)
				return (-1);
			len = 0;
		}
		else
			len++;
		i++;
	}
	return (0);
}

int	check_wall(t_map mapdata)
{
	int	i;
	int	j;

	i = 0;
	while (i < mapdata.height)
	{
		if (mapdata.grid[i][0] != '1'
				|| mapdata.grid[i][mapdata.width - 1] != '1')
			return (-1);
		i++;
	}
	j = 0;
	while (j < mapdata.width)
	{
		if (mapdata.grid[0][j] != '1'
				|| mapdata.grid[mapdata.height - 1][j] != '1')
			return (-1);
		j++;
	}
	return (0);
}

void	check_path(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map.height)
	{
		j = 0;
		while (j < data->map.width)
		{
			if (data->map.grid[i][j])
			{
				if (data->map.grid[i][j] == 'P')
				{
					data->p.v.y = i;
					data->p.v.x = j;
					data->map.p++;
				}
				if (data->map.grid[i][j] == 'C')
					data->map.c++;
				if (data->map.grid[i][j] == 'E')
					data->map.e++;
			}
			j++;
		}
		j = 0;
		i++;
	}
}
