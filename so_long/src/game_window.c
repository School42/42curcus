/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:46:46 by talin             #+#    #+#             */
/*   Updated: 2024/10/14 15:58:45 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_game_window(t_mapping game)
{
	game.mlx = mlx_init((WIDTH * game.size.x), \
	(WIDTH * game.size.y), "So_Long", true);
	if (!game.mlx)
		ft_printf("MLX\n");
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
}
