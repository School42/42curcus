/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_loader.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bworrawa <bworrawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 11:33:17 by bworrawa          #+#    #+#             */
/*   Updated: 2024/09/27 13:18:29 by bworrawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	load_sprite(mlx_t *mlx, char *path, mlx_image_t **img, t_dim dim)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(path);
	if (!texture)
		return (0);
	*img = mlx_texture_to_image(mlx, texture);
	if (!*img)
		return (0);
	if (dim.w > 0 && dim.h > 0)
		if (!mlx_resize_image(*img, dim.w, dim.h))
			return (0);
	mlx_delete_texture(texture);
	return (1);
}

int	load_p_sprites(t_game *g)
{
	char	**sprites;
	int		i;
	t_dim	dim;

	dim = get_dim(PW, PH);
	sprites = get_p_sprites();
	if (!sprites)
		sl_exit(g, "Could not allocate sprites setting up memory.(player)");
	i = 0;
	while (i < SI_PMAX)
	{
		if (!load_sprite(g->mlx, sprites[i], &(g->player.sprites[i]), dim))
		{
			free(sprites);
			sl_exit(g, "Could not load player sprites.");
		}
		mlx_image_to_window(g->mlx, g->player.sprites[i], 0, 0);
		g->player.sprites[i]->enabled = false;
		i++;
	}
	free(sprites);
	return (1);
}

int	load_misc_sprites(t_game *g)
{
	t_dim	dim;
	char	**sprites;
	int		i;

	dim = get_dim(GW, GH);
	sprites = get_misc_sprites();
	if (!sprites)
		sl_exit(g, "Could not allocate sprites setting up memory.(misc)");
	i = 0;
	while (i < SI_MAX)
	{
		if (i >= SI_P && i <= SI_E)
			dim = get_dim(PW, PH);
		if (i == SI_MOVES)
			dim = get_dim(FW * 5, FH);
		if (!load_sprite(g->mlx, sprites[i], &(g->sprites[i]), dim))
		{
			free(sprites);
			sl_exit(g, "Could not load misc sprites.");
		}
		i++;
	}
	free(sprites);
	return (1);
}

int	load_font_sprites(t_game *g)
{
	char	**sprites;
	int		i;
	t_dim	d;

	d = get_dim(FW, FH);
	sprites = get_font_sprites();
	if (!sprites)
		sl_exit(g, "Could not allocate sprites setting up memory (font).");
	i = 0;
	while (i < 11)
	{
		if (!load_sprite(g->mlx, sprites[i], &(g->sprites[SP_D_OS + i]), d))
		{
			free(sprites);
			sl_exit(g, "Could not load font sprites.");
		}
		i++;
	}
	free(sprites);
	return (1);
}
