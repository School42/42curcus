/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_finish.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:03:11 by talin             #+#    #+#             */
/*   Updated: 2024/10/21 14:15:24 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_check_count(t_mapping *game, char c)
{
	if (c == 'C')
	{
		game->num_collectible--;
		game->consumed_meat++;
		ft_print_meat(game);
		if (game->num_collectible == 0)
		{
			mlx_delete_image(game->mlx, game->texts.playing);
			game->texts.won = mlx_put_string(game->mlx, \
			"You have eaten all meats!", (game->size.x + WIDTH + 110), \
			(game->size.y * WIDTH) + 20);
		}
	}
	else if (c == 'E' && game->num_collectible != 0)
	{
		game->texts.playing = mlx_put_string(game->mlx, \
			"Some meat has to be consumed!", (game->size.x + WIDTH + 240), \
			(game->size.y * WIDTH) + 20);
		return (1);
	}
	else if (c == 'E' && game->num_collectible == 0)
		game->portal = TRUE;
	else if (c == 'X')
		game->gameover = TRUE;
	return (0);
}
