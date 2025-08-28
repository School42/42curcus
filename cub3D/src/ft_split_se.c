/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_se.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 16:51:30 by talin             #+#    #+#             */
/*   Updated: 2025/08/28 16:18:07 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

static size_t	ft_substr_count(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 1;
	while (s[i])
	{
		if (s[i] == c)
			count++;
		i++;
	}
	return (count);
}

static size_t	ft_substr_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}

static char	**ft_free(char **str, int i)
{
	while (i >= 0)
		free(str[i--]);
	free(str);
	return (NULL);
}

char	*ft_substr_se(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	char	*tmp;
	size_t	i;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (s == NULL || s_len < start || len == 0)
		return (ft_strdup(""));
	if (start + len < s_len)
		ptr = (char *)malloc((len + 1) * sizeof(char));
	else
		ptr = (char *)malloc((s_len - start + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	i = start;
	tmp = ptr;
	while (i < (start + len) && s[i])
		*tmp++ = *(s + i++);
	*tmp = '\0';
	return (ptr);
}

char	**ft_split_se(char const *s, char c)
{
	char	**str;
	size_t	i;
	size_t	j;
	size_t	len;

	str = (char **) malloc((ft_substr_count(s, c) + 1) * sizeof(char *));
	if (!s || !str)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		len = ft_substr_len(&s[i], c);
		str[j] = ft_substr_se(s, i, len);
		if (!str[j])
			return (ft_free(str, j));
		i += len;
		j++;
		if (s[i] == c)
			i++;
	}
	if (s[i - 1] == c)
		str[j++] = ft_strdup("");
	str[j] = NULL;
	return (str);
}
