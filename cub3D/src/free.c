/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 13:07:27 by talin             #+#    #+#             */
/*   Updated: 2025/08/18 16:48:39 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

void	ft_free_string_arr(char **string_arr)
{
	int	i;

	i = 0;
	if (!string_arr)
		return ;
	while (string_arr[i])
	{
		if (string_arr[i])
			free(string_arr[i]);
		i++;
	}
	free(string_arr);
}

void	free_map(t_game_map *map)
{
	if (!map)
		return ;
	if (map->map)
		ft_free_string_arr(map->map);
	if (map->game_map)
		ft_free_string_arr(map->game_map);
	if (map->player)
		free(map->player);
	free(map);
}

void	free_tex_color(t_tex_color *t)
{
	if (!t)
		return ;
	if (t->ceiling_color)
		free(t->ceiling_color);
	if (t->floor_color)
		free(t->floor_color);
	if (t->north_texture)
		free(t->north_texture);
	if (t->east_texture)
		free(t->east_texture);
	if (t->west_texture)
		free(t->west_texture);
	if (t->south_texture)
		free(t->south_texture);
	free(t);
}

void	free_data(t_data *data)
{
	if (!data)
		return ;
	if (data->map)
		free_map(data->map);
	if (data->tex_color)
		free_tex_color(data->tex_color);
	if (data->win)
		free_window(data->win);
	if (data->player)
		free(data->player);
	if (data)
		free(data);
}

void	free_t_pixel(void **t_pixel)
{
	int	i;	

	i = -1;
	while (t_pixel[++i])
	{
		if (t_pixel[i])
			free(t_pixel[i]);
	}
	free(t_pixel);
}
