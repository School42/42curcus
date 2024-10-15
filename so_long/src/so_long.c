/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:30:25 by talin             #+#    #+#             */
/*   Updated: 2024/10/15 16:29:26 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int ac, char **av)
{
	t_mapping	game;
	int			fd;

	if (ac != 2)
		return (ft_printf("Error: more or less than one arg.\n"));
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (ft_printf("Error: %s\n", strerror(errno)));
	game = ft_creat_game_map(av, fd);
	if (!game.valid)
	{
		ft_free(game);
		return (ft_printf("Error: Not a valid map!\n"));
	}
	else
	{
		ft_game_window(game);
		return (ft_free(game));
	}
}
