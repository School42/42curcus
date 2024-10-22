/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:33:23 by talin             #+#    #+#             */
/*   Updated: 2024/10/21 16:50:41 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_enemy_moves(t_mapping *game)
{
	int	speed;
	int	x;
	int	y;

	y = -1;
	speed = 50;
	game->enemy_int = game->loop % speed;
	if (game->enemy_int == speed - 1)
	{
		while (++y < game->size.y)
		{
			x = -1;
			while (++x < game->size.x)
			{
				if (game->game_map[y][x] == 'X')
				{
					while (ft_move_enemy(game, x, y) == FALSE)
					{
					}
				}
			}
		}
	}
}

bool	ft_move_enemy(t_mapping *game, int x, int y)
{
	int	rand_x;
	int	rand_y;

	rand_x = (rand() % 3) - 1;
	rand_y = (rand() % 3) - 1;
	if (ft_strchr("0P", game->game_map[y + rand_y][x + rand_x]))
	{
		if (game->game_map[y + rand_y][x + rand_x] == 'P')
			game->gameover = TRUE;
		game->game_map[y + rand_y][x + rand_x] = 'X';
		game->game_map[y][x] = '0';
		return (TRUE);
	}
	return (FALSE);
}
