/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:01:49 by talin             #+#    #+#             */
/*   Updated: 2024/11/04 16:44:16 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_write_output(char **av, int ac, int x)
{
	int	fd;

	if (access(av[ac - 1], F_OK) != 0)
	{
		if (x == 0)
			fd = open(av[ac -1], O_CREAT | O_WRONLY | O_TRUNC);
		else
			fd = open(av[ac - 1], O_CREAT | O_RDWR | O_APPEND);
		if (fd < 0)
		{
			perror("Error opening file");
			close(fd);
			return ;
		}
	}
	else
	{
		if (x == 0)
			fd = open(av[ac - 1], O_WRONLY | O_TRUNC);
		else
			fd = open(av[ac - 1], O_RDWR | O_APPEND);
		if (fd < 0)
		{
			close(fd);
			perror("Error opening file");
			return ;
		}
	}
	write(fd, "", 0);
}

int	main(int ac, char **av, char **envp)
{
	if (ac < 5)
		return (ft_printf("Error!\n"));
	if ((ft_strncmp(av[1], "here_doc", 9) != 0))
	{
		if (!ft_pipex(ac, av, envp))
		{
			ft_write_output(av, ac, 0);
			ft_printf("Error\n");
			return (0);
		}
	}
	else
	{
		if (!ft_heredoc(ac, av, envp))
		{
			ft_write_output(av, ac, 1);
			ft_printf("Error\n");
			return (0);
		}
	}
}
