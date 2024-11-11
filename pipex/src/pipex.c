/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:18:11 by talin             #+#    #+#             */
/*   Updated: 2024/11/11 15:38:44 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int ac, char **av, char **envp)
{
	if (ac != 5)
		return (ft_printf("./pipex infile cmd cmd1 outfile\n"));
	if (!ft_pipex(ac, av, envp))
	{
		ft_write_output_one(av, ac);
		ft_printf("Error\n");
		return (1);
	}
	return (0);
}
