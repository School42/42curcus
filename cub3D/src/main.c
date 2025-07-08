/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 10:37:04 by talin             #+#    #+#             */
/*   Updated: 2025/07/08 13:27:40 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

int	main(int ac, char **av)
{
	t_data	*data;
	int		fd;

	if (ac != 2)
		return (error_ft(ERR_USAGE), 1);
	if (!ft_file_extension(av[1], "cub"))
		return (error_ft(ERR_FILE_NOT_CUB), 1);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (printf("Error\n%s\n", strerror(errno)));
	data = ft_create_game_map(av, fd);
	if (!data)
	{
		free_data(data);
		close(fd);
		return (1);
	}
	render_game(data);
	free_data(data);
	close(fd);
	return (0);
}
