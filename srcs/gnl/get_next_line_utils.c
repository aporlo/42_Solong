/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsomrat <lsomrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 23:28:59 by lsomrat           #+#    #+#             */
/*   Updated: 2022/04/06 14:09:56 by lsomrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t  ft_strlen(const char *s)
{
    size_t  i;

    i = 0;
    while (s[i] != '\0')
        i++;
    return (i);
}

void    save_readed(t_gnllist **buff, char *buf, int readed)
{
    int         i;
    t_gnllist  *last;
    t_gnllist  *new;

    new = malloc(sizeof(t_gnllist));
    if (!new)
        return;
    new->next = NULL;
    new->content = malloc(sizeof(char) * (readed + 1));
    if (new->content == NULL)
        return;
    i = 0;
    while (buf[i] && i < readed)
    {
        new->content[i] = buf[i];
        i++;
    }
    new->content[i] = '\0';
    if (*buff == NULL)
    {
        *buff = new;
        return;
    }
    last = get_last(*buff);
    last->next = new;
} 

int get_newline(t_gnllist *buff)
{
    int				i;
    t_gnllist  *current;

    if (buff == NULL)
        return (0);
    current = get_last(buff);
    i = 0;
    while (current->content[i])
    {
        if (current->content[i] == '\n')
            return (1);
        i++;
    }
    return (0);
}

void    generate_line(char **line, t_gnllist *buff)
{
    int i;
    int len;

    len = 0;
    while (buff)
    {
        i = 0;
        while (buff->content[i])
        {
            if (buff->content[i] == '\n')
            {
                len++;
                break;
            }
            len++;
            i++;
        }
        buff = buff->next;
    }
    *line = malloc(sizeof(char) * (len + 1));
}

t_gnllist  *get_last(t_gnllist *buff)
{
    t_gnllist  *current;

    current = buff;
    while (current && current->next)
        current = current->next;
    return (current);
}

void    free_buff(t_gnllist *buff)
{
    t_gnllist  *current;
    t_gnllist  *next;

    current = buff;
    while (current)
    {
        free(current->content);
        next = current->next;
        free(current);
        current = next;            
    }
}
