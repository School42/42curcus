/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 13:54:26 by talin             #+#    #+#             */
/*   Updated: 2024/09/30 09:34:23 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_printf_bonus(const char *str, ...)
{
	va_list	ptr;
	int		count;

	count = 0;
	va_start(ptr, str);
	while (*str)
	{
		if (*str == '%')
		{
			count += ft_parse(str++, ptr);
		}
		str++;
	}
	va_end(ptr);
	return (1);
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