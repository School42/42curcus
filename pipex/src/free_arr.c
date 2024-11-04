/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:21:47 by talin             #+#    #+#             */
/*   Updated: 2024/11/04 13:09:17 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	ft_free_arr(t_array *new, int ac)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	while (++i < ac - 3)
	{
		j = -1;
		free(new->filename[i]);
		while (new->cmd[i][++j])
			free(new->cmd[i][j]);
		k = -1;
		if (new->path_arr[i])
		{
			while (new->path_arr[i][++k])
				free(new->path_arr[i][k]);
			free(new->path_arr[i]);
		}
		free(new->cmd[i]);
	}
	free(new->filename);
	free(new->cmd);
	free(new->path_arr);
	return (0);
}
