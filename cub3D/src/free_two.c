/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 16:48:47 by talin             #+#    #+#             */
/*   Updated: 2025/08/18 16:48:56 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

void	free_int_arr(int **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if (arr[i])
			free(arr[i]);
		i++;
	}
	if (arr)
		free(arr);
}

void	free_window(t_window *w)
{
	if (w->t_pixel)
		free_int_arr(w->t_pixel);
	if (w->textures)
		free_int_arr(w->textures);
	if (w)
		free(w);
}
