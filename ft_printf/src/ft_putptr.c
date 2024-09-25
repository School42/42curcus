/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 10:48:56 by ubuntu            #+#    #+#             */
/*   Updated: 2024/09/10 15:56:36 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_len_ptr(unsigned long nbr)
{
	int	len;

	len = 0;
	while (nbr != 0)
	{
		len++;
		nbr = nbr / 16;
	}
	return (len);
}

void	ft_put(unsigned long nbr)
{
	if (nbr >= 16)
	{
		ft_put(nbr / 16);
		ft_put(nbr % 16);
	}
	else
	{
		if (nbr <= 9)
			ft_putchar((nbr + '0'));
		else
			ft_putchar((nbr - 10 + 'a'));
	}
}

int	ft_putptr(unsigned long ptr)
{
	int	x;

	x = 0;
	if (ptr == 0)
		x += write(1, "(nil)", 5);
	else
	{
		x += write(1, "0x", 2);
		ft_put(ptr);
		x += ft_len_ptr(ptr);
	}
	return (x);
}
