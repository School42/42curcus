/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:46:46 by talin             #+#    #+#             */
/*   Updated: 2024/10/15 16:35:47 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	hook(void *param)
{
	t_mapping	*game;

	game = param;
	ft_put_img(game);
}

void	ft_game_window(t_mapping game)
{
	t_point	window;

	window.x = game.size.x * WIDTH;
	window.y = game.size.y * WIDTH;
	game.mlx = mlx_init(window.x, window.y, "So_Long", FALSE);
	if (!game.mlx)
		exit(EXIT_FAILURE);
	ft_load_assets(&game);
	mlx_loop_hook(game.mlx, &hook, &game);
	mlx_key_hook(game.mlx, &ft_key_hook, &game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
}
