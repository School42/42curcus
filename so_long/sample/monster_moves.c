/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bworrawa <bworrawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 15:46:15 by bworrawa          #+#    #+#             */
/*   Updated: 2024/09/28 16:20:32 by bworrawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	_replace_map_pf_char(unsigned int i, char *c)
{
	(void)i;
	if ((int)(*c) == CW)
		*c = 100;
	else
		*c = 1;
}

static void	_monster_set_next_move(t_game *g, int i, size_t nm)
{
	g->monsters[i].next_move = nm;
	g->monsters[i].status = MS_WALKING;
	g->monsters[i].walk_frames = FR_MONSTER_WALK;
}

static void	_monster_set_idle(t_game *g, int i)
{
	g->monsters[i].next_move = 0;
	g->monsters[i].status = MS_IDLE;
	g->monsters[i].walk_frames = 0;
}

static void	_make_monster_map(t_game *g)
{
	size_t	i;

	g->m_path = copy_map(g->path, NULL);
	i = 0;
	while (i < g->n_monsters)
	{
		g->m_path[g->monsters[i].pos.y][g->monsters[i].pos.x] = CM;
		i++;
	}
}

int	monsters_think(t_game *g)
{
	size_t	i;
	char	**map;
	size_t	next_move;

	if (g->status != GS_ACTIVE)
		return (0);
	if (g->m_path == NULL)
		_make_monster_map(g);
	map = copy_map(g->map, &_replace_map_pf_char);
	flood_fill_inc(g, map, get_coord(g->player.pos.x, g->player.pos.y), 2);
	i = 0;
	while (i < g->n_monsters)
	{
		next_move = least_of_four_side(g, map, g->monsters[i].pos);
		if (monster_can_move(g, i, next_move))
			_monster_set_next_move(g, i, next_move);
		else
			_monster_set_idle(g, i);
		i++;
	}
	cleanup_map(map);
	return (1);
}
