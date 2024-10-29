/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:20:37 by talin             #+#    #+#             */
/*   Updated: 2024/10/29 11:26:02 by talin            ###   ########.fr       */
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
#endif