/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:01:49 by talin             #+#    #+#             */
/*   Updated: 2024/10/30 14:02:13 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int ac, char **av, char **envp)
{

	if (ac < 2)
		return (ft_printf("Error!\n"));
	if ((ft_strncmp(av[1], "here_doc", 9) != 0))
	{
		ft_pipex(ac, av, envp);
	}
	else
	{
		ft_heredoc(ac, av, envp);
	}
}
