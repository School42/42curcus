/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 13:54:26 by talin             #+#    #+#             */
/*   Updated: 2024/10/02 15:50:54 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	int		count;
	char	*first;

	count = 0;
	va_start(ptr, str);
	while (*str)
	{
		if (*str == '%')
		{
			first = (char *)str;
			if (*(str++))
				count += ft_parse((char *)str, ptr);
			while (*str && !ft_strchr(SPECIFIER, *str))
				str++;
			if (!(*str))
				str = first;
		}
		else
			count += ft_putchar(*str);
		if (*str)
			str++;
	}
	va_end(ptr);
	return (count);
}

t_format	ft_newformat(void)
{
	t_format	new;

	new.plus = 0;
	new.minus = 0;
	new.space = 0;
	new.zero = 0;
	new.dot = 0;
	new.width = 0;
	new.precision = 0;
	new.neg_prec = 0;
	new.sharp = 0;
	new.specifier = 0;
	return (new);
}

int	ft_print_format(t_format new, va_list ptr)
{
	int	count;

	count = 0;
	if (new.specifier == 'c' || new.specifier == '%')
		count = ft_printf_char(new, ptr);
	if (new.specifier == 's')
		count = ft_printf_str(new, ptr);
	if (new.specifier == 'i' || new.specifier == 'd')
		count = ft_printf_int(new, ptr);
	if (new.specifier == 'u')
		count = ft_printf_uint(new, ptr);
	if (new.specifier == 'x' || new.specifier == 'X')
		count = ft_printf_hex(new, ptr);
	if (new.specifier == 'p')
		count = ft_printf_ptr(new, ptr);
	return (count);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}
