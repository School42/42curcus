/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:07:27 by talin             #+#    #+#             */
/*   Updated: 2024/10/01 11:29:44 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_printf_char(t_format new, va_list ptr)
{
	int		count;
	char	c;

	count = 0;
	if (new.specifier == 'c')
		c = va_arg(ptr, char);
	else
		c = '%';
	if (!new.minus && new.width)
		count += ft_putnchar(' ', (new.width - 1));
	count += ft_putnchar(c, 1);
	return (count);
}

int	ft_printf_str(t_format new, va_list ptr)
{
	int		count;
	char	*str;
	int		mal;

	str = va_arg(ptr, char *);
	count = 0;
	mal = 0;
	if (!str)
	{
		mal = 1;
		str = ft_strdup("(null)");
	}
	if (!new.minus && new.width)
		count += ft_putnchar(' ', (new.width - new.precision));
	if (new.dot && (new.precision <= ft_strlen(str)))
		count += ft_putnstr(str, new.precision);
	else
		count += ft_putnstr(str, ft_strlen(str));
	if (mal)
		free(str);
	return (count);
}
