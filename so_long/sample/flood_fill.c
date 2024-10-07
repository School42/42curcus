/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bworrawa <bworrawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 16:33:34 by bworrawa          #+#    #+#             */
/*   Updated: 2024/09/30 10:59:00 by bworrawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ir(int num, int min, int max)
{
	return (num >= min && num <= max);
}

static int	_least(t_game *g, char **m, t_coord coord, int n)
{
	ssize_t	x;
	ssize_t	y;
	int		init_value;

	init_value = n;
	x = coord.x;
	y = coord.y;
	if (ir(y - 1, 0, g->msize.y - 1) && m[y - 1][x] != 1 && m[y - 1][x] < n - 1)
		init_value = m[y - 1][x];
	if (ir(y + 1, 0, g->msize.y - 1) && m[y + 1][x] != 1 && m[y + 1][x] < n - 1)
		init_value = m[y + 1][x];
	if (ir(x - 1, 0, g->msize.x - 1) && m[y][x - 1] != 1 && m[y][x - 1] < n - 1)
		init_value = m[y][x - 1];
	if (ir(x + 1, 0, g->msize.x - 1) && m[y][x + 1] != 1 && m[y][x + 1] < n - 1)
		init_value = m[y][x + 1];
	return (init_value);
}

void	flood_fill(t_game *g, char **map, t_coord coord, int number)
{
	ssize_t	x;
	ssize_t	y;

	x = coord.x;
	y = coord.y;
	if (y < 0 || y >= g->msize.y - 1)
		return ;
	if (x < 0 || x >= g->msize.x - 1)
		return ;
	if (map[y] && map[y][x] && map[y][x] == CW)
		return ;
	map[y][x] = number;
	if (ir(y - 1, 0, g->msize.y - 1) && map[y - 1][x] == CF)
		flood_fill(g, map, get_coord(x, y - 1), number);
	if (ir(x + 1, 0, g->msize.x - 1) && map[y][x + 1] == CF)
		flood_fill(g, map, get_coord(x + 1, y), number);
	if (ir(y + 1, 0, g->msize.y - 1) && map[y + 1][x] == CF)
		flood_fill(g, map, get_coord(x, y + 1), number);
	if (ir(x - 1, 0, g->msize.x - 1) && map[y][x - 1] == CF)
		flood_fill(g, map, get_coord(x - 1, y), number);
}

void	flood_fill_inc(t_game *g, char **m, t_coord coord, int n)
{
	ssize_t	x;
	ssize_t	y;
	ssize_t	mx;
	ssize_t	my;

	mx = g->msize.x;
	my = g->msize.y;
	y = coord.y;
	x = coord.x;
	if (y < 0 || y >= my - 1 || x < 0 || x >= mx - 1 || m[y][x] == 100)
		return ;
	if (_least(g, m, get_coord(x, y), n) < n)
		n = _least(g, m, get_coord(x, y), n) + 1;
	m[y][x] = n;
	if (n < m[y][x] || m[y][x] == 1)
		m[y][x] = n;
	if (ir(y - 1, 0, my - 1) && ((m[y - 1][x] > n + 1) || m[y - 1][x] == 1))
		flood_fill_inc(g, m, get_coord(x, y - 1), n + 1);
	if (ir(x + 1, 0, mx - 1) && ((m[y][x + 1] > n + 1) || m[y][x + 1] == 1))
		flood_fill_inc(g, m, get_coord(x + 1, y), n + 1);
	if (ir(y + 1, 0, my - 1) && ((m[y + 1][x] > n + 1) || m[y + 1][x] == 1))
		flood_fill_inc(g, m, get_coord(x, y + 1), n + 1);
	if (ir(x - 1, 0, mx - 1) && ((m[y][x - 1] > n + 1) || m[y][x - 1] == 1))
		flood_fill_inc(g, m, get_coord(x - 1, y), n + 1);
}
