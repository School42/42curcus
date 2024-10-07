/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bworrawa <bworrawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 19:31:34 by bworrawa          #+#    #+#             */
/*   Updated: 2024/09/27 20:19:48 by bworrawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	dps_but(t_game *g, int e_index, int32_t x, int32_t y)
{
	int	i;

	i = 0;
	while (i < SI_PMAX)
	{
		if (i == e_index)
		{
			g->player.sprites[i]->instances->x = x;
			g->player.sprites[i]->instances->y = y;
			g->player.sprites[i]->enabled = true;
		}
		else
			g->player.sprites[i]->enabled = false;
		i++;
	}
	return (1);
}

void	_player_walking(t_game *g, uint16_t *frame_no, mlx_image_t	*im)
{
	ssize_t			dlt_x;
	ssize_t			dlt_y;
	size_t			i;

	im->instances[0].enabled = false;
	get_dir_delta(g->player.face, &dlt_x, &dlt_y);
	im->instances[0].x += dlt_x * P_STEP_SIZE;
	im->instances[0].y += dlt_y * P_STEP_SIZE;
	i = (g->player.face - 1) * 3;
	if (*frame_no < FR_PLAYER / 3)
		dps_but(g, i, im->instances[0].x, im->instances[0].y);
	else if (*frame_no < FR_PLAYER * 2 / 3)
		dps_but(g, i + 1, im->instances[0].x, im->instances[0].y);
	else if (*frame_no < FR_PLAYER)
		dps_but(g, i + 2, im->instances[0].x, im->instances[0].y);
	else
		dps_but(g, i + 1, im->instances[0].x, im->instances[0].y);
	check_monster_kill(g);
	if (*frame_no == FR_PLAYER)
	{
		g->player.status = PS_IDLE;
		*frame_no = 0;
		check_player_pos(g, &(g->player));
	}
}

void	animate_player(t_game *g)
{
	static uint16_t	frame_no = 0;
	mlx_image_t		*i;

	i = g->sprites[SI_P];
	if (g->player.status == PS_IDLE)
		return ;
	if (g->player.status == PS_WON)
	{
		if (!g->player.sprites[PSI_WON]->enabled)
			dps_but(g, PSI_WON, i->instances[0].x, i->instances[0].y);
		return ;
	}
	if (g->player.status == PS_DEAD)
	{
		if (!g->player.sprites[PSI_LOST]->enabled)
			dps_but(g, PSI_LOST, i->instances[0].x, i->instances[0].y);
		return ;
	}
	if (g->player.status == PS_WALKING)
	{
		frame_no ++;
		_player_walking(g, &frame_no, i);
	}
}
