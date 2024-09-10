/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 10:55:16 by ubuntu            #+#    #+#             */
/*   Updated: 2024/09/10 11:12:58 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_hex_len(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len ++;
		num = num / 16;
	}
	return (len);
}

void	ft_hex(unsigned int num, int n)
{
	if (num >= 16)
	{
		ft_hex(num / 16, n);
		ft_hex(num % 16, n);
	}
	else
	{
		if (num <= 9)
			ft_putchar((num + '0'));
		else
		{
			if (n == 0)
				ft_putchar((num - 10 + 'a'));
			if (n == 1)
				ft_putchar((num - 10 + 'A'));
		}
	}
}

int	ft_puthex(unsigned int num, int n)
{
	if (num == 0)
		return (write(1, "0", 1));
	else
		ft_hex(num, n);
	return (ft_hex_len(num));
}
