/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_raycast.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 14:54:33 by rick              #+#    #+#             */
/*   Updated: 2025/08/18 16:43:55 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

void	render_raycast(t_data *data)
{
	init_t_pixel(data, data->win->win_height, data->win->win_width);
	init_ray(&data->ray);
	raycasting(data->player, data);
	render_frame(data);
}
