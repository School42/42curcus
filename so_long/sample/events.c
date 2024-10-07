/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bworrawa <bworrawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:53:44 by bworrawa          #+#    #+#             */
/*   Updated: 2024/09/30 11:08:19 by bworrawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid_move(t_game *g, ssize_t dir)
{
	size_t	x;
	size_t	y;

	x = g->player.pos.x;
	y = g->player.pos.y;
	if (dir == DU)
		return (g->map[y - 1][x] != CW);
	if (dir == DR)
		return (g->map[y][x + 1] != CW);
	if (dir == DD)
		return (g->map[y + 1][x] != CW);
	if (dir == DL)
		return (g->map[y][x - 1] != CW);
	return (0);
}

void	cb_x_button_pressed(void *param)
{
	t_game	*g;
	char	*message;

	g = (t_game *)param;
	if (g->status == GS_ACTIVE)
		message = "Close button being pressed.";
	else
		message = "";
	sl_clean_exit(g, message);
}

static int	_get_direction(t_game *g, keys_t key)
{
	int	ret_dir;

	ret_dir = 0;
	if (key == MLX_KEY_UP || key == MLX_KEY_W || key == MLX_KEY_Z)
		ret_dir = DU;
	if (key == MLX_KEY_RIGHT || key == MLX_KEY_D || key == MLX_KEY_D)
		ret_dir = DR;
	if (key == MLX_KEY_DOWN || key == MLX_KEY_S)
		ret_dir = DD;
	if (key == MLX_KEY_LEFT || key == MLX_KEY_A || key == MLX_KEY_Q)
		ret_dir = DL;
	if (ret_dir > 0)
	{
		if (!is_valid_move(g, ret_dir))
			return (-1);
		if (g->n_moves >= 999)
		{
			g->player.status = PS_DEAD;
			g->status = GS_GAMEOVER_LOSE;
			ft_printf("Game Over: Your player died from exhaustion.\n");
		}
	}
	return (ret_dir);
}

void	cb_detect_keys(mlx_key_data_t keydata, void *param)
{
	t_game	*g;
	ssize_t	dir;
	ssize_t	dlt_x;
	ssize_t	dlt_y;

	g = (t_game *)param;
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
			sl_clean_exit(g, NULL);
		dir = _get_direction(g, keydata.key);
		if (dir > 0 && g->player.status == PS_IDLE)
		{
			get_dir_delta(dir, &dlt_x, &dlt_y);
			g->player.pos.x += dlt_x;
			g->player.pos.y += dlt_y;
			g->player.face = dir;
			g->player.status = PS_WALKING;
			g->n_moves++;
			ft_printf("%d move(s)\n", g->n_moves);
			display_moves(g);
		}
		if (g->n_moves == 1)
			monsters_think(g);
	}
}
