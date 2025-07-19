/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 09:44:29 by rick              #+#    #+#             */
/*   Updated: 2025/07/19 14:51:45 by rick             ###   ########.fr       */
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
	data->win->mlx_win = mlx_new_window(data->win->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	if (!data->win->mlx_win)
	{
		printf("Error\n");
		exit(1);
	}
	if (BONUS)
	{
		mlx_mouse_hide(data->win->mlx, data->win->mlx_win);
		mlx_hook(data->win->mlx_win, 6, 1L << 6, handle_mouse_move, data);
	}
}
