/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 15:03:20 by rick              #+#    #+#             */
/*   Updated: 2025/07/22 15:25:58 by talin            ###   ########.fr       */
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
	// printf("map_x : %d, map_y : %d\n", ray->map_x, ray->map_y);
	// printf("dir_x : %f, dir_y : %f, camera_x : %f, plane_x : %f, plane_y : %f\n", ray->ray_dir_x, ray->ray_dir_y, ray->camera_x, player->plane_x, player->plane_y);
	ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
	// printf("deltadist_x : %f, deltadist_y : %f\n", ray->delta_dist_x, ray->delta_dist_y);
}

static void	set_dda(t_ray *ray, t_player *player)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (player->pos_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - player->pos_x) * ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (player->pos_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - player->pos_y) * ray->delta_dist_y;
	}
	// printf("sidedist_y : %f, map_x : %d, map_y : %d\n", ray->side_dist_y, ray->map_x, ray->map_y);
}

static void	perform_dda(t_ray *ray, t_data *data)
{
	ray->hit = 0;
	// printf("map height : %d, width : %d\n", data->map->height, data->map->width);
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
			// printf("increasing sidedist_x: %f\n", ray->side_dist_x);
		}
		else
		{
			// printf("before increasing sidedist_y : %f\n", ray->side_dist_y);
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
			// printf("increasing sidedist_y : %f, deltadist_y : %f\n", ray->side_dist_y, ray->delta_dist_y);
		}
		// printf("sidedist_x : %f, sidedist_y : %f\n", ray->side_dist_x, ray->side_dist_y);
		if (ray->map_y < 0.25 || ray->map_x < 0.25 || ray->map_y > data->map->height - 0.25 || ray->map_x > data->map->width - 0.25)
			break;
		else if (data->map->game_map[ray->map_y][ray->map_x] > '0')
			ray->hit = 1;
	}
	// printf("sidedist_x : %f, sidedist_y : %f\n", ray->side_dist_x, ray->side_dist_y);
}

static void	line_height(t_ray *ray, t_data *data, t_player *player)
{
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->side_dist_x - ray->delta_dist_x);
	else
		ray->perp_wall_dist = (ray->side_dist_y - ray->delta_dist_y);
	// printf("wall_dist : %f, sidedist_x : %f, sidedist_y : %f, deltadist_x :%f, deltadist_y : %f \n", ray->perp_wall_dist, ray->side_dist_x, ray->side_dist_y, ray->delta_dist_x, ray->delta_dist_y);
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
	// printf("DEBUG: wall_x calculated as %f, wall_dist : %f\n", ray->wall_x, ray->perp_wall_dist);
}


int	raycasting(t_player *player, t_data *data)
{
	int		x;
	t_ray	ray;

	x = 0;
	ray = data->ray;
	data->map->width = 34;
	// printf("tex->x : %d\n", data->tex_color->x);
	// printf("raycasting : win_width : %d \n", data->win->win_width);
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