/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_four.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 16:05:54 by talin             #+#    #+#             */
/*   Updated: 2025/08/18 16:06:23 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

int	ft_check_digit(char *c_code)
{
	int	i;

	i = 0;
	if (!c_code)
		return (0);
	while (c_code[i])
	{
		if (!ft_isdigit(c_code[i]))
			return (0);
		i++;
	}
	return (1);
}
