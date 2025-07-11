/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 13:27:53 by talin             #+#    #+#             */
/*   Updated: 2025/07/11 16:05:58 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"
#include "../minilibx-linux/mlx.h"

void my_mlx_pixel_put(t_window *data, int x, int y, int color)
{
	if (x < 0 || y < 0 || x >= WIN_WIDTH || y >= WIN_HEIGHT)
		return;
	char *dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

typedef struct s_vec2 {
	int x;
	int y;
} t_vec2;

void	draw_filled_triangle(t_window *win, t_vec2 p0, t_vec2 p1, t_vec2 p2, int color)
{
	int min_x = fmin(fmin(p0.x, p1.x), p2.x);
	int max_x = fmax(fmax(p0.x, p1.x), p2.x);
	int min_y = fmin(fmin(p0.y, p1.y), p2.y);
	int max_y = fmax(fmax(p0.y, p1.y), p2.y);

	for (int y = min_y; y <= max_y; y++)
	{
		for (int x = min_x; x <= max_x; x++)
		{
			float alpha = ((p1.y - p2.y)*(x - p2.x) + (p2.x - p1.x)*(y - p2.y)) /
						  ((float)((p1.y - p2.y)*(p0.x - p2.x) + (p2.x - p1.x)*(p0.y - p2.y)));
			float beta  = ((p2.y - p0.y)*(x - p2.x) + (p0.x - p2.x)*(y - p2.y)) /
						  ((float)((p1.y - p2.y)*(p0.x - p2.x) + (p2.x - p1.x)*(p0.y - p2.y)));
			float gamma = 1.0f - alpha - beta;

			if (alpha >= 0 && beta >= 0 && gamma >= 0)
				my_mlx_pixel_put(win, x, y, color);
		}
	}
}

void	draw_filled_circle(t_window *win, int cx, int cy, int radius, int color)
{
	for (int y = -radius; y <= radius; y++)
	{
		for (int x = -radius; x <= radius; x++)
		{
			if (x * x + y * y <= radius * radius)
				my_mlx_pixel_put(win, cx + x, cy + y, color);
		}
	}
}

void draw_ring(t_window *win, int cx, int cy, int outer_radius, int inner_radius, int color)
{
	for (int y = -outer_radius; y <= outer_radius; y++)
	{
		for (int x = -outer_radius; x <= outer_radius; x++)
		{
			int dist_sq = x * x + y * y;
			if (dist_sq <= outer_radius * outer_radius && dist_sq >= inner_radius * inner_radius)
				my_mlx_pixel_put(win, cx + x, cy + y, color);
		}
	}
}

int interpolate_color(int start, int end, float t)
{
	int sr = (start >> 16) & 0xFF;
	int sg = (start >> 8) & 0xFF;
	int sb = start & 0xFF;

	int er = (end >> 16) & 0xFF;
	int eg = (end >> 8) & 0xFF;
	int eb = end & 0xFF;

	int r = sr + t * (er - sr);
	int g = sg + t * (eg - sg);
	int b = sb + t * (eb - sb);

	return (r << 16) | (g << 8) | b;
}

void	draw_horizontal_gradient_rect(t_window *win, int x1, int y1, int x2, int y2, int col1, int col2)
{
	for (int y = y1; y <= y2; y++)
	{
		for (int x = x1; x <= x2; x++)
		{
			float t = (float)(x - x1) / (x2 - x1);
			int color = interpolate_color(col1, col2, t);
			my_mlx_pixel_put(win, x, y, color);
		}
	}
}

int	create_trgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	add_background(t_data *data)
{
	int	ceiling;
	int	floor;
	int	x;
	int	y;

	ceiling = create_trgb(data->tex_color->ceiling_color[0], data->tex_color->ceiling_color[1], data->tex_color->ceiling_color[2]);
	floor = create_trgb(data->tex_color->floor_color[0], data->tex_color->floor_color[1], data->tex_color->floor_color[2]);
	y = -1;
	while (++y < WIN_HEIGHT / 2)
	{
		x = -1;
		while (++x < WIN_WIDTH)
			my_mlx_pixel_put(data->win, x, y, ceiling);
	}
	while (y < WIN_HEIGHT)
	{
		x = -1;
		while (++x < WIN_WIDTH)
			my_mlx_pixel_put(data->win, x, y, floor);
		y++;
	}
}

int	close_win(int keycode, t_window *vars)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->mlx_win);
		exit(0);
	}
	printf("keycode : %d\n", keycode);
	return (0);
}

int	key_hook(int keycode, t_window *vars)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->mlx_win);
		exit(0);
	}
	printf("keycode : %d\n", keycode);
	return (0);
}

// int mouse_hook(int code, t_window *vars)
// {
// 	(void) vars;
// 	printf("code : %d\n", code);
// 	return (0);
// }

int mouse_hook(int x, int y, t_window *vars)
{
	(void) vars;
	printf("x : %d, y : %d\n", x, y);
	return (0);
}

int handle_mouse_move(int x, int y, t_data *data)
{
	(void) data;
	printf("Mouse moved to: x = %d, y = %d\n", x, y);
	return (0);
}

int	render_frame(t_data *data)
{
	add_background(data);
	if (data->tex_color->ceiling_color[2] < 255)
		data->tex_color->ceiling_color[2]++;
	else if (data->tex_color->ceiling_color[2] == 255)
		data->tex_color->ceiling_color[2] = 0;
	if (data->tex_color->floor_color[2] < 255)
		data->tex_color->floor_color[2]++;
	else if (data->tex_color->floor_color[2] == 255)
		data->tex_color->floor_color[2] = 0;
	draw_horizontal_gradient_rect(data->win, 200, 200, 800, 600, 0x00FF0000, 0x000000FF); // Red to Blue gradient
	draw_ring(data->win, 800, 800, 100, 98, 0x0000FF); // A blue-ish ring
	draw_filled_circle(data->win, 500, 500, 100, 0x00FF00); // Green circle
	mlx_put_image_to_window(data->win->mlx, data->win->mlx_win, data->win->img, 0, 0);
	mlx_put_image_to_window(data->win->mlx, data->win->mlx_win, data->win->img, 0, 0);
	return (0);
}

void	render_game(t_data *data)
{
	data->win->mlx = mlx_init();
	data->win->mlx_win = mlx_new_window(data->win->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	data->win->img = mlx_new_image(data->win->mlx, WIN_WIDTH, WIN_HEIGHT);
	data->win->addr = mlx_get_data_addr(data->win->img, &data->win->bits_per_pixel, &data->win->line_length, &data->win->endian);
	mlx_string_put(data->win->mlx, data->win->mlx_win, 300, 300, 0xFFFFFF, "hello world");
	mlx_mouse_hide(data->win->mlx, data->win->mlx_win);
	mlx_key_hook(data->win->mlx_win, key_hook, data->win);
	mlx_hook(data->win->mlx_win, 6, 1L << 6, handle_mouse_move, data);
	mlx_loop_hook(data->win->mlx, render_frame, data);
	mlx_loop(data->win->mlx);
}
