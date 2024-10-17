/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:32:28 by talin             #+#    #+#             */
/*   Updated: 2024/10/17 16:51:40 by ubuntu           ###   ########.fr       */
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
	// {
	// 	ft_img_portal(game, x, y);
	// }
		mlx_image_to_window(game->mlx, \
		game->assets.portal, x * WIDTH, y * WIDTH);
	else if (game->game_map[y][x] == 'P')
		mlx_image_to_window(game->mlx, game->assets.dino, x * WIDTH, y * WIDTH);
	else if (game->game_map[y][x] == 'C')
		mlx_image_to_window(game->mlx, game->assets.meat, x * WIDTH, y * WIDTH);
	if (y == 0 && x == 0)
		mlx_image_to_window(game->mlx, \
		game->assets.grass, x * WIDTH, y * WIDTH);
}

void	ft_put_img(t_mapping *game)
{
	int	x;
	int	y;

	y = 0;
	if (game->playing == PLAYING)
	{
		ft_delete_assets(game);
		game->images = game->assets;
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
		if (game->portal == TRUE)
			ft_game_won(game);
	}
	return ;
}

void	ft_game_won(t_mapping *game)
{
	ft_delete_assets(game);
	game->images = game->assets;
	ft_delete_assets(game);
	game->playing = GAME;
	ft_print_game(game);
	mlx_close_window(game->mlx);
}

void	ft_print_game(t_mapping *game)
{
	if (game->playing == GAME)
	{
		ft_printf("\nCongratulations!!!");
		ft_printf("You completed the game in %d moves!\n", game->move);
	}
	else if (game->playing == CLOSING)
		ft_printf("\nNext time, we should get these meats!\n");
	else if (game->playing == GAMEOVER)
		ft_printf("\nOh no!\n");
}
