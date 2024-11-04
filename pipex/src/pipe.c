/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:34:38 by talin             #+#    #+#             */
/*   Updated: 2024/11/04 22:33:47 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_pipe(t_array *new, char **envp, int i)
{
	pid_t	pid;
	int		pd[2];

	if (pipe(pd) == -1)
		exit(0);
	pid = fork();
	if (pid == -1)
		exit(0);
	if (!pid)
	{
		close(pd[0]);
		dup2(pd[1], 1);
		if (execve(new->filename[i], new->cmd[i], envp) == -1)
		{
			perror("Execution Error");
			return ;
		}
	}
	else
	{
		close(pd[1]);
		dup2(pd[0], 0);
	}
}
