/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 10:23:30 by talin             #+#    #+#             */
/*   Updated: 2025/08/28 17:15:53 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

static int	is_valid_pos_in_map(t_data *data, double x, double y)
{
	if (x < 0.25 || x >= data->map->width - 0.25)
		return (0);
	if (y < 0.25 || y >= data->map->height - 0.25)
		return (0);
	return (1);
}

static int	is_wall_touched(t_data *data, double x, double y)
{
	int	left;
	int	right;
	int	top;
	int	bottom;

	left = (int)(x - PLAYER_RADIUS);
	right = (int)(x + PLAYER_RADIUS);
	top = (int)(y - PLAYER_RADIUS);
	bottom = (int)(y + PLAYER_RADIUS);
	if (left < 0)
		left = 0;
	if (right >= data->map->width)
		right = data->map->width - 1;
	if (top < 0)
		top = 0;
	if (bottom >= data->map->height)
		bottom = data->map->height - 1;
	if (data->map->game_map[top][left] == '1'
		|| data->map->game_map[top][right] == '1'
		|| data->map->game_map[bottom][left] == '1'
		|| data->map->game_map[bottom][right] == '1')
		return (1);
	return (0);
}

static int	is_valid_pos(t_data *data, double x, double y)
{
	if (is_valid_pos_in_map(data, x, y) && !is_wall_touched(data, x, y))
		return (1);
	return (0);
}

int	validate_move(t_data *data, double new_x, double new_y)
{
	int	moved;

	moved = 0;
	if (is_valid_pos(data, new_x, new_y))
	{
		data->player->pos_x = new_x;
		data->player->pos_y = new_y;
		moved = 1;
	}
	else
	{
		if (is_valid_pos(data, new_x, data->player->pos_y))
		{
			data->player->pos_x = new_x;
			moved = 1;
		}
		if (is_valid_pos(data, data->player->pos_x, new_y))
		{
			data->player->pos_y = new_y;
			moved = 1;
		}
	}
	return (moved);
}
