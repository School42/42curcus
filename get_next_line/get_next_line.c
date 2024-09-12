/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:55:49 by talin             #+#    #+#             */
/*   Updated: 2024/09/12 16:41:41 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_get(int fd, char *line, char *buffer)
{
	ssize_t	n;
	char	*str;

	n = 1;
	while (n > 0 && !(ft_strchr(buffer, '\n')))
	{
		n = read(fd, buffer, BUFFER);
		if (n == -1)
		{
			free(line);
			return (NULL);
		}
		buffer[n] = 0;
		// str[n] = '\0';
		line = ft_strjoin(line, buffer);
		// free(str);
	}
	// free(str);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char	*buffer;
	char	*str;

	buffer = (char *)malloc(sizeof(char) * (BUFFER + 1));
	if (!buffer)
		return (buffer);
	// read(fd, str, BUFFER);
	// printf("%s\n", str);
	line = ft_get(fd, line, buffer);
	return (line);
}
#include <stdio.h>

int	main(void)
{
	int	fd;
	fd = open("doc.txt", O_RDONLY);
	char	*str = get_next_line(fd);
	printf("%s", str);
	return (0);
}