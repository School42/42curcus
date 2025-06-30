/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_game_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 11:52:35 by talin             #+#    #+#             */
/*   Updated: 2025/06/30 13:38:34 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

t_game_map	ft_init_mapping(void)
{
	t_game_map	map;

	map.num_player = 0;
	map.ln_count = 0;
	return (map);
}

int	ft_size_map(char *filename)
{
	int		line;
	char	*str;
	int		fd;

	line = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	str = get_next_line(fd);
	line++;
	while (str != NULL)
	{
		free(str);
		str = get_next_line(fd);
		if (str != NULL)
			line++;
	}
	return (line);
}

char	*ft_strdup_cu(const char *s)
{
	char	*ptr;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	i = ft_strlen(s);
	ptr = (char *)malloc((i + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

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

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
}

t_game_map	ft_create_game_map(char **av, int fd)
{
	t_game_map	map;

	map = ft_init_mapping();
	map.ln_count = ft_size_map(av[1]);
	if (map.ln_count <= 0)
		return (printf("Error\n"), map);
	map.map = ft_making_map(fd, map.ln_count);
	if (!map.map)
	{
		ft_printf("Error: no map was created.\n");
		return (map);
	}
	ft_substr
	// new.size.y = ft_size_map(av[1], fd);
	// new.game_map = ft_copying_map(new.map, new.size.y);
	// new = ft_checking_map(new);
	// if (!new.valid)
	// 	return (new);
	// new = ft_valid_map(new);
	// if (!new.valid)
	// 	return (new);
	// new.valid = ft_outsider(new);
	// new.valid = ft_right_path(&new);
	return (map);
}