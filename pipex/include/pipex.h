/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:34:38 by talin             #+#    #+#             */
/*   Updated: 2024/11/15 13:20:37 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <errno.h>
# include <stdio.h>

typedef struct s_file
{
	int	in_fd;
	int	out_fd;
	int	num;
	int	i;
	int	size;
	int	prev_pipe;
	int	pipes[2];
	int	exitcode;
}	t_file;

void	ft_exit(int n_exit);
int		ft_open_file(char *file, int n, t_file *new);
char	*ft_getenv(char *name, char **envp);
char	*ft_get_path(char *cmd, char **envp, int i);
void	ft_free_arr(char **arr);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_exec(char *cmd, char **envp);
void	ft_execute_cmd(char *cmd, char **envp, t_file *pipe_new);
void	ft_heredoc_input(char **av, int *p_fd);
void	ft_heredoc(char **av);
void	ft_pipe(char **cmd, char **envp, t_file new);
int		ft_check_set_unset(char **envp);
int		ft_check_last_cmd(char *cmd, char **envp);
int		ft_exitcode(int ac, char **av, char **envp, t_file *new);
#endif