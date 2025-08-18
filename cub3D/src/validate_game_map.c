/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_game_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 16:30:05 by talin             #+#    #+#             */
/*   Updated: 2025/08/18 16:57:23 by talin            ###   ########.fr       */
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
				return (error_ft(ERR_INV_LETTER), 0);
			if (is_player(map->game_map[i][j]))
			{
				map->num_player++;
				map->player->pos = map->game_map[i][j];
				map->player->x = (double)j + 0.5;
				map->player->y = (double)i + 0.5;
			}
		}
	}
	if (map->num_player > 1)
		return (error_ft(ERR_NUM_PLAYER), 0);
	if (map->num_player < 1)
		return (error_ft(ERR_NO_PLAYER), 0);
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

static int	surrounded_by_walls(t_game_map *map)
{
	int	i;

	i = -1;
	while (++i < map->height)
	{
		if (i == 0 || i == map->height - 1)
		{
			if (!check_top_bottom(map->game_map[i], map->width))
				return (error_ft(ERR_MAP_NO_WALLS), 0);
		}
		else
		{
			if (!check_line_by_line(map, map->game_map[i], i))
				return (0);
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
	return (1);
}
