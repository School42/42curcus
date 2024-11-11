/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:20:37 by talin             #+#    #+#             */
/*   Updated: 2024/11/05 15:17:45 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "../libft/libft.h"

typedef struct s_array
{
	char	**filename;
	char	***cmd;
	char	**path_arr;
	int		infd;
	int		outfd;
	int		status;
}	t_array;

int		ft_make_array(int ac, char **av, char **envp, t_array *new);
int		ft_make_array_here(int ac, char **av, char **envp, t_array *new);
void	ft_pipe(t_array *new, char **envp, int i, int ac);
int		ft_heredoc(int ac, char **av, char **envp);
int		ft_pipex(int ac, char **av, char **envp);
int		ft_free_arr(t_array *new, int ac);
int		ft_close_and_free(t_array *new);
void	ft_write_output_one(char **av, int ac);
void	ft_write_output_two(char **av, int ac);
#endif