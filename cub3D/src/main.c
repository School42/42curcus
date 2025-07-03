/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 10:37:04 by talin             #+#    #+#             */
/*   Updated: 2025/07/03 11:08:39 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

int	main(int ac, char **av)
{
	t_data	*data;
	int		fd;

	if (ac != 2)
		return (printf("Error: more or less than one arg.\n"));
	if (!ft_file_extension(av[1], "cub"))
		return (printf("Error: not a supported file extension!\n"));
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (printf("Error: %s\n", strerror(errno)));
	data = ft_create_game_map(av, fd);
	if (!data)
	{
		close(fd);
		return (0);
	}
	// print_map(game.map);
	close(fd);
	(void) data;
	return (0);
}