/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 17:00:02 by talin             #+#    #+#             */
/*   Updated: 2025/08/18 17:02:14 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

int	upper_wall(t_game_map *map, int row, int col)
{
	int	up;
	int	up_right;
	int	up_left;
	int	right;

	up = map->game_map[row - 1][col];
	if (col < map->width - 1)
	{
		up_right = map->game_map[row - 1][col + 1];
		right = map->game_map[row][col];
	}
	else
	{
		up_right = ' ';
		right = ' ';
	}
	if (col > 0)
		up_left = map->game_map[row - 1][col -1];
	else
		up_left = ' ';
	if (!(up == '1' || right == '1' || up_left == '1' || up_right == '1'))
		return (0);
	return (1);
}

int	lower_wall(t_game_map *map, int row, int col)
{
	int	down;
	int	down_right;
	int	down_left;
	int	left;

	down = map->game_map[row + 1][col];
	if (col < map->width - 1)
		down_right = map->game_map[row + 1][col + 1];
	else
		down_right = ' ';
	if (col > 0)
	{
		down_left = map->game_map[row + 1][col - 1];
		left = map->game_map[row][col - 1];
	}
	else
	{
		down_left = ' ';
		left = ' ';
	}
	if (!(down == '1' || left == '1' || down_left == '1' || down_right == '1'))
		return (0);
	return (1);
}

static int	touched_with_space(char **m, int r, int c)
{
	int	up;
	int	down;
	int	right;
	int	left;

	up = m[r - 1][c];
	down = m[r + 1][c];
	right = m[r][c + 1];
	left = m[r][c - 1];
	if (up == ' ' || down == ' ' || right == ' ' || left == ' ')
		return (1);
	return (0);
}

static int	closed_by_wall(char **m, int r, int c)
{
	int	up;
	int	down;
	int	right;
	int	left;

	up = m[r - 1][c];
	down = m[r + 1][c];
	right = m[r][c + 1];
	left = m[r][c - 1];
	if (!(up == ' ' || up == '1')
		|| !(down == ' ' || down == '1')
		|| !(right == ' ' || right == '1')
		|| !(left == ' ' || left == '1'))
		return (0);
	return (1);
}

int	valid_pos(t_game_map *map, int row, int col)
{
	int	c;

	c = map->game_map[row][col];
	if (is_floor_player(c))
	{
		if (touched_with_space(map->game_map, row, col))
			return (error_ft(ERR_MAP_SPACE_FLOOR), 0);
	}
	else if (c == ' ')
	{
		if (!closed_by_wall(map->game_map, row, col))
			return (error_ft(ERR_MAP_SPACE_FLOOR), 0);
	}
	return (1);
}
