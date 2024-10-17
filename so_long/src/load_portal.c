/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_portal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:20:18 by talin             #+#    #+#             */
/*   Updated: 2024/10/17 16:44:56 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_load_portal(t_mapping *game)
{
	game->assets.portal[0] = ft_asset_to_image(game->mlx, "assets/portal1.png");
	game->assets.portal[1] = ft_asset_to_image(game->mlx, "assets/portal2.png");
	game->assets.portal[2] = ft_asset_to_image(game->mlx, "assets/portal3.png");
	game->assets.portal[3] = ft_asset_to_image(game->mlx, "assets/portal4.png");
	game->assets.portal[4] = ft_asset_to_image(game->mlx, "assets/portal5.png");
	game->assets.portal[5] = ft_asset_to_image(game->mlx, "assets/portal6.png");
}

void	ft_delete_portal(t_mapping *game)
{
	int	i;

	i = 0;
	while (i < PC)
	{
		mlx_delete_image(game->mlx, game->assets.portal[i]);
		i++;
	}
}

void	ft_img_portal(t_mapping *game, int x, int y)
{
	int	i;

	if (game->frame_count % game->frame_speed == 0)
	{
		game->assets.portal[game->current_frame]->enabled = false;
		game->current_frame = (game->current_frame + 1) % PC;
		game->assets.portal[game->current_frame]->enabled = true;
	}
	game->frame_count++;
	i = 0;
	while (i < PC)
	{
		game->assets.portal[i]->enabled = false;
		mlx_resize_image(game->assets.portal[i], 500, 500);
		mlx_image_to_window(game->mlx, game->assets.portal[i], x, y);
		if (i == game->current_frame)
			game->assets.portal[i]->enabled = true;
		i++;
	}
}
