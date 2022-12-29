/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsomrat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 04:05:13 by lsomrat           #+#    #+#             */
/*   Updated: 2022/08/22 04:05:59 by lsomrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(unsigned long ptr)
{
	int	len;

	len = 0;
	len += write(1, "0x", 2);
	len += ft_printptr(ptr);
	return (len);
}

int	ft_printptr(unsigned long num)
{
	int	length;

	length = 0;
	if (num >= 16)
	{
		length += ft_printptr(num / 16);
		length += ft_printptr(num % 16);
	}
	else
	{
		if (num <= 9)
			length += ft_putchar(num + 48);
		else
			length += ft_putchar(num + 87);
	}
	return (length);
}
