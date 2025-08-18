/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 10:34:12 by talin             #+#    #+#             */
/*   Updated: 2025/08/18 16:19:25 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

int	rotating(t_data *data, double speed)
{
	t_player	*p;
	double		x;

	p = data->player;
	x = p->dir_x;
	p->dir_x = p->dir_x * cos(speed) - p->dir_y * sin(speed);
	p->dir_y = x * sin(speed) + p->dir_y * cos(speed);
	x = p->plane_x;
	p->plane_x = p->plane_x * cos(speed) - p->plane_y * sin(speed);
	p->plane_y = x * sin(speed) + p->plane_y * cos(speed);
	return (1);
}

int	player_rotate(t_data *data, double rotate, double mov_speed)
{
	int		moved;
	double	speed;

	moved = 0;
	speed = mov_speed * rotate;
	moved += rotating(data, speed);
	return (moved);
}
