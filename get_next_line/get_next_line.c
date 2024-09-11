/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:55:49 by talin             #+#    #+#             */
/*   Updated: 2024/09/11 23:36:16 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// char	*get_next_line(int fd);

char	*ft_get(void)
{
	int	fd;
	int	n;
	static char	*str;
	// char	*ptr;

	str = (char *)calloc((BUFFER + 1), sizeof(char));
	fd = open("doc.txt", O_RDONLY);
	read(fd, str, BUFFER);
	return (str);
	// ptr = ft_strdup(str);
	// printf("%s\n", ptr);
	// get_next_line(fd);
}

#include <stdio.h>

int	main(void)
{
	char	*str = ft_get();
	str = ft_get();
	str = ft_get();
	printf("%s\n", str);
}