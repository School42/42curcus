/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 13:03:01 by talin             #+#    #+#             */
/*   Updated: 2025/07/01 16:06:06 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

void	print_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map->map[i])
	{
		printf("%s\n", data->map->map[i]);
		i++;
	}
	printf("\n###################################\n\n");
	printf("%s\n", data->tex_color->north_texture);
	printf("%s\n", data->tex_color->south_texture);
	printf("%s\n", data->tex_color->west_texture);
	printf("%s\n", data->tex_color->east_texture);
	i = -1;
	while (++i < 3)
		printf("%d ", data->tex_color->floor_color[i]);
	printf("\n");
	i = -1;
	while (++i < 3)
		printf("%d ", data->tex_color->ceiling_color[i]);
	printf("\n");
}

void	print_game_map(char **game_map)
{
	int	i;

	i = -1;
	while (game_map[++i])
	{
		printf("==>%s<==\n", game_map[i]);
	}
}