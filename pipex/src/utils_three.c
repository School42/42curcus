/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:34:38 by talin             #+#    #+#             */
/*   Updated: 2024/11/14 16:38:20 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_exec(char *cmd, char **envp, int ext)
{
	char	**s_cmd;
	char	*path;

	s_cmd = ft_split(cmd, ' ');
	path = ft_get_path(s_cmd[0], envp);
	if (execve(path, s_cmd, envp) == -1)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(s_cmd[0], 2);
		ft_free_arr(s_cmd);
		if (ext == 1)
			exit(127);
		else if (ext == 0)
			exit(0);
	}
}

void	ft_execute_cmd(char *cmd, char **envp, t_file pipe_new, int ext)
{
	if (pipe_new.in_fd != STDIN_FILENO)
	{
		if (dup2(pipe_new.in_fd, STDIN_FILENO) == -1)
			exit(EXIT_FAILURE);
		close(pipe_new.in_fd);
	}
	if (pipe_new.out_fd != STDOUT_FILENO)
	{
		if (dup2(pipe_new.out_fd, STDOUT_FILENO) == -1)
			exit(EXIT_FAILURE);
		close(pipe_new.out_fd);
	}
	ft_exec(cmd, envp, ext);
}

char	*ft_remove_newline(char *s)
{
	char	*ptr;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	i = ft_strlen(s);
	ptr = (char *)malloc((i + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	free(s);
	return (ptr);
}

void	ft_heredoc_input(char **av)
{
	char	*str;

	while (1)
	{
		str = ft_remove_newline(get_next_line(0));
		if (ft_strncmp(str, av[2], ft_strlen(av[2]) + 1) == 0)
		{
			free(str);
			exit(0);
		}
		// ft_putstr_fd(str, p_fd[1]);
		free(str);
	}
}

void	ft_heredoc(char **av)
{
	// int		p_fd[2];
	// pid_t	pid1;
	// pid_t	pid2;

	// if (pipe(p_fd) == -1)
	// 	exit(0);
	ft_heredoc_input(av);
	// pid1 = fork();
	// pid = fork();
	// if (pid == -1)
	// 	exit(0);
	// if (!pid)
	// 	ft_heredoc_input(av, p_fd);
	// else
	// {
	// 	close(p_fd[1]);
	// 	dup2(p_fd[0], 0);
	// 	wait(NULL);
	// }
}

void	ft_pipe(char **cmd, char **envp, int size, t_file new)
{
	pid_t	*pids;
	int		pipes[2];
	int		i;
	int		prev_pipe;
	t_file	pipe_new;

	prev_pipe = -1;
	pids = malloc(sizeof(pid_t) * size);
	if (!pids)
		exit(EXIT_FAILURE);
	i = -1;
	while (++i < size)
	{
		if (i < size - 1)
		{
			if (pipe(pipes) == -1)
				exit(EXIT_FAILURE);
		}
		pids[i] = fork();
		if (pids[i] == -1)
			exit(EXIT_FAILURE);
		if (pids[i] == 0)
		{
			if (i == 0)
				pipe_new.in_fd = new.in_fd;
			else
				pipe_new.in_fd = prev_pipe;
			if (i == size - 1)
				pipe_new.out_fd = new.out_fd;
			else
				pipe_new.out_fd = pipes[1];
			if (i < size - 1)
				close(pipes[0]);
			ft_execute_cmd(cmd[i + new.num], envp, pipe_new, (i == size - 1));
		}
		if (i > 0)
			close(prev_pipe);
		if (i < size - 1)
		{
			close(pipes[1]);
			prev_pipe = pipes[0];
		}
	}
	close(new.in_fd);
	close(new.out_fd);
	i = -1;
	while (++i < size)
		waitpid(pids[i], &pipe_new.status, 0);
	free(pids);
}
