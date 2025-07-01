/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture_color.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 13:06:18 by talin             #+#    #+#             */
/*   Updated: 2025/07/01 14:47:49 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

int	ft_color_check(char *color)
{
	char	**colors;
	int		c_code;
	int		i;

	if (!color)
		return (0);
	colors = ft_split(color, ',');
	if (!colors)
		return (0);
	if (ft_length_str_arr(colors) != 3)
		return (0);
	i = 0;
	while (colors[i])
	{
		if (!ft_check_digit(colors[i]))
			return (0);
		c_code = ft_atoi(colors[i]);
		if (!(0 <= c_code && c_code <= 255))
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_texture_color(t_tex_color *tex_color)
{
	if (!tex_color->north_texture || !tex_color->south_texture || !tex_color->east_texture || !tex_color->west_texture || !tex_color->floor_color || !tex_color->ceiling_color)
		return (printf("texture or color code is missing\n"), 0);
	if (!ft_file_exist(tex_color->north_texture) || !ft_file_exist(tex_color->east_texture) || !ft_file_exist(tex_color->west_texture) || !ft_file_exist(tex_color->south_texture))
		return (printf("texture file not existed\n"), 0);
	return (1);
}