/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 14:03:21 by talin             #+#    #+#             */
/*   Updated: 2024/10/02 16:54:59 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nbrlen(size_t n)
{
	int	count;

	count = 0;
	if (n < 0)
		n *= -1;
	while (n >= 16)
	{
		n /= 16;
		count++;
	}
	if (n < 16)
		count++;
	return (count);
}

int	ft_recursive_hex(t_format new, size_t n, size_t i)
{
	int		count;
	int		x;
	char	c;

	count = 0;
	if (n > 0 || (!i && (new.specifier != 'p' || !new.dot)))
	{
		x = n % 16;
		if (new.specifier == 'x' || new.specifier == 'p')
			c = HEXA_LOWER[x];
		else
			c = HEXA_UPPER[x];
		n /= 16;
		i = 5;
		count += ft_recursive_hex(new, n, i);
		count += ft_putnchar(c, 1);
	}
	return (count);
}

int ft_ptr_null(void)
{
	int	count;

	count = 0;
	count += ft_putnstr("(nil)", 5);
	return (count);
}

int	ft_printf_ptr(t_format new, va_list ptr)
{
	int		count;
	size_t	n;
	int		len;

	count = 0;
	n = va_arg(ptr, size_t);
	if (n == 0)
		return (ft_ptr_null());
	len = ft_nbrlen(n);
	len *= !(!n && !new.precision && new.dot);
	if (new.precision < len || !new.dot)
		new.precision = len;
	count += ft_putnstr("0x", 2 * new.zero);
	new.width -= 2;
	if (!new.minus && new.width > new.precision && !new.dot && new.zero)
		count += ft_putnchar('0', new.width - new.precision);
	else if (!new.minus && new.width > new.precision)
		count += ft_putnchar(' ', new.width - new.precision);
	count += ft_putnstr("0x", 2 * !new.zero);
	count += ft_putnchar('0', (new.precision - len) * (n != 0));
	count += ft_putnchar('0', new.precision * (new.dot && !n));
	if (len)
		count += ft_recursive_hex(new, n, n);
	if (new.minus && new.width > new.precision)
		count += ft_putnchar(' ', new.width - new.precision);
	return (count);
}
