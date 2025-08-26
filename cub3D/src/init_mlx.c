/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 09:44:29 by rick              #+#    #+#             */
/*   Updated: 2025/08/26 14:50:29 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

void	init_mlx(t_data *data)
{
	data->win->mlx = mlx_init();
	if (!data->win->mlx)
	{
		printf("Error\n");
		exit(1);
	}
	data->win->mlx_win = mlx_new_window(data->win->mlx,
			WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	if (!data->win->mlx_win)
	{
		printf("Error\n");
		exit(1);
	}
	if (BONUS)
	{
		mlx_mouse_hide(data->win->mlx, data->win->mlx_win);
		mlx_mouse_move(data->win->mlx, data->win->mlx_win,
			data->win->win_width / 2, data->win->win_height / 2);
	}
}
