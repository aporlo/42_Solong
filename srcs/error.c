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

void	*delete_node(t_pix *content)
{
	free(content);
}