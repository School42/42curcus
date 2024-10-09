/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 09:20:44 by talin             #+#    #+#             */
/*   Updated: 2024/10/09 15:54:01 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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

	i = -1;
	new.size.x = ft_strlen(new.map[0]);
	n = new.size.x;
	while (++i < new.size.y)
	{
		j = 0;
		n = ft_strlen(new.map[i]);
		while (new.map[i][j])
		{
			new.num_exit += (ft_char_check(new.map[i][j], 'E'));
			new.num_player += (ft_char_check(new.map[i][j], 'P'));
			new.num_collectible += (ft_char_check(new.map[i][j], 'C'));
		}
		j++;
	}
	if (n == new.size.x)
		new.valid = 1;
	else
		new = ft_error("size.x", new);
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
	while (i < new.size.y)
	{
		if (new.map[i][0] != '1' || new.map[i][new.size.x - 1] != '1')
		{
			new = ft_error("wall e", new);
			return (new);
		}
		i++;
	}
	if (!ft_wall(new.map[0]) || !ft_wall(new.map[new.size.y - 1]))
		new = ft_error("wall", new);
	return (new);
}

int	ft_outside(char c)
{
	if (c == '1' || c == '0' || c == 'E' || c == 'C' || c == 'P')
		return (1);
	return (0);
}
