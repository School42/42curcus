/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bworrawa <bworrawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:11:18 by bworrawa          #+#    #+#             */
/*   Updated: 2024/09/28 13:07:40 by bworrawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_monster_kill(t_game *g)
{
	size_t	x;
	size_t	y;
	size_t	mx;
	size_t	my;
	size_t	i;

	x = g->sprites[SI_P]->instances[0].x;
	y = g->sprites[SI_P]->instances[0].y + (PH - GH);
	i = 0;
	while (i < g->n_monsters)
	{
		mx = g->sprites[SI_M]->instances[i].x;
		my = g->sprites[SI_M]->instances[i].y;
		if (x < mx + GW && (x + PW) > mx && y < (my + GH) && (y + GH) > my)
		{
			if (g->player.status != PS_DEAD)
			{
				ft_printf("Game Over: You Died.\n");
				g->player.status = PS_DEAD;
				g->status = GS_GAMEOVER_LOSE;
				return ;
			}
		}
		i++;
	}
}

void	animate(void *param)
{
	t_game	*g;

	g = (t_game *) param;
	animate_colls(g);
	animate_colls_v(g);
	animate_monsters(g);
	animate_monsters_move(g);
	animate_player(g);
}
