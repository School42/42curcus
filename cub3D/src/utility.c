/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 11:05:06 by talin             #+#    #+#             */
/*   Updated: 2025/08/28 16:41:43 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int	ft_file_extension(char *filename, char *ext)
{
	char	*extension;

	extension = ft_strrchr(filename, '.');
	if (!extension)
		return (0);
	if (ft_strcmp(extension + 1, ext) != 0)
		return (0);
	return (1);
}

size_t	ft_length_str_arr(char **string_arr)
{
	size_t	i;

	i = 0;
	while (string_arr[i])
	{
		i++;
	}
	return (i);
}

int	is_dir(char *filename)
{
	int	fd;

	fd = open(filename, __O_DIRECTORY);
	if (fd >= 0)
	{
		close(fd);
		return (1);
	}
	return (0);
}

int	ft_file_exist(char *filename)
{
	int	fd;

	if (!ft_file_extension(filename, "xpm"))
		return (error_ft(ERR_FILE_NOT_XPM), 0);
	if (is_dir(filename))
		return (error_ft(ERR_FILE_IS_DIR), 0);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (error_ft(ERR_TEX_OPEN), 0);
	else
		close(fd);
	return (1);
}
