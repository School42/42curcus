/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_texture_color.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 13:08:14 by talin             #+#    #+#             */
/*   Updated: 2025/08/18 12:45:41 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

static int	valid_content_elements(char **s, char *line)
{
	if (!ft_strcmp(s[0], "NO") || !ft_strcmp(s[0], "SO") || !ft_strcmp(s[0], "EA") || !ft_strcmp(s[0], "WE"))
	{
		if (ft_length_str_arr(s) != 2)
			return (error_ft(ERR_TEXTURE_FILE), 0);
	}
	else if (!ft_strcmp(s[0], "F") || !ft_strcmp(s[0], "C"))
	{
		if (ft_length_str_arr(s) > 4)
			return (error_ft(ERR_MUL_COL), 0);
	}
	else
	{
		if (!contain_only_certain_characters(line, " 01NEWS"))
			return (error_ft(ERR_INVALID_ELE), 0);
	}
	return (1);
}

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
		if (contain_only_certain_characters(data->map->map[i], " 01NEWS"))
			break ;
		string_arr = ft_split(data->map->map[i], ' ');
		if (!valid_content_elements(string_arr, data->map->map[i]))
			return (ft_free_string_arr(string_arr), 0);
		if (ft_length_str_arr(string_arr) >= 2)
			copy_texture_color(data, string_arr);
		ft_free_string_arr(string_arr);
		i++;
	}
	if (!ft_check_texture_color(data->tex_color))
		return (0);
	if (data->tex_color->check_texture_color > 6)
		return (error_ft(ERR_MUL_ELE), 0);
	return (1);
}
