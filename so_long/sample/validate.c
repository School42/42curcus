/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bworrawa <bworrawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 16:42:50 by bworrawa          #+#    #+#             */
/*   Updated: 2024/09/30 10:33:43 by bworrawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_first(t_game *g, char *buf)
{
	int		nl;
	int		y;

	if (!g->map)
		return (0);
	y = 0;
	nl = 0;
	while (buf[y])
	{
		if (buf[y] == '\n')
			nl++;
		y++;
	}
	y = 0;
	while (g->map[y])
		y++;
	if (y - 1 != nl)
		return (0);
	return (1);
}

int	validate_map(t_game *g)
{
	ssize_t	len;
	char	*c;

	g->msize.y = 0;
	g->msize.x = 0;
	while (g->map && g->map[g->msize.y])
	{
		c = g->map[g->msize.y];
		len = 0;
		while (c[len] && c[len] != '\n')
		{
			if (!check_map_char(g, c[len], get_coord(len, g->msize.y)))
				return (0);
			if (!check_map_mon(g, c[len], get_coord(len, g->msize.y)))
				return (0);
			len++;
		}
		if (g->msize.x == 0)
			g->msize.x = len;
		else
			if (g->msize.x != len)
				sl_exit(g, "Invalid map, not a rectangle.");
		g->msize.y++;
	}
	return (1);
}

int	validate_map_shape(t_game *g)
{
	char	*c;
	ssize_t	i;

	if (g->msize.y < MIN_MW || g->msize.x < MIN_MH)
		return (sl_exit(g, "Invalid map, too small."));
	if (g->msize.y > MAX_MH || g->msize.x > MAX_MW)
		return (sl_exit(g, "Invalid map, too large."));
	i = 0;
	while (g->map && g->map[i])
	{
		if (i == 0 || i == g->msize.y - 1)
		{
			c = g->map[i];
			while (*c)
			{
				if (*c != CW)
					return (sl_exit(g, "Map is not fully bordered. (X)"));
				c++;
			}
		}
		if (g->map[i][0] != CW || g->map[i][g->msize.x - 1] != CW)
			return (sl_exit(g, "Map is not fully bordered. (Y)"));
		i++;
	}
	return (1);
}

static void	_replace_map_char(unsigned int i, char *c)
{
	(void)i;
	if ((int)(*c) == CW)
		*c = TM_W;
	else
		*c = TM_F;
}

int	valid_map_path(t_game *g)
{
	size_t	i;
	ssize_t	e_x;
	ssize_t	e_y;
	ssize_t	c_x;
	ssize_t	c_y;

	e_x = g->exit.pos.x;
	e_y = g->exit.pos.y;
	g->path = copy_map(g->map, &_replace_map_char);
	flood_fill(g, g->path, get_coord(g->player.pos.x, g->player.pos.y), TM_P);
	if (!g->path[e_y] || !g->path[e_y][e_x] || g->path[e_y][e_x] != TM_P)
		return (sl_exit(g, "No path to exit."));
	i = 0;
	while (i < g->n_colls)
	{
		c_x = g->colls[i].pos.x;
		c_y = g->colls[i].pos.y;
		if (!g->path[c_y] || !(g->path[c_y][c_x]) || g->path[c_y][c_x] != TM_P)
			return (sl_exit(g, "Some paths to the collectible were blocked."));
		i++;
	}
	return (1);
}
