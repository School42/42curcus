/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_four.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:54:44 by talin             #+#    #+#             */
/*   Updated: 2024/11/16 09:19:48 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	ft_check_last_cmd(char *cmd, char **envp)
{
	char	**s_cmd;
	char	*path;
	int		i;

	s_cmd = ft_split(cmd, ' ');
	path = ft_get_path(s_cmd[0], envp, -1);
	if (access(path, F_OK) == 0)
	{
		if (access(path, X_OK) == 0)
			i = 0;
		else
			i = 126;
	}
	else
		i = 127;
	ft_free_arr(s_cmd);
	if (path != s_cmd[0])
		free(path);
	return (i);
}

int	ft_exitcode(int ac, char **av, char **envp, t_file *new)
{
	if (new->exitcode != 1)
		new->exitcode = ft_check_last_cmd(av[ac - 2], envp);
	return (new->exitcode);
}
