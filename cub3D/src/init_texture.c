/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 09:46:10 by rick              #+#    #+#             */
/*   Updated: 2025/07/21 14:38:06 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

void	init_img_clean(t_img *img)
{
	img->img = NULL;
	img->addr = NULL;
	img->bits_per_pixel = 0;
	img->line_length = 0;
	img->endian = 0;
}

void	init_texture_img(t_data *data, t_img *tmp, char *filename)
{
	init_img_clean(tmp);
	tmp->img = mlx_xpm_file_to_image(data->win->mlx, filename, &data->tex_color->size, &data->tex_color->size);
	if (!tmp->img)
	{
		printf("Error\n");
		exit(1);
	}
	tmp->addr = (int *)mlx_get_data_addr(tmp->img, &tmp->bits_per_pixel, &tmp->line_length, &tmp->endian);
	// printf("check point : init_texture_img\n");
}

static int	*xpm_to_img(t_data *data, char *filename)
{
	t_img	tmp;
	int		*buffer;
	int		x;
	int		y;

	init_texture_img(data, &tmp, filename);
	// printf("check point : after init_texture_img\n");
	buffer = ft_calloc(data->tex_color->size * data->tex_color->size, sizeof(int));
	if (!buffer)
	{
		printf("Error\n");
		exit(1);
	}
	// printf("buffer : size : %zu\n", sizeof(buffer));
	// printf("line_length : %d\n", tmp.line_length);
	// printf("check point : after ft_calloc\n");
	y = -1;
	// printf("tex_color->size : %d\n", data->tex_color->size);
	while (++y < data->tex_color->size)
	{
		x = -1;
		while (++x < data->tex_color->size) {
			buffer[y * data->tex_color->size + x] = tmp.addr[y * (tmp.line_length / sizeof(int)) + x];
		}
	}
	// printf("check point : before mlx_destory_image");
	mlx_destroy_image(data->win->mlx, tmp.img);
	// printf("check point : xpm_to_img\n");
	return (buffer);
}

void	init_textures(t_data *data)
{
	data->win->textures = ft_calloc(5, sizeof * data->win->textures);
	if (!data->win->textures)
	{
		printf("Error\n");
		exit(1);
	}
	data->win->textures[NORTH] = xpm_to_img(data, data->tex_color->north_texture);
	data->win->textures[SOUTH] = xpm_to_img(data, data->tex_color->south_texture);
	data->win->textures[EAST] = xpm_to_img(data, data->tex_color->east_texture);
	data->win->textures[WEST] = xpm_to_img(data, data->tex_color->west_texture);
	// printf("check point : init_textures\n");
}

void	init_texture_pixels(t_data *data)
{
	int	i;

	if (data->win->texture_pixels)
		free_texture_pixels((void **)data->win->texture_pixels);
	data->win->texture_pixels = ft_calloc(data->win->win_height + 1, sizeof * data->win->texture_pixels);
	if (!data->win->texture_pixels)
	{
		printf("Error\n");
		exit(1);
	}
	i = -1;
	while (++i < data->win->win_height)
	{
		data->win->texture_pixels[i] = ft_calloc(data->win->win_width + 1, sizeof * data->win->texture_pixels);
		if (!data->win->texture_pixels[i])
		{
			printf("Error\n");
			exit(1);
		}
	}
}
