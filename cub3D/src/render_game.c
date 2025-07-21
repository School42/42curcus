/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 13:27:53 by talin             #+#    #+#             */
/*   Updated: 2025/07/21 13:24:14 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

void	render_game(t_data *data)
{
	init_player_direction(data);
	init_mlx(data);
	init_textures(data);
	render_images(data);
	mlx_hook(data->win->mlx, 33, 1L << 17, handle_close, data);
	mlx_hook(data->win->mlx_win, 2, 1L << 0, handle_key_press, data);
	mlx_hook(data->win->mlx_win, 3, 1L << 1, handle_key_release, data);
	mlx_loop_hook(data->win->mlx, render, data);
	mlx_loop(data->win->mlx);
}
