/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:34:38 by talin             #+#    #+#             */
/*   Updated: 2024/11/15 15:55:28 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_pipe_support(t_file *pipe_new, t_file *new, char **cmd, char **envp)
{
	if (pipe_new->i == 0)
		pipe_new->in_fd = new->in_fd;
	else
		pipe_new->in_fd = pipe_new->prev_pipe;
	if (pipe_new->i == new->size - 1)
		pipe_new->out_fd = new->out_fd;
	else
		pipe_new->out_fd = pipe_new->pipes[1];
	if (pipe_new->i < new->size - 1)
		close(pipe_new->pipes[0]);
	ft_execute_cmd(cmd[pipe_new->i + new->num], envp, \
	pipe_new);
}

void	ft_pipe_main(char **cmd, char **envp, t_file new, pid_t *pids)
{
	t_file	pipe_new;

	pipe_new.i = -1;
	pipe_new.prev_pipe = -1;
	while (++pipe_new.i < new.size)
	{
		if (pipe_new.i < new.size - 1)
		{
			if (pipe(pipe_new.pipes) == -1)
				exit(EXIT_FAILURE);
		}
		pids[pipe_new.i] = fork();
		if (pids[pipe_new.i] == -1)
			exit(EXIT_FAILURE);
		if (pids[pipe_new.i] == 0)
			ft_pipe_support(&pipe_new, &new, cmd, envp);
		if (pipe_new.i > 0)
			close(pipe_new.prev_pipe);
		if (pipe_new.i < new.size - 1)
		{
			close(pipe_new.pipes[1]);
			pipe_new.prev_pipe = pipe_new.pipes[0];
		}
	}
}

void	ft_pipe(char **cmd, char **envp, t_file new)
{
	pid_t	pids[1024];
	int		status;
	int		i;

	ft_pipe_main(cmd, envp, new, pids);
	close(new.in_fd);
	close(new.out_fd);
	i = -1;
	while (++i < new.size)
		waitpid(pids[i], &status, 0);
}

int	ft_check_set_unset(char **envp)
{
	int	i;

	i = -1;
	while (envp[++i])
	{
		if (ft_strncmp(envp[i], "PATH=/", 6) == 0)
			return (1);
	}
	return (0);
}
