/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:24:52 by talin             #+#    #+#             */
/*   Updated: 2024/10/28 11:25:53 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_load_enemy_asset(t_mapping *game)
{
	game->enemy[0] = ft_asset_to_image(game->mlx, "assets/enemy1.png");
	game->enemy[1] = ft_asset_to_image(game->mlx, "assets/enemy2.png");
	game->enemy[2] = ft_asset_to_image(game->mlx, "assets/enemy3.png");
	game->enemy[3] = ft_asset_to_image(game->mlx, "assets/enemy4.png");
	game->enemy[4] = ft_asset_to_image(game->mlx, "assets/enemy5.png");
	game->enemy[5] = ft_asset_to_image(game->mlx, "assets/enemy6.png");
	game->enemy[6] = ft_asset_to_image(game->mlx, "assets/enemy7.png");
	game->enemy[7] = ft_asset_to_image(game->mlx, "assets/enemy8.png");
	game->enemy[8] = ft_asset_to_image(game->mlx, "assets/enemy9.png");
	game->enemy[9] = ft_asset_to_image(game->mlx, "assets/enemy10.png");
	game->enemy[10] = ft_asset_to_image(game->mlx, "assets/enemy11.png");
	game->enemy[11] = ft_asset_to_image(game->mlx, "assets/enemy12.png");
}

void	ft_game_over_window(t_mapping *game)
{
	int	i;
	int	x;

	ft_load_enemy_asset(game);
	i = 0;
	x = (((game->size.x < game->size.y) * game->size.x) + \
	((game->size.x >= game->size.y) * game->size.y)) * WIDTH;
	while (i < ENEMY)
	{
		if (!game->enemy[i])
		{
			ft_printf("Failed to create image for frame %d!\n", i + 1);
			exit(EXIT_FAILURE);
		}
		if (i > 0)
			game->enemy[i]->enabled = false;
		mlx_resize_image(game->enemy[i], x, x);
		mlx_image_to_window(game->mlx, game->enemy[i], \
		(game->size.x * WIDTH / 2 - (x / 2)), (x / 10));
		i++;
	}
}

void	ft_get_current_frame(t_mapping *game)
{
	if (game->frame_count % game->frame_speed == 0)
	{
		game->enemy[game->current_frame]->enabled = false;
		game->current_frame = (game->current_frame + 1) % ENEMY;
		game->enemy[game->current_frame]->enabled = true;
	}
	game->frame_count++;
}
