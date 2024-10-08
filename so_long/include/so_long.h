/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 10:45:00 by talin             #+#    #+#             */
/*   Updated: 2024/10/08 14:15:59 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>
# include "libft.h"

typedef struct s_mapping
{
	char	**map;
	int		num_exit;
	int		num_player;
	int		num_collectible;
	int		map_size;
	int		line_length;
	int		valid;
}	t_mapping;

#endif