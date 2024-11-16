/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:34:38 by talin             #+#    #+#             */
/*   Updated: 2024/11/15 15:48:19 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_exec(char *cmd, char **envp)
{
	char	**s_cmd;
	char	*path;

	s_cmd = ft_split(cmd, ' ');
	path = ft_get_path(s_cmd[0], envp, -1);
	if (execve(path, s_cmd, envp) == -1)
	{
		if (access(path, F_OK) == 0)
			ft_putstr_fd("permission denied: ", 2);
		else
			ft_putstr_fd("command not found: ", 2);
		ft_putendl_fd(s_cmd[0], 2);
		ft_free_arr(s_cmd);
		exit(127);
	}
}

void	ft_execute_cmd(char *cmd, char **envp, t_file *pipe_new)
{
	if (pipe_new->in_fd != STDIN_FILENO)
	{
		if (dup2(pipe_new->in_fd, STDIN_FILENO) == -1)
			exit(EXIT_FAILURE);
		close(pipe_new->in_fd);
	}
	if (pipe_new->out_fd != STDOUT_FILENO)
	{
		if (dup2(pipe_new->out_fd, STDOUT_FILENO) == -1)
			exit(EXIT_FAILURE);
		close(pipe_new->out_fd);
	}
	ft_exec(cmd, envp);
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

void	ft_heredoc_input(char **av, int *p_fd)
{
	char	*str;
	char	*ptr;

	close(p_fd[0]);
	ft_putstr_fd("> ", 1);
	while (1)
	{
		str = get_next_line(0);
		ptr = ft_strdup(str);
		ptr = ft_remove_newline(ptr);
		if (ft_strncmp(ptr, av[2], ft_strlen(av[2]) + 1) == 0)
		{
			free(str);
			free(ptr);
			exit(0);
		}
		ft_putstr_fd("> ", 1);
		ft_putstr_fd(str, p_fd[1]);
		free(str);
		free(ptr);
	}
}

void	ft_heredoc(char **av)
{
	int		p_fd[2];
	pid_t	pid;

	if (pipe(p_fd) == -1)
		exit(0);
	pid = fork();
	if (pid == -1)
		exit(0);
	if (!pid)
		ft_heredoc_input(av, p_fd);
	else
	{
		close(p_fd[1]);
		dup2(p_fd[0], 0);
		wait(NULL);
	}
}
