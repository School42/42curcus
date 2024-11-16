/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:34:38 by talin             #+#    #+#             */
/*   Updated: 2024/11/15 15:51:20 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	ft_open_infile(char *file, t_file *new)
{
	int	fd;

	if (access(file, R_OK) != 0 || access(file, F_OK) != 0)
	{
		if (access(file, F_OK) != 0)
			ft_printf("%s: No such file or directory\n", file);
		else
			ft_printf("%s: permission denied\n", file);
		new->exitcode = 1;
		fd = 4;
	}
	else
		fd = open(file, O_RDONLY, 0777);
	return (fd);
}

int	ft_open_file(char *file, int in_or_out, t_file *new)
{
	int	fd;

	if (in_or_out == 0)
		fd = ft_open_infile(file, new);
	if (in_or_out == 1)
	{
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
		if (access(file, W_OK) != 0)
			ft_printf("%s: Permission denied\n", file);
	}
	if (in_or_out == 2)
	{
		fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0777);
		if (access(file, W_OK) != 0)
			ft_printf("%s: Permission denied\n", file);
	}
	if (fd == -1)
	{
		new->exitcode = 1;
		exit(EXIT_FAILURE);
	}
	return (fd);
}

void	ft_free_arr(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char	*ft_getenv(char *name, char **envp)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (envp[i])
	{
		j = 0;
		while (envp[i][j] && envp[i][j] != '=')
			j++;
		str = ft_substr(envp[i], 0, j);
		if (ft_strcmp(str, name) == 0)
		{
			free(str);
			return (envp[i] + j + 1);
		}
		free(str);
		i++;
	}
	return (NULL);
}

char	*ft_get_path(char *cmd, char **envp, int i)
{
	char	*exec;
	char	**allpath;
	char	*path_part;
	char	**s_cmd;

	if (ft_check_set_unset(envp) == 0)
		return (cmd);
	allpath = ft_split(ft_getenv("PATH", envp), ':');
	s_cmd = ft_split(cmd, ' ');
	while (allpath[++i])
	{
		path_part = ft_strjoin(allpath[i], "/");
		exec = ft_strjoin(path_part, s_cmd[0]);
		free(path_part);
		if (access(exec, F_OK | X_OK) == 0)
		{
			ft_free_arr(allpath);
			ft_free_arr(s_cmd);
			return (exec);
		}
		free(exec);
	}
	ft_free_arr(allpath);
	ft_free_arr(s_cmd);
	return (cmd);
}
