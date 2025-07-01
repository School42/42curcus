/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_game_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 16:30:05 by talin             #+#    #+#             */
/*   Updated: 2025/07/01 17:02:56 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

static int	player_pos(int c)
{
	return ((c == 'N' || c == 'S' || c == 'W' || c == 'E'));
}

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
				return (printf("outsider character found!\n"), 0);
			if (player_pos(map->game_map[i][j]))
			{
				map->num_player++;
				map->player->pos = map->game_map[i][j];
				map->player->x = i;
				map->player->y = j;
			}
		}
	}
	if (map->num_player != 1)
		return (printf("more than one player!\n"), 0);
	return (1);
}

int	validate_game_map(t_game_map *map)
{
	if (!outsider_found_num_player(map))
		return (0);
	printf("play position : %c, row : %d, col : %d\n", map->player->pos, map->player->x, map->player->y);
	return (1);
}