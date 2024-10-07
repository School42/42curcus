/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bworrawa <bworrawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:02:11 by bworrawa          #+#    #+#             */
/*   Updated: 2024/09/27 15:37:53 by bworrawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_moves(t_game *g)
{
	int	i;
	int	ind;
	int	arr[3];

	arr[0] = g->n_moves / 100;
	arr[1] = (g->n_moves % 100) / 10;
	arr[2] = g->n_moves % 10;
	i = 0;
	while (i < 3)
	{
		ind = 0;
		while (ind < 10)
		{
			g->sprites[SP_D_OS + ind]->instances[i].enabled = arr[i] == ind;
			ind++;
		}
		i++;
	}
}

void	display_left(t_game *g)
{
	int	i;
	int	ind;
	int	arr[3];
	int	show;

	arr[0] = g->n_collected / 100;
	arr[1] = (g->n_collected % 100) / 10;
	arr[2] = g->n_collected % 10;
	i = 0;
	while (i < 3)
	{
		ind = 0;
		while (ind < 10)
		{
			show = arr[i] == ind;
			g->sprites[SP_D_OS + ind]->instances[3 + i].enabled = show;
			ind++;
		}
		i++;
	}
}

void	display_full_score(t_game *g)
{
	int	i;
	int	ind;
	int	arr[3];
	int	show;

	arr[0] = g->n_colls / 100;
	arr[1] = (g->n_colls % 100) / 10;
	arr[2] = g->n_colls % 10;
	i = 0;
	while (i < 3)
	{
		ind = 0;
		while (ind < 10)
		{
			show = arr[i] == ind;
			g->sprites[SP_D_OS + ind]->instances[6 + i].enabled = show;
			ind++;
		}
		i++;
	}
}
