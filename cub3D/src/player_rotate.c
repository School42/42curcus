/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 10:34:12 by talin             #+#    #+#             */
/*   Updated: 2025/07/21 10:41:22 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

static int	rotating(t_data *data, double speed)
{
	t_player	*player;
	double		x;

	player = data->player;
	x = player->dir_x;
	player->dir_x = player->dir_x * cos(speed) - player->dir_y * sin(speed);
	player->dir_y = x * sin(speed) + player->dir_y * cos(speed);
	x = player->plane_x;
	player->plane_x = player->plane_x * cos(speed) - player->plane_y * sin(speed);
	player->plane_y = x * sin(speed) + player->plane_y * cos(speed);
	return (1);
}

int	player_rotate(t_data *data, double rotate)
{
	int		moved;
	double	speed;

	moved = 0;
	speed = SPEED * rotate;
	moved += rotating(data, speed);
	return (moved);
}