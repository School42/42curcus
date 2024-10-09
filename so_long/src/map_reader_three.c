/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader_three.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:51:11 by talin             #+#    #+#             */
/*   Updated: 2024/10/09 16:20:27 by talin            ###   ########.fr       */
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
				return (0);
			j++;
		}
		i++;
	}
	return (new.valid);
}

t_mapping	ft_creat_game_map(char **av)
{
	t_mapping	new;

	new = ft_init_mapping();
	new.map = ft_making_map(av);
	new.size.y = ft_size_map(av[1]);
	new = ft_checking_map(new);
	new = ft_valid_map(new);
	new.valid = ft_outsider(new);
	new.valid = ft_right_path(new);
	if (new.map)
		free(new.map);
	if (new.valid)
		new.game_map = ft_making_map(av);
	return (new);
}

int	main(int ac, char **av)
{
	(void)		ac;
	t_mapping	game;

	game = ft_creat_game_map(av);
	if (!game.valid)
	{
		ft_printf("Error\n");
		return (1);
	}
	else
	{
		int i = 0;
		ft_printf("Good\n");
		while (i < game.size.y)
		{
			ft_printf("%s\n", game.game_map[i]);
			i++;
		}
	}
}
