/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:39:37 by talin             #+#    #+#             */
/*   Updated: 2024/11/04 16:33:21 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	ft_check_access(int ac, char **av, t_array *new)
{
	if (access(av[1], R_OK) != 0 || access(av[1], F_OK) != 0)
	{
		return (0);
	}
	if (access(av[ac - 1], F_OK) != 0)
	{
		new->outfd = open(av[ac -1], O_CREAT | O_WRONLY | O_TRUNC);
		if (new->outfd < 0)
		{
			perror("Error opening file");
			close(new->outfd);
			return (0);
		}
	}
	else
	{
		new->outfd = open(av[ac - 1], O_WRONLY | O_TRUNC);
		if (new->outfd < 0)
		{
			close(new->outfd);
			perror("Error opening file");
			return (0);
		}
	}
	return (1);
}

int	ft_check_access_here(int ac, char **av, t_array *new)
{
	if (access(av[ac - 1], F_OK) != 0)
	{
		new->outfd = open(av[ac - 1], O_CREAT | O_RDWR | O_APPEND);
		if (new->outfd < 0)
		{
			close(new->outfd);
			perror("Error opening file");
			return (0);
		}
	}
	else
	{
		new->outfd = open(av[ac - 1], O_RDWR | O_APPEND);
		if (new->outfd < 0)
		{
			close(new->outfd);
			perror("Error opening file");
			return (0);
		}
	}
	return (1);
}

char	*remove_newline(char *s)
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
	return (ptr);
}

int	ft_pipex(int ac, char **av, char **envp)
{
	t_array	*new;
	int		i;

	new = (t_array *)malloc(sizeof(t_array) * 1);
	if (!ft_check_access(ac, av, new))
		return (0);
	if (!ft_make_array(ac, av, envp, new))
	{
		close(new->outfd);
		free(new);
		return (0);
	}
	new->infd = open(av[1], O_RDONLY);
	dup2(new->infd, 0);
	i = -1;
	while (++i < ac - 4)
		ft_pipe(new, envp, i);
	dup2(new->outfd, 1);
	execve(new->filename[i], new->cmd[i], envp);
	return (1);
}

int	ft_heredoc(int ac, char **av, char **envp)
{
	t_array	*new;
	int		i;
	char	*str;

	new = (t_array *)malloc(sizeof(t_array) * 1);
	if (!ft_check_access_here(ac, av, new))
		return (0);
	while (1)
	{
		str = remove_newline(get_next_line(0));
		if (ft_strncmp(av[2], remove_newline(str), \
		(int)ft_strlen(av[2]) + 1) == 0)
			break ;
	}
	free(str);
	if (!ft_make_array_here(ac, av, envp, new))
	{
		close(new->outfd);
		free(new);
		return (0);
	}
	i = -1;
	while (++i < ac - 5)
		ft_pipe(new, envp, i);
	dup2(new->outfd, 1);
	execve(new->filename[i], new->cmd[i], envp);
	return (1);
}
