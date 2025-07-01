/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_game_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 11:52:35 by talin             #+#    #+#             */
/*   Updated: 2025/07/01 16:53:57 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

char	**ft_making_map(int fd, int size)
{
	char		*str;
	int			i;
	char		**map;

	map = (char **)malloc(sizeof(char *) * (size + 1));
	str = get_next_line(fd);
	i = 0;
	while (str != NULL)
	{
		map[i++] = ft_strdup_cu(str);
		free(str);
		str = get_next_line(fd);
	}
	map[i] = 0;
	return (map);
}

char	**ft_making_game_map(t_data *data)
{
	char	**game_map;
	int		size;
	int		i;
	int		j;

	ft_finding_pos_map(data);
	size = data->map->end - data->map->start + 1;
	if (size <= 1)
		return (NULL);
	data->map->width = ft_find_longest_length(data);
	data->map->height = size;
	game_map = (char **)malloc(sizeof(char *) * size + 1);
	if (!game_map)
		return (NULL);
	i = 0;
	j = data->map->start;
	while (j <= data->map->end)
	{
		game_map[i++] = copy_map_lines(data->map->width, data->map->map[j++]);
	}
	game_map[i] = 0;
	return (game_map);
}

t_data	*ft_create_game_map(char **av, int fd)
{
	t_data		*data;

	data = init_data();
	if (!data)
		return (NULL);
	data->map->ln_count = ft_size_map(av[1]);
	if (data->map->ln_count <= 0)
		return (printf("Error\n"), NULL);
	data->map->map = ft_making_map(fd, data->map->ln_count);
	if (!data->map->map)
	{
		ft_printf("Error: no map was created.\n");
		return (NULL);
	}
	if (!texture_and_color(data))
		return (printf("Error\n"), NULL);
	data->map->game_map = ft_making_game_map(data);
	if (!data->map->game_map)
		return (printf("game map error!\n"), NULL);
	if (!validate_game_map(data->map))
		return (printf("game map error!\n"), NULL);
	print_game_map(data->map->game_map);
	return (data);
}
