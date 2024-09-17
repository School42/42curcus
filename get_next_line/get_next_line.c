/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:55:49 by talin             #+#    #+#             */
/*   Updated: 2024/09/17 15:33:04 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*next_line(char *buffer)
{
	int		i;
	char	*str;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	str = (char *)malloc((i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		str[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		str[i] = buffer[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*new_line(char *buffer)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(buffer) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (buffer[i])
		str[j++] = buffer[i++];
	str[j] = '\0';
	free(buffer);
	// buffer = NULL;
	if (!buffer)
		printf("BUFFER\n");
	return (str);
}

char	*read_line(int fd, char *buffer)
{
	char	*ptr;
	ssize_t	n;

	ptr = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!ptr)
		return (NULL);
	n = 1;
	while (!ft_strchr(buffer, '\n') && n > 0)
	{
		n = read(fd, ptr, BUFFER_SIZE);
		if (n == -1)
		{
			free(ptr);
			return (NULL);
		}
		ptr[n] = '\0';
		buffer = ft_strjoin(buffer, ptr);
	}
	free(ptr);
	if (!ptr)
		printf("POINTER\n");
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
	{
		buffer = (char *)malloc(1 * sizeof(char));
		buffer[0] = '\0';
	}
	buffer = read_line(fd, buffer);
	if (!buffer)
		return (NULL);
	str = next_line(buffer);
	buffer = new_line(buffer);
	free(buffer);
	return (str);
}

int	main()
{
	int	fd;
	char	*str;

	fd = open("doc.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("%s", str);
	str = get_next_line(fd);
	printf("%s", str);
	// str = get_next_line(fd);
	// printf("%s", str);
	// str = get_next_line(fd);
	// printf("%s", str);
	// str = get_next_line(fd);
	// printf("%s", str);

	if (str)
	{
		free(str);
	}
	if (!str)
		printf("NO LEAK from main!!!\n");
	return (0);
}