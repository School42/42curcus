/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:21:47 by talin             #+#    #+#             */
/*   Updated: 2024/11/11 15:38:28 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	ft_free_arr(t_array *new, int ac)
{
	int	i;
	int	j;

	i = -1;
	while (++i < ac - 3)
	{
		j = -1;
		free(new->filename[i]);
		while (new->cmd[i][++j])
		{
			free(new->cmd[i][j]);
		}
		j = -1;
		free(new->cmd[i]);
	}
	free(new->filename);
	free(new->cmd);
	free(new);
	return (0);
}

int	ft_close_and_free(t_array *new)
{
	close(new->outfd);
	return (0);
}
