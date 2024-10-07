/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bworrawa <bworrawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:38:48 by bworrawa          #+#    #+#             */
/*   Updated: 2024/09/28 15:26:36 by bworrawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_coord	get_coord(ssize_t x, ssize_t y)
{
	static t_coord	coord;

	coord.x = x;
	coord.y = y;
	return (coord);
}

t_dim	get_dim(size_t w, size_t h)
{
	static t_dim	dim;

	dim.w = w;
	dim.h = h;
	return (dim);
}

char	**copy_map(char **map, void (*f)(unsigned int, char*))
{
	char	**out;	
	int		x;
	int		y;
	int		i;

	y = 0;
	while (map[y])
		y++;
	x = 0;
	while (map[0][x])
		x++;
	i = 0;
	out = (char **) malloc(sizeof(char *) * (y + 1));
	while (map[i])
	{
		out[i] = ft_strdup(map[i]);
		if (f)
			ft_striteri(out[i], f);
		i++;
	}
	out[i] = NULL;
	return (out);
}

void	get_dir_delta(int d, ssize_t *dlt_x, ssize_t *dlt_y)
{
	*dlt_x = 0;
	*dlt_y = 0;
	if (d == DU)
		*dlt_y = -1;
	if (d == DR)
		*dlt_x = 1;
	if (d == DD)
		*dlt_y = 1;
	if (d == DL)
		*dlt_x = -1;
}

char	least_of_four_side(t_game *g, char **m, t_coord xy)
{
	ssize_t	y;
	ssize_t	x;
	char	n;

	x = xy.x;
	y = xy.y;
	n = m[y][x];
	if (ir(y - 1, 0, g->msize.y - 1) && m[y - 1][x] != 1 && m[y - 1][x] < n)
		return (DU);
	if (ir(x + 1, 0, g->msize.x - 1) && m[y][x + 1] != 1 && m[y][x + 1] < n)
		return (DR);
	if (ir(y + 1, 0, g->msize.y - 1) && m[y + 1][x] != 1 && m[y + 1][x] < n)
		return (DD);
	if (ir(x - 1, 0, g->msize.x - 1) && m[y][x - 1] != 1 && m[y][x - 1] < n)
		return (DL);
	return (0);
}
