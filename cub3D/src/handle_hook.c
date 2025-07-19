/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 15:41:08 by rick              #+#    #+#             */
/*   Updated: 2025/07/19 15:52:53 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

void	handle_key_press(int key, t_data *data)
{
	if (key == KEY_ESCAPE)
		quit_game(data);
	if (key == KEY_RIGHT)
		data->player->rotate += 1;
	if (key == KEY_LEFT)
		data->player->rotate -= 1;
	if (key == KEY_W)
		data->player->move_y = 1;
	if (key == KEY_S)
		data->player->move_y = -1;
	if (key == KEY_A)
		data->player->move_x = -1;
	if (key == KEY_D)
		data->player->move_x = 1;
}

void	handle_key_release(int key, t_data *data)
{
	if (key == KEY_ESCAPE)
		quit_game(data);
	if (key == KEY_RIGHT && data->player->rotate >= -1)
		data->player->rotate = 0;
	if (key == KEY_LEFT && data->player->rotate <= 1)
		data->player->rotate = 0;
	if (key == KEY_W && data->player->move_y == 1)
		data->player->move_y = 0;
	if (key == KEY_S && data->player->move_y == -1)
		data->player->move_y = 0;
	if (key == KEY_A && data->player->move_x == -1)
		data->player->move_x = 0;
	if (key == KEY_D && data->player->move_x == 1)
		data->player->move_x = 0;
}

void	quit_game(t_data *data)
{
	// mlx_destroy_window(data->win->mlx, data->win->mlx_win);
	// free_data(data);
	exit(0);
}

void	handle_close(t_data *data)
{
	quit_game(data);
}
