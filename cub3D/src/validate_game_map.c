/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_game_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 16:30:05 by talin             #+#    #+#             */
/*   Updated: 2025/07/03 10:52:41 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

static int	outsider_found_num_player(t_game_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (!valid_char(map->game_map[i][j]))
				return (printf("outsider character found ->%c<-!\n", map->game_map[i][j]), 0);
			if (is_player(map->game_map[i][j]))
			{
				map->num_player++;
				map->player->pos = map->game_map[i][j];
				map->player->x = i;
				map->player->y = j;
			}
		}
	}
	if (map->num_player != 1)
		return (printf("more than one player or none!\n"), 0);
	return (1);
}

static int	check_top_bottom(char *map, int width)
{
	int	i;

	i = -1;
	while (++i < width)
	{
		if (map[i] != '1' && map[i] != ' ')
			return (0);
	}
	return (1);
}

static int	upper_wall(t_game_map *map, int row, int col)
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

static int	lower_wall(t_game_map *map, int row, int col)
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

int	connected_wall(t_game_map *map, int row, int col)
{
	if (!upper_wall(map, row, col) && !lower_wall(map, row, col))
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

static int closed_by_wall(char **m, int r, int c)
{
	int	up;
	int	down;
	int	right;
	int	left;

	up = m[r - 1][c];
	down = m[r + 1][c];
	right = m[r][c + 1];
	left = m[r][c - 1];
	if (!(up == ' ' || up == '1') || !(down == ' ' || down == '1') || !(right == ' ' || right == '1') || !(left == ' ' || left == '1'))
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
			return (printf("floor is touched with space\n"), 0);
	}
	else if (c == ' ')
	{
		if (!closed_by_wall(map->game_map, row, col))
			return (printf("sapce is touched with floor or player\n"), 0);
	}
	return (1);
}

static int	check_line_by_line(t_game_map *map, char *line, int row)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->width && line[i] == ' ')
		i++;
	j = map->width - 1;
	while (j > 0 && line[j] == ' ')
		j--;
	if (line[i] != '1' || !connected_wall(map, row, i) || line[j] != '1' || !connected_wall(map, row, j))
		return (printf("edge of map error!\n"), 0);
	while (i < j)
	{
		if (!valid_pos(map, row, i))
			return (0);
		i++;
	}
	return (1);
}

static int	surrounded_by_walls(t_game_map *map)
{
	int	i;

	i = -1;
	while (++i < map->height)
	{
		if (i == 0 || i == map->height - 1)
		{
			if (!check_top_bottom(map->game_map[i], map->width))
				return (printf("hole in the wall!\n"), 0);
		}
		else
		{
			if (!check_line_by_line(map, map->game_map[i], i))
				return (printf("invalid map!\n"), 0);
		}
	}
	return (1);
}

int	validate_game_map(t_game_map *map)
{
	if (!outsider_found_num_player(map))
		return (0);
	if (!surrounded_by_walls(map))
		return (0);
	printf("play position : %c, row : %d, col : %d\n", map->player->pos, map->player->x, map->player->y);
	return (1);
}