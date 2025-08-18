/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 10:23:30 by talin             #+#    #+#             */
/*   Updated: 2025/08/18 16:25:30 by talin            ###   ########.fr       */
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

// static int	is_wall_touched(t_data *data, double x, double y)
// {
// 	int a;
// 	int b;

// 	a = (int)(x);
// 	b = (int)(y);
// 	if (data->map->game_map[b][a] == '1')
// 		return (1);
// 	printf("x : %f, y : %f, map char : %c\n", x, y, data->map->game_map[b][a]);
// 	return (0);
// }

static int	is_wall_touched(t_data *data, double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = (int)x;
	map_y = (int)y;
	if (data->map->game_map[map_y][map_x] == '1')
		return (1);
	return (0);
}

static int	is_valid_pos(t_data *data, double x, double y)
{
	if (is_valid_pos_in_map(data, x, y) && !is_wall_touched(data, x, y))
		return (1);
	return (0);
}

// int	validate_move(t_data *data, double x, double y, int dir)
// {
// 	int	moved;
// 	(void) dir;

// 	moved = 0;
// 	if (is_valid_pos(data, x, data->player->pos_y))
// 	{
// 		data->player->pos_x = x;
// 		moved = 1;
// 	}
// 	if (is_valid_pos(data, data->player->pos_x, y))
// 	{
// 		data->player->pos_y = y;
// 		moved = 1;
// 	}
// 	return (moved);
// }

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
