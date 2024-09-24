/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 11:42:51 by talin             #+#    #+#             */
/*   Updated: 2024/09/19 13:15:52 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check(const char format, va_list ptr)
{
	int	x;

	x = 0;
	if (format == 'c')
		x += ft_putchar(va_arg(ptr, int));
	else if (format == 's')
		x += ft_putstr(va_arg(ptr, char *));
	else if (format == 'p')
		x += ft_putptr(va_arg(ptr, unsigned long));
	else if (format == 'd' || format == 'i')
		x += ft_putnbr(va_arg(ptr, int));
	else if (format == 'u')
		x += ft_putuint(va_arg(ptr, unsigned int));
	else if (format == 'x')
		x += ft_puthex(va_arg(ptr, unsigned int), 0);
	else if (format == 'X')
		x += ft_puthex(va_arg(ptr, unsigned int), 1);
	else if (format == '%')
		x += ft_putchar('%');
	return (x);
}

int	ft_printf(const char *format, ...)
{
	va_list	ptr;
	int		x;
	int		i;

	x = 0;
	i = 0;
	if (!format)
		return (-1);
	va_start(ptr, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			x += ft_check(format[i + 1], ptr);
			i++;
		}
		else
			x += ft_putchar(format[i]);
		i++;
	}
	va_end(ptr);
	return (x);
}
