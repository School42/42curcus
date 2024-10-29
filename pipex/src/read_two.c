/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:39:37 by talin             #+#    #+#             */
/*   Updated: 2024/10/29 15:58:27 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	ft_check_access(int ac, char **av, t_array *new)
{
	if (access(av[ac - 1], R_OK) != 0 || access(av[ac - 1], W_OK) != 0)
	{
		new->outfd = open(av[ac -1], O_CREAT | O_RDWR);
		if (new->outfd < 0)
		{
			perror("Error opening file");
			return (-1);
		}
	}
	else
		new->outfd = open(av[ac - 1], O_RDWR);
	if (access(av[1], R_OK) != 0)
	{
		close(new->outfd);
		return (0);
	}
	return (1);
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

int	main(int ac, char **av, char **envp)
{
	t_array	*new;

	if (ac < 2)
		return (ft_printf("Error!\n"));
	if ((ft_strncmp(av[1], "here_doc", 9) != 0))
	{
		new = (t_array *)malloc(sizeof(t_array) * 1);
		ft_make_array(ac, av, envp, new);
		ft_check_access(ac, av, new);
		new->infd = open(av[1], O_RDONLY);
		dup2(new->infd, 0);
		int	i;
		i = -1;
		while (++i < ac - 4)
			ft_pipe(new, envp, i);
		dup2(new->outfd, 1);
		execve(new->filename[i], new->cmd[i], envp);
	}
	else
		ft_printf("here\n");
	ft_printf("good\n");
}
