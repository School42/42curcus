/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:09:46 by talin             #+#    #+#             */
/*   Updated: 2024/10/07 20:51:55 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_read_size(char *filename)
{
	int		n;
	int		fd;
	char	c;

	n = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		write(2, "map error\n", 10);
		close(fd);
		return (1);
	}
	while (read(fd, &c, 1) > 0)
		n++;
	return (n);
}

int	main(void)
{
	int		fd;
	char	*str;

	fd = open("map.ber", O_RDONLY);
	if (fd == -1)
	{
		ft_printf("map error\n");
		close(fd);
		return (1);
	}
	str = get_next_line(fd);
	ft_printf("%s\n", str);
	while (str == NULL)
	{
		str = get_next_line(fd);
		ft_printf("%s\n", str);
	}
}
