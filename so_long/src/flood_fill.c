/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 09:24:10 by talin             #+#    #+#             */
/*   Updated: 2024/10/09 14:53:41 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	fill(char **map, t_point size, int row, int col)
{
	if (row < 0 || col < 0 || row >= size.y || col >= size.x)
		return ;
	if (map[row][col] == 'F' || map[row][col] == 'E' || map[row][col] == '1')
		return ;
	if (map[row][col] == '0' || map[row][col] == 'C')
		map[row][col] = 'F';
	fill (map, size, row - 1, col);
	fill (map, size, row + 1, col);
	fill (map, size, row, col - 1);
	fill (map, size, row, col + 1);
}

void	flood_fill(char **map, t_point size, t_point begin)
{
	fill(map, size, begin.y, begin.x);
}

t_point	ft_get_exit(t_mapping new, char c)
{
	t_point	exit;
	int		y;
	int		x;

	y = 0;
	exit.x = 0;
	exit.y = 0;
	while (y < new.size.y)
	{
		x = 0;
		while (x < new.size.x)
		{
			if (new.map[y][x] == c)
			{
				exit.x = x;
				exit.y = y;
				return (exit);
			}
			x++;
		}
		y++;
	}
	return (exit);
}

int	ft_player_exit(t_mapping new, t_point size)
{
	if (new.map[size.y - 1][size.x] == 'F')
		return (1);
	else if (new.map[size.y + 1][size.x] == 'F')
		return (1);
	else if (new.map[size.y][size.x - 1] == 'F')
		return (1);
	else if (new.map[size.y][size.x + 1] == 'F')
		return (1);
	else
		return (0);
}

int	ft_right_path(t_mapping new)
{
	t_point	exit;
	t_point	player;
	int		i;

	player = ft_get_exit(new, 'P');
	flood_fill(new.map, new.size, player);
	exit = ft_get_exit(new, 'E');
	if (!(ft_player_exit(new, exit) && ft_player_exit(new, player)))
	{
		new.valid = 0;
		ft_printf("right path\n");
	}
	i = -1;
	while (++i < new.size.y)
		free(new.map[i]);
	return (new.valid);
}
