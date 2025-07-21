/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 15:28:17 by rick              #+#    #+#             */
/*   Updated: 2025/07/21 14:39:10 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

void	init_img(t_data *data, t_img *img, int width, int height)
{
	// printf("Creating image with width: %d, height: %d\n", width, height);
	init_img_clean(img);
	img->img = mlx_new_image(data->win->mlx, width, height);
	if (!img->img)
	{
		printf("Error\n");
		exit(1);
	}
	img->addr = (int *)mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
	// printf("check point : init_img\n");
}

void	set_image_pixel(t_img *img, int x, int y, int color)
{
	int pixel;

	pixel = y * (img->line_length / 4) + x;
	img->addr[pixel] = color;
}

static void	set_frame_image_pixel(t_data *data, t_img *img, int x, int y)
{
	if (data->win->texture_pixels[y][x] > 0)
		set_image_pixel(img, x, y, data->win->texture_pixels[y][x]);
	else if (y < data->win->win_height / 2)
		set_image_pixel(img, x, y, data->tex_color->hex_ceiling);
	else
		set_image_pixel(img, x, y, data->tex_color->hex_floor);
}

int	render_frame(t_data *data)
{
	t_img	img;
	int		x;
	int		y;

	img.img = NULL;
	// printf("render_frame image with width: %d, height: %d\n", data->win->win_width, data->win->win_height);
	init_img(data, &img, data->win->win_width, data->win->win_height);
	// printf("in render_frame : after init_img\n");
	y = -1;
	while (++y < data->win->win_height)
	{
		x = -1;
		while (++x < data->win->win_width)
			set_frame_image_pixel(data, &img, x, y);
	}
	mlx_put_image_to_window(data->win->mlx, data->win->mlx_win, img.img, 0, 0);
	// printf("in render_frame: after mlx_put_image_to_window\n");
	mlx_destroy_image(data->win->mlx, img.img);
	// printf("check point: render_frame\n");
	return (1);
}
