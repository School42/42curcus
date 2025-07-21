/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 10:16:40 by talin             #+#    #+#             */
/*   Updated: 2025/07/21 10:33:53 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

static int	player_forward(t_data *data)
{
	double	x;
	double	y;

	x = data->player->pos_x + data->player->dir_x * SPEED;
	y = data->player->pos_y + data->player->dir_y * SPEED;
	return (validate_move(data, x, y));
}

static int	player_backward(t_data *data)
{
	double	x;
	double	y;

	x = data->player->pos_x - data->player->dir_x * SPEED;
	y = data->player->pos_y - data->player->dir_y * SPEED;
	return (validate_move(data, x, y));
}

static int	player_right(t_data *data)
{
	double	x;
	double	y;

	x = data->player->pos_x - data->player->dir_y * SPEED;
	y = data->player->pos_y + data->player->dir_x * SPEED;
	return (validate_move(data, x, y));
}

static int	player_left(t_data *data)
{
	double	x;
	double	y;

	x = data->player->pos_x + data->player->dir_y * SPEED;
	y = data->player->pos_y - data->player->dir_x * SPEED;
	return (validate_move(data, x, y));
}

int	player_move(t_data *data)
{
	int	moved;

	moved = 0;
	if (data->player->move_y == 1)
		moved += player_forward(data);
	if (data->player->move_y == -1)
		moved += player_backward(data);
	if (data->player->move_x == 1)
		moved += player_right(data);
	if (data->player->move_x == -1)
		moved += player_left(data);
	if (data->player->rotate != 0)
		moved += player_rotate(data, data->player->rotate);
	return (moved);
}
