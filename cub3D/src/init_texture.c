/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 09:46:10 by rick              #+#    #+#             */
/*   Updated: 2025/08/18 16:43:55 by talin            ###   ########.fr       */
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
	tmp->img = mlx_xpm_file_to_image(data->win->mlx, filename,
			&data->tex_color->size, &data->tex_color->size);
	if (!tmp->img)
	{
		free_data(data);
		printf("Error\n");
		exit(1);
	}
	tmp->addr = (int *)mlx_get_data_addr(tmp->img,
			&tmp->bits_per_pixel, &tmp->line_length, &tmp->endian);
}

static int	*xpm_to_img(t_data *d, char *filename, int s)
{
	t_img	tmp;
	int		*buffer;
	int		x;
	int		y;

	init_texture_img(d, &tmp, filename);
	buffer = ft_calloc(1, sizeof * buffer * s * s);
	if (!buffer)
	{
		free_data(d);
		printf("Error\n");
		exit(1);
	}
	y = -1;
	while (++y < s)
	{
		x = -1;
		while (++x < s)
			buffer[y * s + x] = tmp.addr[y * s + x];
	}
	mlx_destroy_image(d->win->mlx, tmp.img);
	return (buffer);
}

void	init_textures(t_data *d)
{
	int	s;

	d->win->textures = ft_calloc(5, sizeof * d->win->textures);
	if (!d->win->textures)
	{
		free_data(d);
		printf("Error\n");
		exit(1);
	}
	s = d->tex_color->size;
	d->win->textures[NORTH] = xpm_to_img(d, d->tex_color->north_texture, s);
	d->win->textures[SOUTH] = xpm_to_img(d, d->tex_color->south_texture, s);
	d->win->textures[EAST] = xpm_to_img(d, d->tex_color->east_texture, s);
	d->win->textures[WEST] = xpm_to_img(d, d->tex_color->west_texture, s);
}

void	init_t_pixel(t_data *data, int h, int w)
{
	int	i;

	if (data->win->t_pixel)
		free_t_pixel((void **)data->win->t_pixel);
	data->win->t_pixel = ft_calloc(h + 1, sizeof * data->win->t_pixel);
	if (!data->win->t_pixel)
	{
		free_data(data);
		printf("Error\n");
		exit(1);
	}
	i = -1;
	while (++i < h)
	{
		data->win->t_pixel[i] = ft_calloc(w + 1, sizeof * data->win->t_pixel);
		if (!data->win->t_pixel[i])
		{
			free_data(data);
			printf("Error\n");
			exit(1);
		}
	}
}
