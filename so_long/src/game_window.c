/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:46:46 by talin             #+#    #+#             */
/*   Updated: 2024/10/14 16:46:33 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_game_window(t_mapping game)
{
	game.mlx = mlx_init((WIDTH * game.size.x), \
	(WIDTH * game.size.y), "So_Long", true);
	if (!game.mlx)
		ft_printf("MLX\n");
	mlx_image_t*	img = mlx_new_image(game.mlx, 256, 256);
	memset(img->pixels, 255, img->width * img->height * sizeof(int32_t));
	mlx_image_to_window(game.mlx, img, 0, 0);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
}
