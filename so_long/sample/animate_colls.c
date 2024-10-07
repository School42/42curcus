/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_colls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bworrawa <bworrawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 19:10:24 by bworrawa          #+#    #+#             */
/*   Updated: 2024/09/30 10:13:20 by bworrawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	animate_colls(t_game *g)
{
	static uint16_t	frame_no = 0;
	size_t			ctr;
	int				bright;

	if (frame_no % 30 == 29)
	{
		bright = frame_no / 30 == 1 || frame_no / 30 == 3;
		ctr = 0;
		while (ctr < g->sprites[SI_C1]->count)
		{
			if (g->colls[ctr].status != CS_COLLECTED)
			{
				g->sprites[SI_C1]->instances[ctr].enabled = !bright;
				g->sprites[SI_C2]->instances[ctr].enabled = bright;
			}
			ctr++;
		}
	}
	if (frame_no > TFR_COLL)
		frame_no = 0;
	frame_no++;
}

void	animate_colls_v(t_game *g)
{
	static uint16_t	frame_no = 0;
	size_t			ctr;
	int				d;

	if (frame_no > TFR_COLL_V / 2)
		d = -1;
	else
		d = 1;
	if (frame_no % 10 == 0)
	{
		ctr = 0;
		while (ctr < g->sprites[SI_C1]->count)
		{
			if (g->colls[ctr].status != CS_COLLECTED)
			{
				g->sprites[SI_C1]->instances[ctr].y += (d * 1);
				g->sprites[SI_C2]->instances[ctr].y += (d * 1);
			}
			ctr++;
		}
	}
	if (frame_no > TFR_COLL_V)
		frame_no = 0;
	frame_no++;
}
