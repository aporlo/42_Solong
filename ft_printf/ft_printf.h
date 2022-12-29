/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsomrat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 03:24:39 by lsomrat           #+#    #+#             */
/*   Updated: 2022/08/22 03:25:22 by lsomrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int		ft_process(va_list *ap, const char format);
int		ft_printf(const char *format, ...);
int		ft_putchar(char c);
int		ft_putstr(char *c);
int		ft_putnbr(int n);
int		ft_putptr(unsigned long ptr);
int		ft_printptr(unsigned long num);
int		ft_putunsigned(unsigned int num);
int		ft_puthex(unsigned int num, const char format);

#endif
