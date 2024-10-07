/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bworrawa <bworrawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:27:41 by bworrawa          #+#    #+#             */
/*   Updated: 2024/09/28 15:35:40 by bworrawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	load_assets(t_game *g)
{
	if (!load_misc_sprites(g))
		sl_exit(g, "Misc sprites error.");
	if (!load_font_sprites(g))
		sl_exit(g, "Font sprites error.");
	render(g);
	return (1);
}

int	read_map(t_game *g, const char *path)
{
	int		fd;
	char	*buf;
	ssize_t	bytes_read;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (sl_exit(g, "Cannot open map file."));
	buf = (char *)malloc(sizeof(char) * (READ_BUF_SIZE + 1));
	if (!buf)
		return (sl_exit(g, "Memory allocation error."));
	bytes_read = read(fd, buf, READ_BUF_SIZE);
	buf[bytes_read] = '\0';
	if (bytes_read >= READ_BUF_SIZE)
	{
		free(buf);
		return (sl_exit(g, "File is larger than file buffer could read."));
	}
	g->map = ft_split(buf, '\n');
	if (!validate_first(g, buf))
	{
		free(buf);
		return (sl_exit(g, "Invalid map."));
	}
	free(buf);
	return (close(fd));
}
