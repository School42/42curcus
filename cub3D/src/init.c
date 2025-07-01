/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 13:09:13 by talin             #+#    #+#             */
/*   Updated: 2025/07/01 16:52:52 by talin            ###   ########.fr       */
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
	if (!data->tex_color)
		return (NULL);
	return (data);
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
