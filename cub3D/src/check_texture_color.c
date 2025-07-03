/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture_color.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 13:06:18 by talin             #+#    #+#             */
/*   Updated: 2025/07/03 16:02:15 by talin            ###   ########.fr       */
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
		return (ft_free_string_arr(colors), 0);
	i = 0;
	while (colors[i])
	{
		if (!ft_check_digit(colors[i]))
			return (ft_free_string_arr(colors), 0);
		c_code = ft_atoi(colors[i]);
		if (!(0 <= c_code && c_code <= 255))
			return (error_ft(ERR_COLOR_RGB_VAL), ft_free_string_arr(colors), 0);
		i++;
	}
	ft_free_string_arr(colors);
	return (1);
}

int	ft_check_texture_color(t_tex_color *tex_color)
{
	if (!tex_color->north_texture || !tex_color->south_texture || !tex_color->east_texture || !tex_color->west_texture)
		return (error_ft(ERR_TEX_MISSING), 0);
	if (!tex_color->floor_color || !tex_color->ceiling_color)
		return (error_ft(ERR_COLOR_MISSING), 0);
	if (!ft_file_exist(tex_color->north_texture) || !ft_file_exist(tex_color->east_texture) || !ft_file_exist(tex_color->west_texture) || !ft_file_exist(tex_color->south_texture))
		return (0);
	return (1);
}