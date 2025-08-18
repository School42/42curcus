/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 09:45:21 by rick              #+#    #+#             */
/*   Updated: 2025/08/18 16:46:06 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

static void	wrap_mouse_position(int x, int y, t_data *data)
{
	int	w;
	int	h;

	w = data->win->win_width;
	h = data->win->win_height;
	if (x > w - TEX_SIZE || y > h - TEX_SIZE)
	{
		x = TEX_SIZE;
		y = TEX_SIZE;
		mlx_mouse_move(data->win->mlx, data->win->mlx_win, x, y);
	}
	if (x < TEX_SIZE || y < TEX_SIZE)
	{
		x = w - TEX_SIZE;
		y = h - TEX_SIZE;
		mlx_mouse_move(data->win->mlx, data->win->mlx_win, x, y);
	}
}

int	handle_mouse_move(int x, int y, t_data *data)
{
	int	last_x;
	int	delta_x;

	wrap_mouse_position(x, y, data);
	last_x = data->player->mouse_x;
	if (last_x == -1)
	{
		last_x = x;
		return (0);
	}
	delta_x = x - last_x;
	if (delta_x > 0)
		data->player->has_moved += player_rotate(data, 1, MOUSE_SPEED);
	else if (delta_x < 0)
		data->player->has_moved += player_rotate(data, -1, MOUSE_SPEED);
	data->player->mouse_x = x;
	return (0);
}
