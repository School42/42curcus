/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:34:38 by talin             #+#    #+#             */
/*   Updated: 2024/11/14 10:30:03 by ubuntu           ###   ########.fr       */
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

void	ft_exit(int n_exit);
int		ft_open_file(char *file, int n);
char	*ft_getenv(char *name, char **envp);
char	*ft_get_path(char *cmd, char **envp);
void	ft_exec(char *cmd, char **envp);
void	ft_free_arr(char **arr);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_exec(char *cmd, char **envp);
void	ft_heredoc_input(char **av, int *p_fd);
void	ft_heredoc(char **av);
void	ft_pipe(char *cmd, char **envp);
#endif