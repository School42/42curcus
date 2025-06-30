/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 10:37:04 by talin             #+#    #+#             */
/*   Updated: 2025/06/30 13:30:45 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

int	main(int ac, char **av)
{
	t_game_map	game;
	int			fd;

	if (ac != 2)
		return (printf("Error: more or less than one arg.\n"));
	if (!ft_file_extension(av[1]))
		return (printf("Error: not a supported file extension!\n"));
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (printf("Error: %s\n", strerror(errno)));
	game = ft_create_game_map(av, fd);
	print_map(game.map);
	close(fd);
	(void) game;
	return (0);
}