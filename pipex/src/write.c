/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:16:23 by talin             #+#    #+#             */
/*   Updated: 2024/11/11 15:39:00 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_write_output_one(char **av, int ac)
{
	int	fd;

	if (access(av[ac - 1], F_OK) != 0)
	{
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

void	ft_write_output_two(char **av, int ac)
{
	int	fd;

	if (access(av[ac - 1], F_OK) != 0)
	{
		fd = open(av[ac - 1], O_CREAT | O_RDWR | O_TRUNC);
		if (fd < 0)
		{
			perror("Error opening file");
			close(fd);
			return ;
		}
	}
	else
	{
		fd = open(av[ac - 1], O_RDWR | O_TRUNC);
		if (fd < 0)
		{
			close(fd);
			perror("Error opening file");
			return ;
		}
	}
	write(fd, "", 0);
}
