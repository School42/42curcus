/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 15:03:20 by rick              #+#    #+#             */
/*   Updated: 2025/08/18 16:30:06 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

void	init_raycasting(int x, t_ray *ray, t_player *player)
{
	init_ray(ray);
	ray->camera_x = 2 * x / (double)WIN_WIDTH - 1;
	ray->ray_dir_y = player->dir_y + player->plane_y * ray->camera_x;
	ray->ray_dir_x = player->dir_x + player->plane_x * ray->camera_x;
	ray->map_x = (int)player->pos_x;
	ray->map_y = (int)player->pos_y;
	ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
}

static void	set_dda(t_ray *ray, t_player *p)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (p->pos_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - p->pos_x) * ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (p->pos_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - p->pos_y) * ray->delta_dist_y;
	}
}

static void	perform_dda(t_ray *ray, t_data *data)
{
	ray->hit = 0;
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (ray->map_y < 0.25 || ray->map_x < 0.25
			|| ray->map_y > data->map->height - 0.25
			|| ray->map_x > data->map->width - 0.25)
			break ;
		else if (data->map->game_map[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
	}
}

static void	line_height(t_ray *ray, t_data *data, t_player *player)
{
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->side_dist_x - ray->delta_dist_x);
	else
		ray->perp_wall_dist = (ray->side_dist_y - ray->delta_dist_y);
	ray->line_height = (int)(data->win->win_height / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + data->win->win_height / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + data->win->win_height / 2;
	if (ray->draw_end >= data->win->win_height)
		ray->draw_end = data->win->win_height - 1;
	if (ray->side == 0)
		ray->wall_x = player->pos_y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		ray->wall_x = player->pos_x + ray->perp_wall_dist * ray->ray_dir_x;
	ray->wall_x -= floor(ray->wall_x);
}

int	raycasting(t_player *player, t_data *data)
{
	int		x;
	t_ray	ray;

	x = 0;
	ray = data->ray;
	data->map->width = 34;
	while (x < data->win->win_width)
	{
		init_raycasting(x, &ray, player);
		set_dda(&ray, player);
		perform_dda(&ray, data);
		line_height(&ray, data, player);
		update_texture(&ray, data, x, data->tex_color);
		x++;
	}
	return (1);
}
