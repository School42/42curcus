/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 13:09:13 by talin             #+#    #+#             */
/*   Updated: 2025/08/18 16:43:55 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

t_data	*init_data(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data) + 1);
	if (!data)
		return (NULL);
	data->map = ft_init_mapping();
	if (!data->map)
		return (NULL);
	data->tex_color = ft_init_tex_color();
	data->win = ft_init_win();
	data->player = ft_init_player();
	if (!data->tex_color || !data->win || !data->player)
		return (NULL);
	return (data);
}

t_player	*ft_init_player(void)
{
	t_player	*player;

	player = malloc(sizeof(t_player) + 1);
	if (!player)
		return (NULL);
	player->dir = '\0';
	player->pos_x = 0.0;
	player->pos_y = 0.0;
	player->dir_x = 0.0;
	player->dir_y = 0.0;
	player->move_x = 0;
	player->move_y = 0;
	player->has_moved = 0;
	player->rotate = 0;
	player->plane_x = 0.0;
	player->plane_y = 0.0;
	player->mouse_x = __INT_MAX__;
	return (player);
}

t_window	*ft_init_win(void)
{
	t_window	*win;

	win = malloc(sizeof(t_window) + 1);
	if (!win)
		return (NULL);
	win->mlx = NULL;
	win->mlx_win = NULL;
	win->win_width = WIN_WIDTH;
	win->win_height = WIN_HEIGHT;
	win->t_pixel = NULL;
	win->textures = NULL;
	return (win);
}

t_tex_color	*ft_init_tex_color(void)
{
	t_tex_color	*tex_color;

	tex_color = malloc(sizeof(t_tex_color) + 1);
	if (!tex_color)
		return (NULL);
	tex_color->north_texture = NULL;
	tex_color->south_texture = NULL;
	tex_color->west_texture = NULL;
	tex_color->east_texture = NULL;
	tex_color->floor_color = NULL;
	tex_color->ceiling_color = NULL;
	tex_color->hex_ceiling = 0x0;
	tex_color->hex_floor = 0x0;
	tex_color->size = TEX_SIZE;
	tex_color->pos = 0.0;
	tex_color->x = 0;
	tex_color->y = 0;
	tex_color->check_texture_color = 0;
	return (tex_color);
}

t_game_map	*ft_init_mapping(void)
{
	t_game_map	*map;

	map = malloc(sizeof(t_game_map) + 1);
	if (!map)
		return (NULL);
	map->num_player = 0;
	map->ln_count = 0;
	map->map = NULL;
	map->game_map = NULL;
	map->start = 0;
	map->end = 0;
	map->width = 0;
	map->height = 0;
	map->player = malloc(sizeof(t_player_pos) + 1);
	if (!map->player)
		return (NULL);
	return (map);
}
