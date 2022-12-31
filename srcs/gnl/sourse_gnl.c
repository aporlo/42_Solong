/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sourse_gnl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsomrat <lsomrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 20:10:39 by lsomrat           #+#    #+#             */
/*   Updated: 2022/12/31 20:11:23 by lsomrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
include "get_next_line.h"

void	free_buff(t_gnllist *buff)
{
	t_gnllist	*current;
	t_gnllist	*next;

	current = buff;
	while (current)
	{
		free(current->content);
		next = current->next;
		free(current);
		current = next;
	}
}
