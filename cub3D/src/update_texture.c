/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 15:19:19 by rick              #+#    #+#             */
/*   Updated: 2025/07/21 13:36:29 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

static void get_texture_index(t_data *data, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->ray_dir_x < 0)
			data->tex_color->index = WEST;
		else
			data->tex_color->index = EAST;
	}
	else
	{
		if (ray->ray_dir_y < 0)
			data->tex_color->index = NORTH;
		else
			data->tex_color->index = SOUTH;
	}
}

void	update_texture(t_ray *ray, t_data *data, int x, t_tex_color *tex)
{
	int	y;
	int	color;

	get_texture_index(data, ray);
	tex->x = (int)ray->wall_x * tex->size;
	// printf("ray->wall_x : %f tex->size : %d\n", ray->wall_x, tex->size);
	if ((ray->side == 0 && ray->ray_dir_x < 0) || (ray->side == 1 && ray->ray_dir_y > 0))
		tex->x = tex->size - tex->x - 1;
	tex->step = 1.0 * tex->size / ray->line_height;
	tex->pos = (ray->draw_start - data->win->win_height / 2 + ray->line_height / 2) * tex->step;
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		tex->y = (int)tex->pos & (tex->size - 1);
		tex->pos += tex->step;
		color = data->win->textures[tex->index][tex->size * tex->y + tex->x];
		if (tex->index == NORTH || tex->index == EAST)
			color = (color >> 1) & 8355711;
		if (color > 0)
			data->win->texture_pixels[y][x] = color;
		y++;
	}
}
