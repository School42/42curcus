/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 10:23:30 by talin             #+#    #+#             */
/*   Updated: 2025/07/21 10:28:03 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

static int	is_valid_pos_in_map(t_data *data, double x, double y)
{
	if (x < 0.25 || x >= data->map->width - 1.25)
		return (0);
	if (y < 0.25 || y >= data->map->height - 0.25)
		return (0);
	return (1);
}

static int	is_valid_pos(t_data *data, double x, double y)
{
	if (is_valid_pos_in_map(data, x, y))
		return (1);
	return (0);
}

int	validate_move(t_data *data, double x, double y)
{
	int	moved;

	moved = 0;
	if (is_valid_pos(data, x, data->player->pos_y))
	{
		data->player->pos_x = x;
		moved = 1;
	}
	if (is_valid_pos(data, data->player->pos_x, y))
	{
		data->player->pos_y = y;
		moved = 1;
	}
	return (moved);
}