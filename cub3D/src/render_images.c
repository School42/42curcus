/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 14:53:25 by rick              #+#    #+#             */
/*   Updated: 2025/08/18 14:58:00 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

void	render_images(t_data *data)
{
	render_raycast(data);
}

int	render(t_data *data)
{
	data->player->has_moved += player_move(data);
	if (data->player->has_moved == 0)
		return (0);
	render_images(data);
	return (1);
}
