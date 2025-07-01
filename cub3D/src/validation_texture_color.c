/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_texture_color.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 13:08:14 by talin             #+#    #+#             */
/*   Updated: 2025/07/01 14:35:00 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

int	texture_and_color(t_data *data)
{
	int		i;
	char	**string_arr;

	i = 0;
	while (i < data->map->ln_count)
	{
		if (ft_strlen(data->map->map[i]) <= 0)
		{
			i++;
			continue ;
		}
		if (ft_check_digit(data->map->map[i]))
			break ;
		string_arr = ft_split(data->map->map[i], ' ');
		if (ft_length_str_arr(string_arr) >= 2)
			copy_texture_color(data, string_arr);
		ft_free_string_arr(string_arr);
		i++;
	}
	if (data->tex_color->check_texture_color != 6 || !ft_check_texture_color(data->tex_color))
		return (0);
	return (1);
}
