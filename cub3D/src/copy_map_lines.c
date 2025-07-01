/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 16:16:23 by talin             #+#    #+#             */
/*   Updated: 2025/07/01 16:26:58 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

char	*copy_map_lines(int size, char *src)
{
	char	*line;
	int		i;

	if (size <= 0 || !src)
		return (NULL);
	line = (char *)malloc(sizeof(char) * size + 1);
	if (!line)
		return (NULL);
	i = -1;
	while (src[++i])
		line[i] = src[i];
	if (i < size)
	{
		while (i < size)
		{
			line[i] = ' ';
			i++;
		}
	}
	line[i] = 0;
	return (line);
}