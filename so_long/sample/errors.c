/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bworrawa <bworrawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 18:57:39 by bworrawa          #+#    #+#             */
/*   Updated: 2024/09/27 16:42:28 by bworrawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_exit(t_game *g, char *message)
{
	if (message)
		ft_printf("Error: %s\n", message);
	else
		ft_printf("\n");
	cleanup_all(g);
	exit (-1);
	return (1);
}

int	sl_clean_exit(t_game *g, char *message)
{
	if (message)
		ft_printf("%s\n", message);
	else
		ft_printf("\n");
	cleanup_all(g);
	exit (0);
	return (1);
}
