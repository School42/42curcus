/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 16:15:02 by talin             #+#    #+#             */
/*   Updated: 2025/08/18 16:15:20 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

int	ft_find_longest_length(t_data *data)
{
	int	max;
	int	j;

	max = 0;
	j = data->map->start;
	while (j <= data->map->end)
	{
		if ((int)ft_strlen(data->map->map[j]) > max)
			max = (int)ft_strlen(data->map->map[j]);
		j++;
	}
	return (max);
}
