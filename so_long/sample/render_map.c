/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bworrawa <bworrawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 13:41:53 by bworrawa          #+#    #+#             */
/*   Updated: 2024/09/27 14:57:40 by bworrawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	_w_im(t_game *g, int y, int x)
{
	int	i;

	if (y == g->msize.y - 1)
		i = SI_WD;
	else if (y == 0)
		i = SI_WU;
	else if (x == 0)
		i = SI_WL;
	else if (x == g->msize.x - 1)
		i = SI_WR;
	else if ((x + y) % 5 == 0)
		i = SI_WIII;
	else if ((x + y) % 7 == 0)
		i = SI_WII;
	else
		i = SI_WI;
	return (i);
}

static int	_r(t_game *g, size_t si, int32_t x, int32_t y)
{
	return (im_to_w(g->mlx, g->sprites[si], x, y) >= 0);
}

void	render_map(t_game *g, ssize_t *Y, ssize_t *X)
{
	ssize_t	y;
	ssize_t	x;

	y = 0;
	while (g->map && g->map[y])
	{
		x = 0;
		while (g->map[y][x])
		{
			if (!_r(g, SI_F, *X + (x * GW), *Y + (y * GH)))
				sl_exit(g, "Fail to map FLOOR image to map.");
			if (g->map[y][x] == CW)
			{
				if (! _r(g, _w_im(g, y, x), *X + (x * GW), *Y + (y * GH)))
					sl_exit(g, "Fail to map WALL image to map.");
			}
			if (g->map[y][x] == CE)
				if (!_r(g, SI_E, *X + (x * GW), *Y - 50 + (y * GH)))
					sl_exit(g, "Fail to map EXIT image to map.");
			x++;
		}
		y++;
	}
}

void	render_colls(t_game *g, ssize_t *Y, ssize_t *X)
{
	ssize_t	y;
	ssize_t	x;

	y = 0;
	while (g->map && g->map[y])
	{
		x = 0;
		while (g->map[y][x])
		{
			if (g->map[y][x] == CC)
			{
				if (!_r(g, SI_C1, *X + (x * GW), *Y + (y * GH)))
					sl_exit(g, "Fail to map COLLECTIBLE image to map.");
				if (!_r(g, SI_C2, *X + (x * GW), *Y + (y * GH)))
					sl_exit(g, "Fail to map COLLECTIBLE image to map.");
			}
			if (g->map[y][x] == CP)
				if (!_r(g, SI_P, *X + (x * GW), *Y - 50 + (y * GH)))
					sl_exit(g, "Fail to map PLAYER image to map.");
			x++;
		}
		y++;
	}
}
