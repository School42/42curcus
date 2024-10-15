/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:32:28 by talin             #+#    #+#             */
/*   Updated: 2024/10/15 15:45:08 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_image_to_window(t_mapping *game, int x, int y)
{
	if (y > 0 || x > 0)
		mlx_image_to_window(game->mlx, \
		game->assets.grass, x * WIDTH, y * WIDTH);
	if (game->game_map[y][x] == '1')
		mlx_image_to_window(game->mlx, game->assets.rock, x * WIDTH, y * WIDTH);
	else if (game->game_map[y][x] == 'E')
		mlx_image_to_window(game->mlx, \
		game->assets.portal, x * WIDTH, y * WIDTH);
	else if (game->game_map[y][x] == 'P')
		mlx_image_to_window(game->mlx, game->assets.dino, x * WIDTH, y * WIDTH);
	else if (game->game_map[y][x] == 'C')
		mlx_image_to_window(game->mlx, game->assets.meat, x * WIDTH, y * WIDTH);
	if (y == 0 && x == 0)
		mlx_image_to_window(game->mlx, game->assets.grass, x * WIDTH, y * WIDTH);
}

void	ft_put_img(t_mapping *game)
{
	int	x;
	int	y;

	y = 0;
	ft_load_assets(game);
	while (y < game->size.y)
	{
		x = 0;
		while (x < game->size.x)
		{
			ft_image_to_window(game, x, y);
			x++;
		}
		y++;
	}
	return ;
}
