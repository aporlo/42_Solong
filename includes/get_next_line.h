/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsomrat <lsomrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 23:02:12 by lsomrat           #+#    #+#             */
/*   Updated: 2022/12/28 16:43:04 by lsomrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include<sys/types.h>
# include<sys/stat.h>

# define BUFFER_SIZE 1000

typedef struct s_gnllist
{
	char				*content;
	struct s_gnllist	*next;
}	t_gnllist;

char		*get_next_line(int fd);
char		*read_file(int fd, t_gnllist **buff);
char		*get_line(t_gnllist *buff, char **line);
void		save_readed(t_gnllist **buff, char *buf, int readed);
void		generate_line(char **line, t_gnllist *buff);
void		clear_buff(t_gnllist **buff);
void		free_buff(t_gnllist *buff);
int			get_newline(t_gnllist *buff);
size_t		ft_strlen(const char *s);
t_gnllist	*get_last(t_gnllist *buff);
#endif
