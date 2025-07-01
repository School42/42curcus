/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_texture_color.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 13:04:01 by talin             #+#    #+#             */
/*   Updated: 2025/07/01 14:56:04 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

char	*copy_color_codes(char **string_arr)
{
	char	*code;
	char	*tmp;
	size_t	i;

	if (ft_length_str_arr(string_arr) <= 2)
		return (ft_strdup(string_arr[1]));
	code = concat(string_arr[1], string_arr[2]);
	i = 2;
	while (string_arr[i + 1])
	{
		tmp = concat(code, string_arr[i + 1]);
		free(code);
		code = tmp;
		i++;
	}
	return (code);
}

int	*copy_codes(char **string_arr)
{
	char	*code;
	int		*codes;
	char	**color_str;
	int		i;

	code = copy_color_codes(string_arr);
	if (!code)
		return (printf("invalid color code!\n"), NULL);
	if (!ft_color_check(code))
		return (printf("invalid color code!\n"), NULL);
	codes = (int *)malloc(sizeof(int) * 3 + 1);
	if (!codes)
		return (NULL);
	color_str = ft_split(code, ',');
	i = -1;
	while (++i < 3)
		codes[i] = ft_atoi(color_str[i]);
	codes[i] = 0;
	return (codes);
}

void	copy_texture_color(t_data *data, char **string_arr)
{
	int status;

	status = 1;
	if (ft_strcmp(string_arr[0], "NO") == 0)
		data->tex_color->north_texture = ft_strdup(string_arr[1]);
	else if (ft_strcmp(string_arr[0], "SO") == 0)
		data->tex_color->south_texture = ft_strdup(string_arr[1]);
	else if (ft_strcmp(string_arr[0], "WE") == 0)
		data->tex_color->west_texture = ft_strdup(string_arr[1]);
	else if (ft_strcmp(string_arr[0], "EA") == 0)
		data->tex_color->east_texture = ft_strdup(string_arr[1]);
	else if (ft_strcmp(string_arr[0], "F") == 0)
		data->tex_color->floor_color = copy_codes(string_arr);
	else if (ft_strcmp(string_arr[0], "C") == 0)
		data->tex_color->ceiling_color = copy_codes(string_arr);
	else
		status = 0;
	if (status)
		data->tex_color->check_texture_color++;
}
