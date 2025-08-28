/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 15:19:19 by rick              #+#    #+#             */
/*   Updated: 2025/08/28 15:04:25 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

static void	get_texture_index(t_data *data, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->ray_dir_x < 0)
			data->tex_color->index = EAST;
		else
			data->tex_color->index = WEST;
	}
	else
	{
		if (ray->ray_dir_y < 0)
			data->tex_color->index = SOUTH;
		else
			data->tex_color->index = NORTH;
	}
}

void	update_texture(t_ray *ray, t_data *data, int x, t_tex_color *tex)
{
	int	y;
	int	color;
	int	h;

	get_texture_index(data, ray);
	tex->x = (int)(ray->wall_x * tex->size);
	if ((ray->side == 0 && ray->ray_dir_x < 0)
		|| (ray->side == 1 && ray->ray_dir_y > 0))
		tex->x = tex->size - tex->x - 1;
	tex->step = 1.0 * tex->size / ray->line_height;
	y = ray->draw_start;
	h = data->win->win_height;
	tex->pos = (y - h / 2 + ray->line_height / 2) * tex->step;
	while (y < ray->draw_end)
	{
		tex->y = (int)tex->pos & (tex->size - 1);
		tex->pos += tex->step;
		color = data->win->textures[tex->index][tex->size * tex->y + tex->x];
		if (color > 0)
			data->win->t_pixel[y][x] = color;
		y++;
	}
}
