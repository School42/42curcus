/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bworrawa <bworrawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:58:35 by bworrawa          #+#    #+#             */
/*   Updated: 2024/09/30 10:45:49 by bworrawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	cleanup_map(char **map)
{
	int	y;

	y = 0;
	while (map[y])
	{
		free(map[y]);
		y++;
	}
	free(map);
	return (1);
}

int	cleanup_all(t_game *g)
{
	if (g->map)
		cleanup_map(g->map);
	if (g->path)
		cleanup_map(g->path);
	if (g->m_path)
		cleanup_map(g->m_path);
	return (1);
}
