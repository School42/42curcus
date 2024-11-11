/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:20:07 by talin             #+#    #+#             */
/*   Updated: 2024/11/05 14:40:22 by talin            ###   ########.fr       */
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

void	ft_cat(t_array *new, int j, char **av, int k)
{
	int		i;

	i = -1;
	new->cmd[j] = ft_split(av[j + k], ' ');
	while (new->path_arr[++i] != NULL)
	{
		new->path_arr[i] = ft_strjoin_gnl(new->path_arr[i], "/");
		new->path_arr[i] = ft_strjoin_gnl(new->path_arr[i], \
		new->cmd[j][0]);
		if (access(new->path_arr[i], X_OK) == 0)
		{
			free(new->cmd[j][0]);
			new->cmd[j][0] = ft_strdup(new->path_arr[i]);
			new->filename[j] = ft_strdup(new->path_arr[i]);
			break ;
		}
	}
	i = -1;
	while (new->path_arr[++i])
		free(new->path_arr[i]);
	free(new->path_arr);
}

int	ft_make_array(int ac, char **av, char **envp, t_array *new)
{
	int	i;

	new->cmd = (char ***)malloc(sizeof(char **) * (ac - 2));
	new->filename = (char **)malloc(sizeof(char *) * (ac - 2));
	if (!new->cmd || !new->filename)
		return (0);
	i = -1;
	while (++i < ac - 3)
	{
		if (av[i + 2][0] == '/' || av[i + 2][0] == '.')
		{
			new->cmd[i] = ft_split(av[i + 2], ' ');
			if (access(new->cmd[i][0], X_OK) == 0)
				new->filename[i] = ft_strdup(new->cmd[i][0]);
		}
		else
		{
			new->path_arr = ft_path_arr(envp);
			ft_cat(new, i, av, 2);
		}
	}
	if (access(new->cmd[i - 1][0], X_OK) != 0)
		return (ft_free_arr(new, ac));
	return (1);
}

int	ft_make_array_here(int ac, char **av, char **envp, t_array *new)
{
	int	i;

	new->cmd = (char ***)malloc(sizeof(char **) * (ac - 3));
	new->filename = (char **)malloc(sizeof(char *) * (ac - 3));
	if (!new->cmd || !new->filename)
		return (0);
	i = -1;
	while (++i < ac - 4)
	{
		if (av[i + 3][0] == '/' || av[i + 3][0] == '.')
		{
			new->cmd[i] = ft_split(av[i + 3], ' ');
			if (access(new->cmd[i][0], X_OK) == 0)
				new->filename[i] = ft_strdup(new->cmd[i][0]);
		}
		else
		{
			new->path_arr = ft_path_arr(envp);
			ft_cat(new, i, av, 2);
		}
	}
	if (access(new->cmd[i - 1][0], X_OK) != 0)
		return (ft_free_arr(new, ac - 1));
	return (1);
}
