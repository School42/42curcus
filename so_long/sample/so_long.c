/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bworrawa <bworrawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 10:20:31 by bworrawa          #+#    #+#             */
/*   Updated: 2024/09/30 11:11:48 by bworrawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_game(t_game *g)
{
	t_coord	coord;

	coord.x = 0;
	coord.y = 0;
	g->n_monsters = 0;
	g->n_colls = 0;
	g->n_collected = 0;
	g->player.pos = coord;
	g->player.status = PS_IDLE;
	g->n_moves = 0;
	g->exit.pos = coord;
	g->map = NULL;
	g->path = NULL;
	g->m_path = NULL;
	g->status = GS_ACTIVE;
}

int32_t	main(int argc, char **argv)
{
	t_game	g;
	ssize_t	w_w;
	ssize_t	w_h;

	if (argc != 2)
		return (ft_printf("Error, expect exact 1 argument."));
	init_game(&g);
	read_map(&g, argv[1]);
	if (!validate_map(&g) || !validate_map_shape(&g))
		return (0);
	if (!validate_map_items(&g) || !valid_map_path(&g))
		return (0);
	w_w = (g.msize.x * GW) + BL + BR;
	w_h = (g.msize.y * GH) + BT + BB;
	g.mlx = mlx_init(w_w, w_h, SL_GAME_TITLE, false);
	if (!g.mlx)
		sl_exit(&g, "Error initializing library.");
	mlx_close_hook(g.mlx, &cb_x_button_pressed, &g);
	mlx_key_hook(g.mlx, &cb_detect_keys, &g);
	mlx_loop_hook(g.mlx, &animate, &g);
	load_assets(&g);
	mlx_loop(g.mlx);
	mlx_terminate(g.mlx);
	return (cleanup_all(&g));
}
