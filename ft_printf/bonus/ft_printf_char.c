/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:07:27 by talin             #+#    #+#             */
/*   Updated: 2024/10/02 17:38:43 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_char(t_format new, va_list ptr)
{
	int		count;
	char	c;

	count = 0;
	if (new.specifier == 'c')
		c = va_arg(ptr, int);
	else
		return (ft_putnchar('%', 1));
	if (!new.minus && new.width)
		count += ft_putnchar(' ', (new.width - new.precision - 1));
	count += ft_putnchar(' ', new.precision - 1);
	count += ft_putnchar(c, 1);
	return (count);
}

int ft_str_null(t_format new, char *str)
{
	int	count;

	count = 0;
	count += ft_putnchar(' ', (new.width - new.precision));
	if (new.precision < ft_strlen(str) && !new.dot)
	{
		count += ft_putnchar(' ', (new.precision - ft_strlen(str)));
	}
	else
	{
		count += ft_putnchar(' ', new.precision);
		count += ft_putnstr(str, ft_strlen(str));
	}
	return (count);
}

int	ft_printf_str(t_format new, va_list ptr)
{
	int		count;
	char	*str;

	str = va_arg(ptr, char *);
	count = 0;
	if (!str)
	{
		str = ft_strdup("(null)");
		count += ft_str_null(new, str);
		free(str);
		return (count);
	}
	if (new.precision > ft_strlen(str) || new.precision < 0 || !new.dot)
		new.precision = ft_strlen(str);
	if (!new.minus && new.width > new.precision && new.zero && (!new.dot || new.neg_prec))
		count += ft_putnchar('0', new.width - new.precision);
	else if (!new.minus && new.width - new.precision > 0)
		count += ft_putnchar(' ', new.width - new.precision);
	count += ft_putnstr(str, new.precision);
	if (new.minus && new.width - new.precision > 0)
		count += ft_putnchar(' ', new.width - new.precision);
	return (count);
}
