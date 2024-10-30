/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:20:37 by talin             #+#    #+#             */
/*   Updated: 2024/10/30 14:03:01 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct s_array
{
	char	**filename;
	char	***cmd;
	char	**path_arr;
	int		infd;
	int		outfd;
}	t_array;

void	ft_make_array(int ac, char **av, char **envp, t_array *new);
void	ft_make_array_here(int ac, char **av, char **envp, t_array *new);
void	ft_pipe(t_array *new, char **envp, int i);
void	ft_heredoc(int ac, char **av, char **envp);
void	ft_pipex(int ac, char **av, char **envp);
#endif