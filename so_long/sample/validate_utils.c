/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bworrawa <bworrawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:21:38 by bworrawa          #+#    #+#             */
/*   Updated: 2024/09/30 11:11:27 by bworrawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_char(t_game *g, char c, t_coord pos)
{
	if (c != CF && c != CW && c != CP && c != CE && c != CC && c != CM)
		return (sl_exit(g, "Invalid map, map contains invalid character(s)."));
	if (c == CP)
	{
		if (g->player.pos.x != 0)
			return (sl_exit(g, "Invalid map, more than one start position."));
		g->player.pos = pos;
	}
	else if (c == CE)
	{
		if (g->exit.pos.x != 0)
			return (sl_exit(g, "Invalid map, more than one exit."));
		g->exit.pos = pos;
	}
	else if (c == CC)
	{
		if (g->n_colls > MAX_COLLS)
			return (sl_exit(g, "More collectibles than allowed."));
		g->colls[g->n_colls].pos = pos;
		g->n_colls++;
	}
	return (1);
}

int	check_map_mon(t_game *g, char c, t_coord pos)
{
	if (c == CM)
	{
		if (g->n_monsters > MAX_MONSTERS)
			return (sl_exit(g, "More monsters than allowed."));
		g->monsters[g->n_monsters].pos = pos;
		g->n_monsters++;
	}
	return (1);
}

int	validate_map_items(t_game *g)
{
	if (g->n_colls <= 0)
		return (sl_exit(g, "No collectibles in the map."));
	if (g->exit.pos.x <= 0)
		return (sl_exit(g, "No exit in the map."));
	if (g->player.pos.x <= 0)
		return (sl_exit(g, "No player in the map."));
	return (1);
}
