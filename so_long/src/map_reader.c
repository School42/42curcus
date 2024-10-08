/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:09:46 by talin             #+#    #+#             */
/*   Updated: 2024/10/08 15:17:13 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_size_map(char *filename)
{
	int		fd;
	int		line;
	char	*str;

	line = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("map error\n");
		close(fd);
		return (1);
	}
	str = ft_calloc(1, sizeof(char));
	while (str != NULL)
	{
		str = get_next_line(fd);
		if (str != NULL)
			line++;
		free(str);
	}
	return (line);
}

char	*ft_strdup_sl(const char *s)
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


char	**ft_making_map(char **av)
{
	int			fd;
	char		*str;
	int			i;
	char		**map;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("map error\n");
		close(fd);
		return (NULL);
	}
	map = (char **)malloc(sizeof(char *) * (ft_size_map(av[1]) + 1));
	str = ft_calloc(1, sizeof(char));
	i = 0;
	while (str != NULL)
	{
		str = get_next_line(fd);
		if (str != NULL)
			map[i++] = ft_strdup_sl(str);
		free(str);
	}
	map[i] = 0;
	close(fd);
	return (map);
}

int	ft_char_check(char str, char c)
{
	if (str == c)
		return (1);
	return (0);
}

t_mapping	ft_init_mapping(void)
{
	t_mapping	new;

	new.num_player = 0;
	new.num_collectible = 0;
	new.num_exit = 0;
	new.line_length = 0;
	new.map_size = 0;
	new.valid = 0;
	return (new);
}

t_mapping	ft_error(char *str, t_mapping new)
{
	ft_printf("%s\n", str);
	new.valid = 0;
	return (new);
}

t_mapping	ft_checking_map(t_mapping new)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	new.line_length = ft_strlen(new.map[0]);
	n = new.line_length;
	while (i < new.map_size)
	{
		j = 0;
		n = ft_strlen(new.map[i]);
		while (new.map[i][j])
		{
			if (ft_char_check(new.map[i][j], 'E'))
				new.num_exit++;
			else if (ft_char_check(new.map[i][j], 'P'))
				new.num_player++;
			else if (ft_char_check(new.map[i][j], 'C'))
				new.num_collectible++;
			j++;
		}
		i++;
	}
	if (n == new.line_length)
		new.valid = 1;
	else
		ft_error("line_length", new);
	return (new);
}

int	ft_wall(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

t_mapping	ft_valid_map(t_mapping new)
{
	int	i;

	if (new.num_exit != 1)
		new = ft_error("num_exit", new);
	else if (new.num_player != 1)
		new = ft_error("num_player", new);
	else if (new.num_collectible <= 0)
		new = ft_error("num_collectible", new);
	i = 0;
	while (i < new.map_size)
	{
		if (new.map[i][0] != '1' || new.map[i][new.line_length - 1] != '1')
		{
			new = ft_error("wall e", new);
			return (new);
		}
		i++;
	}
	if (!ft_wall(new.map[0]) || !ft_wall(new.map[new.map_size - 1]))
		new = ft_error("wall", new);
	return (new);
}

int	main(int ac, char **av)
{
	t_mapping	new;
	int			i;
	(void)		ac;

	new = ft_init_mapping();
	new.map = ft_making_map(av);
	new.map_size = ft_size_map(av[1]);
	new = ft_checking_map(new);
	// ft_printf("Exit>%i\nPlayer>%i\nCollectible>%i\nValid>%i\n", new.num_exit, new.num_player, new.num_collectible, new.valid);
	new = ft_valid_map(new);
	ft_printf("Valid====>%i\n", new.valid);
	i = 0;
	while (i < ft_size_map(av[1]))
	{
		ft_printf("%s\n", new.map[i]);
		free(new.map[i]);
		i++;
	}
}
