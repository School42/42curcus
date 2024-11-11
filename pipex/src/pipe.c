/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:34:38 by talin             #+#    #+#             */
/*   Updated: 2024/11/05 16:48:52 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_pipe(t_array *new, char **envp, int i, int ac)
{
	pid_t	pid;
	int		pd[2];

	if (pipe(pd) == -1)
	{
		ft_free_arr(new, ac);
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if (pid == -1)
	{
		ft_free_arr(new, ac);
		exit(EXIT_FAILURE);
	}
	if (!pid)
	{
		close(pd[0]);
		dup2(pd[1], 1);
		if (execve(new->filename[i], new->cmd[i], envp) == -1)
		{
			perror("Command not found!\n");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		close(pd[1]);
		dup2(pd[0], 0);
		close(pd[0]);
		waitpid(pid, NULL, 0);
	}
}
