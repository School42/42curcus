/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 13:05:27 by talin             #+#    #+#             */
/*   Updated: 2025/07/01 16:12:56 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

char	*concat(const char *s1, const char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*res;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	res = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!res)
		return (NULL);
	i = -1;
	while (++i < len1)
		res[i] = s1[i];
	j = -1;
	while (++j < len2)
		res[i + j] = s2[j];
	res[i + j] = 0;
	return (res);
}

int	ft_size_map(char *filename)
{
	int		line;
	char	*str;
	int		fd;

	line = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	str = get_next_line(fd);
	line++;
	while (str != NULL)
	{
		free(str);
		str = get_next_line(fd);
		if (str != NULL)
			line++;
	}
	return (line);
}

char	*ft_strdup_cu(const char *s)
{
	char	*ptr;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	i = ft_strlen(s);
	ptr = (char *)malloc((i + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

void	ft_finding_pos_map(t_data *data)
{
	int	x;

	x = data->map->ln_count - 1;
	while (x > 0)
	{
		if (ft_strcmp(data->map->map[x], "") != 0)
			break;
		x--;
	}
	data->map->end = x;
	while (x > 0)
	{
		if (ft_strcmp(data->map->map[x], "") == 0)
			break;
		x--;
	}
	data->map->start = x + 1;
}

int	ft_find_longest_length(t_data *data)
{
	int	max;
	int	j;

	max = 0;
	j = data->map->start;
	while (j <= data->map->end)
	{
		if ((int)ft_strlen(data->map->map[j]) > max)
			max = (int)ft_strlen(data->map->map[j]);
		j++;
	}
	return (max);
}