/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader_three.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:51:11 by talin             #+#    #+#             */
/*   Updated: 2024/10/14 15:48:15 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_outsider(t_mapping new)
{
	int	i;
	int	j;

	i = 0;
	while (i < new.size.y)
	{
		j = 0;
		while (j < new.size.x)
		{
			if (!ft_outside(new.map[i][j]))
			{
				ft_printf("Error: Outsider found!\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (new.valid);
}

char	**ft_copying_map(char **map, int size)
{
	char	**game;
	int		i;

	game = (char **)malloc(sizeof(char *) * (size + 1));
	i = 0;
	while (i < size)
	{
		game[i] = ft_strdup_sl(map[i]);
		i++;
	}
	game[i] = 0;
	return (game);
}

t_mapping	ft_creat_game_map(char **av, int fd)
{
	t_mapping	new;

	new = ft_init_mapping();
	new.map = ft_making_map(av, fd);
	if (!new.map || !new.game_map)
	{
		ft_printf("Error: no map was created.\n");
		return (new);
	}
	new.size.y = ft_size_map(av[1], fd);
	new.game_map = ft_copying_map(new.map, new.size.y);
	new = ft_checking_map(new);
	if (!new.valid)
		return (new);
	new = ft_valid_map(new);
	if (!new.valid)
		return (new);
	new.valid = ft_outsider(new);
	new.valid = ft_right_path(new);
	if (new.map)
		free(new.map);
	return (new);
}

int	ft_free(t_mapping game)
{
	int	i;

	i = 0;
	if (game.game_map)
	{
		while (i < game.size.y)
		{
			free(game.game_map[i]);
			i++;
		}
		if (game.game_map)
			free(game.game_map);
	}
	return (0);
}
