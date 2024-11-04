/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:21:47 by talin             #+#    #+#             */
/*   Updated: 2024/11/04 22:49:22 by ubuntu           ###   ########.fr       */
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
		ft_printf(">free: %s\n", new->filename[i]);
		while (new->cmd[i][++j])
		{
			ft_printf("=>free: %s\n", new->cmd[i][j]);
			free(new->cmd[i][j]);
		}
		k = -1;
		if (new->path_arr[i])
		{
			while (new->path_arr[i][++k])
			{
				ft_printf("==>free: %s\n", new->path_arr[i][k]);
				free(new->path_arr[i][k]);
			}
			free(new->path_arr[i]);
		}
		free(new->cmd[i]);
	}
	free(new->filename);
	free(new->cmd);
	free(new->path_arr);
	ft_printf("all free\n");
	return (0);
}
