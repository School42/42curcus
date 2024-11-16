/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:46:46 by talin             #+#    #+#             */
/*   Updated: 2024/10/28 12:43:38 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	hook(void *param)
{
	t_mapping	*game;

	game = param;
	ft_get_current_frame(game);
	ft_put_img(game);
	game->loop++;
	ft_enemy_moves(game);
}

void	ft_game_window(t_mapping game)
{
	t_point	window;

	window.x = game.size.x * WIDTH;
	window.y = (game.size.y + 1) * WIDTH;
	game.mlx = mlx_init(window.x, window.y, "So_Long", TRUE);
	if (!game.mlx)
		exit(EXIT_FAILURE);
	if (!ft_load_assets(&game))
		return ;
	ft_game_over_window(&game);
	ft_print_strings(&game);
	mlx_loop_hook(game.mlx, &hook, &game);
	mlx_key_hook(game.mlx, &ft_key_hook, &game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
}
