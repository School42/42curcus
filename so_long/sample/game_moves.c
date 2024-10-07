/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bworrawa <bworrawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 15:03:47 by bworrawa          #+#    #+#             */
/*   Updated: 2024/09/28 16:30:11 by bworrawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	_mark_as_collected(t_game *g, size_t ind)
{
	g->colls[ind].status = CS_COLLECTED;
	g->sprites[SI_C1]->instances[ind].enabled = false;
	g->sprites[SI_C2]->instances[ind].enabled = false;
	g->n_collected ++;
	display_left(g);
	return (1);
}

int	check_player_pos(t_game *g, t_sl_player *pl)
{
	size_t	i;
	t_coord	c;

	if (pl->pos.x == g->exit.pos.x && pl->pos.y == g->exit.pos.y)
	{
		if (g->n_colls == g->n_collected)
		{
			g->player.status = PS_WON;
			g->status = GS_GAMEOVER_WON;
			return (ft_printf("Game Over: You Won.\n"));
		}
	}
	if (g->n_colls != g->n_collected)
	{
		i = 0;
		while (i < g->n_colls)
		{
			c = get_coord(g->colls[i].pos.x, g->colls[i].pos.y);
			if (pl->pos.x == c.x && pl->pos.y == c.y)
				if (g->colls[i].status != CS_COLLECTED)
					_mark_as_collected(g, i);
			i++;
		}
	}
	return (1);
}

int	monster_can_move(t_game *g, size_t ind, size_t d)
{
	ssize_t	x;
	ssize_t	y;
	ssize_t	dlt_x;
	ssize_t	dlt_y;
	int		ret;

	x = g->monsters[ind].pos.x;
	y = g->monsters[ind].pos.y;
	get_dir_delta(d, &dlt_x, &dlt_y);
	ret = 1;
	if (g->m_path[y + dlt_y][x + dlt_x] == TM_W)
		ret = 0;
	else if (g->m_path[y + dlt_y][x + dlt_x] == TM_M)
		ret = 0;
	if (ret == 1)
	{
		g->m_path[y + dlt_y][x + dlt_x] = TM_M;
		g->m_path[y][x] = TM_F;
	}
	if (ret != 1)
		return (ret);
	return (1);
}
