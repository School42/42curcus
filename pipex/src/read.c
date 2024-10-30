/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:20:07 by talin             #+#    #+#             */
/*   Updated: 2024/10/30 14:02:21 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
#include <stdlib.h>

int	ft_getting_path(char *str)
{
	if (ft_strlen(str) >= 5)
	{
		if (!ft_strncmp(str, "PATH=", 5))
			return (1);
	}
	return (0);
}

char	**ft_path_arr(char **envp)
{
	int		i;
	char	**path_arr;
	char	*path1;
	char	*path2;

	i = -1;
	while (envp[++i] != NULL)
	{
		if (ft_getting_path(envp[i]))
			path1 = ft_strdup(envp[i]);
	}
	path2 = ft_strtrim(path1, "PATH=");
	path_arr = ft_split(path2, ':');
	free(path1);
	free(path2);
	return (path_arr);
}

void	ft_make_array(int ac, char **av, char **envp, t_array *new)
{
	int		i;
	int		j;

	new->cmd = (char ***)malloc(sizeof(char **) * (ac - 2));
	new->filename = (char **)malloc(sizeof(char *) * (ac - 2));
	j = -1;
	while (++j < (ac - 3))
	{
		i = -1;
		new->path_arr = ft_path_arr(envp);
		new->cmd[j] = ft_split(av[j + 2], ' ');
		while (new->path_arr[++i] != NULL)
		{
			ft_strlcat(new->path_arr[i], "/", ft_strlen(new->path_arr[i]) + 2);
			ft_strlcat(new->path_arr[i], new->cmd[j][0], \
			ft_strlen(new->path_arr[i]) + ft_strlen(new->cmd[j][0]) + 1);
			if (access(new->path_arr[i], X_OK) == 0)
			{
				new->filename[j] = ft_strdup(new->path_arr[i]);
				new->cmd[j][0] = ft_strdup(new->path_arr[i]);
				break ;
			}
		}
	}
}

void	ft_make_array_here(int ac, char **av, char **envp, t_array *new)
{
	int		i;
	int		j;

	new->cmd = (char ***)malloc(sizeof(char **) * (ac - 3));
	new->filename = (char **)malloc(sizeof(char *) * (ac - 3));
	j = -1;
	while (++j < (ac - 4))
	{
		i = -1;
		new->path_arr = ft_path_arr(envp);
		new->cmd[j] = ft_split(av[j + 3], ' ');
		while (new->path_arr[++i] != NULL)
		{
			ft_strlcat(new->path_arr[i], "/", ft_strlen(new->path_arr[i]) + 2);
			ft_strlcat(new->path_arr[i], new->cmd[j][0], \
			ft_strlen(new->path_arr[i]) + ft_strlen(new->cmd[j][0]) + 1);
			if (access(new->path_arr[i], X_OK) == 0)
			{
				new->filename[j] = ft_strdup(new->path_arr[i]);
				new->cmd[j][0] = ft_strdup(new->path_arr[i]);
				break ;
			}
		}
	}
}

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
		execve(new->filename[i], new->cmd[i], envp);
	}
	else
	{
		close(pd[1]);
		dup2(pd[0], 0);
	}
}
