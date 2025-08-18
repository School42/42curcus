/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_line_by_line.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 16:55:45 by talin             #+#    #+#             */
/*   Updated: 2025/08/18 17:00:28 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

int	connected_wall(t_game_map *map, int row, int col)
{
	if (!upper_wall(map, row, col) && !lower_wall(map, row, col))
		return (0);
	return (1);
}

int	check_line_by_line(t_game_map *map, char *line, int row)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->width && line[i] == ' ')
		i++;
	j = map->width - 1;
	while (j > 0 && line[j] == ' ')
		j--;
	if (line[i] != '1' || !connected_wall(map, row, i)
		|| line[j] != '1' || !connected_wall(map, row, j))
		return (error_ft(ERR_MAP_NO_WALLS), 0);
	while (i < j)
	{
		if (!valid_pos(map, row, i))
			return (0);
		i++;
	}
	return (1);
}
