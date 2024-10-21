/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_assets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:53:34 by talin             #+#    #+#             */
/*   Updated: 2024/10/21 14:58:08 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

bool	ft_open(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (FALSE);
	close(fd);
	return (TRUE);
}

mlx_image_t	*ft_asset_to_image(mlx_t *mlx, char *img_path)
{
	mlx_image_t		*img;
	mlx_texture_t	*texture;

	if (ft_open(img_path) == FALSE)
		ft_printf("Error: can't open !\n");
	texture = mlx_load_png(img_path);
	if (!texture)
		ft_printf("no texture\n");
	img = mlx_texture_to_image(mlx, texture);
	if (!img)
		ft_printf("no img\n");
	mlx_resize_image(img, WIDTH, WIDTH);
	mlx_delete_texture(texture);
	return (img);
}

void	ft_load_assets(t_mapping *game)
{
	game->assets.rock = ft_asset_to_image(game->mlx, "assets/rock.png");
	game->assets.dino = ft_asset_to_image(game->mlx, "assets/dino.png");
	game->assets.grass = ft_asset_to_image(game->mlx, "assets/grass.png");
	game->assets.meat = ft_asset_to_image(game->mlx, "assets/meat.png");
	game->assets.portal = ft_asset_to_image(game->mlx, "assets/portal.png");
	game->assets.enemy = ft_asset_to_image(game->mlx, "assets/enemy.png");
}

void	ft_delete_assets(t_mapping *game)
{
	mlx_delete_image(game->mlx, game->images.grass);
	mlx_delete_image(game->mlx, game->images.meat);
	mlx_delete_image(game->mlx, game->images.dino);
	mlx_delete_image(game->mlx, game->images.portal);
	mlx_delete_image(game->mlx, game->images.rock);
	mlx_delete_image(game->mlx, game->images.enemy);
}
