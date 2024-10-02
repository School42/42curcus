/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_util_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:14:54 by talin             #+#    #+#             */
/*   Updated: 2024/10/02 15:51:33 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnchar(int c, int size)
{
	int	i;

	i = 0;
	if (size <= 0)
		return (0);
	while (i < size)
	{
		write(1, &c, 1);
		i++;
	}
	return (i);
}

int	ft_putnstr(char *str, int size)
{
	int	i;

	i = 0;
	if (size <= 0)
		return (0);
	while (i < size)
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

char	*ft_strdup(char *s)
{
	char	*ptr;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
		i++;
	ptr = (char *)malloc((i + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (s[i])
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	ft_sign(t_format new, int neg)
{
	if (neg)
		return ('-');
	else if (new.plus && !neg)
		return ('+');
	else
		return (' ');
}

char	ft_usign(t_format new)
{
	if (new.plus)
		return ('+');
	else
		return (' ');
}