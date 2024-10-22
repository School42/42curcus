/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:32:28 by talin             #+#    #+#             */
/*   Updated: 2024/10/21 16:24:36 by talin            ###   ########.fr       */
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
	else if (game->game_map[y][x] == 'X')
		mlx_image_to_window(game->mlx, \
		game->assets.enemy, x * WIDTH, y * WIDTH);
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
		if (game->gameover == TRUE)
			ft_game_over(game);
	}
	return ;
}

void	ft_game_won(t_mapping *game)
{
	mlx_image_t	*img;
	mlx_image_t	*bg;

	mlx_delete_image(game->mlx, game->texts.move);
	mlx_delete_image(game->mlx, game->texts.mo_ve);
	mlx_delete_image(game->mlx, game->texts.meat);
	mlx_delete_image(game->mlx, game->texts.me_at);
	mlx_delete_image(game->mlx, game->texts.won);
	mlx_delete_image(game->mlx, game->texts.playing);
	ft_delete_assets(game);
	game->images = game->assets;
	ft_delete_assets(game);
	game->playing = GAME;
	ft_print_game(game);
	bg = mlx_new_image(game->mlx, game->size.x * WIDTH, game->size.y * WIDTH);
	bg = ft_asset_to_image(game->mlx, "assets/bg.png");
	mlx_resize_image(bg, (game->size.x * WIDTH), (game->size.y + 1) * WIDTH);
	mlx_image_to_window(game->mlx, bg, 0, 0);
	img = mlx_new_image(game->mlx, game->size.x * WIDTH, game->size.y * WIDTH);
	img = ft_asset_to_image(game->mlx, "assets/won.png");
	mlx_resize_image(img, (game->size.y * WIDTH), (game->size.y * WIDTH));
	mlx_image_to_window(game->mlx, img, \
	(game->size.x * WIDTH) / 2 - 160, (game->size.y * WIDTH) / 2 - 160);
}

void	ft_game_over(t_mapping *game)
{
	mlx_image_t	*bg;

	mlx_delete_image(game->mlx, game->texts.move);
	mlx_delete_image(game->mlx, game->texts.mo_ve);
	mlx_delete_image(game->mlx, game->texts.meat);
	mlx_delete_image(game->mlx, game->texts.me_at);
	mlx_delete_image(game->mlx, game->texts.won);
	mlx_delete_image(game->mlx, game->texts.playing);
	ft_delete_assets(game);
	game->images = game->assets;
	ft_delete_assets(game);
	game->playing = GAMEOVER;
	bg = mlx_new_image(game->mlx, game->size.x * WIDTH, game->size.y * WIDTH);
	bg = ft_asset_to_image(game->mlx, "assets/bg.png");
	mlx_resize_image(bg, (game->size.x * WIDTH), (game->size.y + 1) * WIDTH);
	mlx_image_to_window(game->mlx, bg, 0, 0);
	ft_game_over_window(game);
}

void	ft_print_game(t_mapping *game)
{
	if (game->playing == GAME)
	{
		ft_printf("Congratulations!!!");
		ft_printf("You completed the game in %d moves!\n", game->move);
	}
	else if (game->playing == CLOSING && game->num_collectible != 0)
		ft_printf("Next time, you should eat all these meats!\n");
	else if (game->playing == CLOSING && game->num_collectible == 0)
		ft_printf("See you again!!!\n");
	else if (game->playing == GAMEOVER)
		ft_printf("Oh no!\n");
}
