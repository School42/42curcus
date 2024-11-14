/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:18:11 by talin             #+#    #+#             */
/*   Updated: 2024/11/14 10:29:11 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int ac, char **av, char **env)
{
	int		i;
	int		fd_in;
	int		fd_out;

	if (ac != 5)
		ft_exit(1);
	i = 2;
	fd_in = ft_open_file(av[1], 0);
	fd_out = ft_open_file(av[ac - 1], 1);
	dup2(fd_in, 0);
	while (i < ac - 2)
		ft_pipe(av[i++], env);
	dup2(fd_out, 1);
	ft_exec(av[ac - 2], env);
}
