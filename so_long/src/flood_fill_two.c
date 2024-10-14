/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:42:14 by talin             #+#    #+#             */
/*   Updated: 2024/10/14 11:42:49 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_right_path(t_mapping new)
{
	t_point	exit;
	t_point	player;
	int		i;

	player = ft_get_exit(new, 'P');
	flood_fill(new.map, new.size, player);
	exit = ft_get_exit(new, 'E');
	if (!(ft_player_exit(new, exit) && \
	ft_player_exit(new, player)) || !ft_collectible(new))
	{
		new.valid = 0;
		ft_printf("right path\n");
	}
	i = -1;
	while (++i < new.size.y)
		free(new.map[i]);
	return (new.valid);
}