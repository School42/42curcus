/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:20:37 by talin             #+#    #+#             */
/*   Updated: 2024/10/25 14:17:53 by talin            ###   ########.fr       */
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
}	t_array;

#endif