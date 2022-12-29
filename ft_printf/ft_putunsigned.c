/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsomrat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 04:08:12 by lsomrat           #+#    #+#             */
/*   Updated: 2022/08/22 04:09:11 by lsomrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(unsigned int num)
{
	int	length;

	length = 0;
	if (num > 9)
	{
		length += ft_putnbr(num / 10);
		length += ft_putchar(num % 10 + 48);
	}
	else
		length += ft_putchar(num + 48);
	return (length);
}
