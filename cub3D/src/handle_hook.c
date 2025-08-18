/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 15:41:08 by rick              #+#    #+#             */
/*   Updated: 2025/08/18 16:47:52 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

int	handle_key_press(int key, t_data *data)
{
	if (key == XK_Escape)
		quit_game(data);
	if (key == XK_Right)
		data->player->rotate += 1;
	if (key == XK_Left)
		data->player->rotate -= 1;
	if (key == XK_w)
		data->player->move_y = 1;
	if (key == XK_s)
		data->player->move_y = -1;
	if (key == XK_a)
		data->player->move_x = -1;
	if (key == XK_d)
		data->player->move_x = 1;
	return (1);
}

int	handle_key_release(int key, t_data *data)
{
	if (key == XK_Escape)
		quit_game(data);
	if (key == XK_Right && data->player->rotate >= -1)
		data->player->rotate = 0;
	if (key == XK_Left && data->player->rotate <= 1)
		data->player->rotate = 0;
	if (key == XK_w && data->player->move_y == 1)
		data->player->move_y = 0;
	if (key == XK_s && data->player->move_y == -1)
		data->player->move_y = 0;
	if (key == XK_a && data->player->move_x == -1)
		data->player->move_x = 0;
	if (key == XK_d && data->player->move_x == 1)
		data->player->move_x = 0;
	return (1);
}

void	quit_game(t_data *data)
{
	(void) data;
	mlx_destroy_window(data->win->mlx, data->win->mlx_win);
	free_data(data);
	exit(0);
}

int	handle_close(t_data *data)
{
	quit_game(data);
	return (1);
}
