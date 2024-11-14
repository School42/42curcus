/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:34:38 by talin             #+#    #+#             */
/*   Updated: 2024/11/14 16:51:05 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int ac, char **av, char **env)
{
	t_file	new;

	if (ac < 5)
		ft_exit(1);
	if (ft_strncmp(av[1], "here_doc", 9) == 0)
	{
		if (ac != 6)
			ft_exit(2);
		new.num = 3;
		new.in_fd = 4;
		new.out_fd = ft_open_file(av[ac - 1], 2);
		ft_heredoc(av);
		ft_pipe(av, env, ac - 4, new);
	}
	else
	{
		new.in_fd = ft_open_file(av[1], 0);
		new.out_fd = ft_open_file(av[ac - 1], 1);
		new.num = 2;
		ft_pipe(av, env, ac - 3, new);
	}
}
