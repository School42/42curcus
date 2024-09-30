/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_util_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:14:54 by talin             #+#    #+#             */
/*   Updated: 2024/09/30 15:41:30 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_putnchar(int c, int size)
{
	int	i;

	i = 0;
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
	while (i < size)
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

