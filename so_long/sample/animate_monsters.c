/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_monsters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bworrawa <bworrawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 20:21:18 by bworrawa          #+#    #+#             */
/*   Updated: 2024/09/28 12:03:29 by bworrawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	animate_monsters(t_game *g)
{
	size_t		i;

	if (g->status != GS_ACTIVE)
		return ;
	i = 0;
	while (i < g->n_monsters)
	{
		g->monsters[i].frame_value ++;
		if (g->monsters[i].frame_value > 100)
		{
			if (g->sprites[SI_M]->instances[i].enabled)
			{
				g->sprites[SI_M]->instances[i].enabled = false;
				g->sprites[SI_M2]->instances[i].enabled = true;
			}
			else
			{
				g->sprites[SI_M]->instances[i].enabled = true;
				g->sprites[SI_M2]->instances[i].enabled = false;
			}
		}
		i++;
	}
}

static void	_monster_move(t_game *g, int ind, size_t *idle_monsters)
{
	ssize_t	dlt_x;
	ssize_t	dlt_y;

	get_dir_delta(g->monsters[ind].next_move, &dlt_x, &dlt_y);
	g->sprites[SI_M]->instances[ind].x += dlt_x * M_STEP_SIZE;
	g->sprites[SI_M]->instances[ind].y += dlt_y * M_STEP_SIZE;
	g->sprites[SI_M2]->instances[ind].x += dlt_x * M_STEP_SIZE;
	g->sprites[SI_M2]->instances[ind].y += dlt_y * M_STEP_SIZE;
	g->monsters[ind].walk_frames --;
	check_monster_kill(g);
	if (g->monsters[ind].walk_frames <= 0)
	{
		g->monsters[ind].status = MS_IDLE;
		g->monsters[ind].pos.x += dlt_x;
		g->monsters[ind].pos.y += dlt_y;
		*idle_monsters += 1;
	}
}

static int	_check_monsters_cooldown(t_game *g, size_t idle_mons)
{
	size_t	i;

	if (idle_mons != g->n_monsters)
		return (0);
	i = 0;
	while (i < g->n_monsters)
	{
		g->monsters[i].status = MS_THINKING;
		g->monsters[i].think_frames = FR_MONSTER_THINK;
		i++;
	}
	return (1);
}

static int	_set_monster_think(t_game *g)
{
	g->monsters[0].think_frames = 0;
	g->monsters[0].status = MS_IDLE;
	monsters_think(g);
	return (1);
}

int	animate_monsters_move(t_game *g)
{
	t_sl_monster	mon;
	size_t			idle_monsters;
	size_t			i;

	if (g->status != GS_ACTIVE)
		return (0);
	idle_monsters = 0;
	i = 0 ;
	while (i < g->n_monsters)
	{
		mon = g->monsters[i];
		if (g->monsters[i].status == MS_IDLE)
			idle_monsters++;
		else if (g->monsters[i].status == MS_WALKING && mon.walk_frames > 0)
			_monster_move(g, i, &idle_monsters);
		else if (g->monsters[i].status == MS_THINKING)
		{
			g->monsters[i].think_frames--;
			if (g->monsters[i].think_frames <= 0)
				return (_set_monster_think(g));
		}
		i++;
	}
	return (_check_monsters_cooldown(g, idle_monsters));
}
