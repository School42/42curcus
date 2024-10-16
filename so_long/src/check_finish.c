/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_finish.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:03:11 by talin             #+#    #+#             */
/*   Updated: 2024/10/16 09:40:06 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_check_count(t_mapping *game, char c)
{
	if (c == 'C')
	{
		game->num_collectible--;
		if (game->num_collectible == 0)
			ft_printf("you have eaten all meats!\n");
	}
	else if (c == 'E' && game->num_collectible != 0)
	{
		ft_printf("some meat has to be consumed!\n");
		return (1);
	}
	else if (c == 'E' && game->num_collectible == 0)
		game->portal = TRUE;
	return (0);
}
