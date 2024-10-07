/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bworrawa <bworrawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:11:56 by bworrawa          #+#    #+#             */
/*   Updated: 2024/09/30 10:12:24 by bworrawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	disable_digit_sprites(t_game *g, size_t i)
{
	size_t	j;

	j = 0;
	while (j < g->sprites[SP_D_OS + i]->count)
	{
		g->sprites[SP_D_OS + i]->instances[j].enabled = false;
		j++;
	}
	return (1);
}

void	render_score(t_game *g)
{
	int32_t	x;
	int32_t	y;
	int		i;

	i = 0;
	while (i < 10)
	{
		x = BL;
		y = 20;
		im_to_w(g->mlx, g->sprites[SP_D_OS + i], x, 20);
		im_to_w(g->mlx, g->sprites[SP_D_OS + i], x + FS + FW, 20);
		im_to_w(g->mlx, g->sprites[SP_D_OS + i], x + 2 * (FS + FW), 20);
		x = BL + 10;
		y = BT + (GH * g->msize.y) + 20;
		im_to_w(g->mlx, g->sprites[SP_D_OS + i], x, y);
		im_to_w(g->mlx, g->sprites[SP_D_OS + i], x + FS + FW, y);
		im_to_w(g->mlx, g->sprites[SP_D_OS + i], x + 2 * (FS + FW), y);
		x = 340;
		im_to_w(g->mlx, g->sprites[SP_D_OS + i], x, y);
		im_to_w(g->mlx, g->sprites[SP_D_OS + i], x + FS + FW, y);
		im_to_w(g->mlx, g->sprites[SP_D_OS + i], x + 2 * (FS + FW), y);
		if (i != 0)
			disable_digit_sprites(g, i);
		i++;
	}
}

void	render_score_misc(t_game *g)
{
	size_t	y;

	y = BT + (GH * g->msize.y) + 20;
	im_to_w(g->mlx, g->sprites[SP_D_OS + 10], 280, y);
	if (im_to_w(g->mlx, g->sprites[SI_MOVES], BL + 185, 20) < 0)
		sl_exit(g, "Font sprite error.");
}

int	render_moving_sprites(t_game *g)
{
	ssize_t	x;
	ssize_t	y;
	size_t	i;
	int32_t	out;

	if (!load_p_sprites(g))
		return (sl_exit(g, "Player sprites error."));
	i = 0;
	while (i < g->n_monsters)
	{
		x = g->monsters[i].pos.x;
		y = g->monsters[i].pos.y;
		if (im_to_w(g->mlx, g->sprites[SI_M], BL + (x * GW), BT + (y * GH)) < 0)
			sl_exit(g, "Fail to map MONSTER image to map.");
		out = im_to_w(g->mlx, g->sprites[SI_M2], BL + (x * GW), BT + (y * GH));
		if (out < 0)
			sl_exit(g, "Fail to map MONSTER image to map.");
		i++;
	}
	return (1);
}

void	render(t_game *g)
{
	ssize_t	offset_x;
	ssize_t	offset_y;

	offset_x = BL;
	offset_y = BT;
	render_score(g);
	render_score_misc(g);
	render_map(g, &offset_y, &offset_x);
	render_colls(g, &offset_y, &offset_x);
	display_full_score(g);
	render_moving_sprites(g);
}
