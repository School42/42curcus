/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:20:07 by talin             #+#    #+#             */
/*   Updated: 2024/10/29 14:35:53 by talin            ###   ########.fr       */
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

// int	main(int ac, char **av, char **envp)
// {
// 	(void)	ac;
// 	t_array	new;

// 	new = ft_make_array(ac, av, envp);
	// int i = 0;
	// int j;
	// while (i < ac - 1)
	// {
	// 	j = 0;
	// 	while (new.cmd[i][j] != NULL)
	// 	{
	// 		ft_printf("%s\n", new.cmd[i][j]);
	// 		j++;
	// 	}
	// 	ft_printf("==> %s\n", new.filename[i]);
	// 	i++;
	// }
// 	execve(new.filename[0], new.cmd[0], envp);
// }
