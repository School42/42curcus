/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 16:51:30 by talin             #+#    #+#             */
/*   Updated: 2024/09/09 15:56:39 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(char const s, char c)
{
	if (s == c)
		return (1);
	return (0);
}

static int	ft_wordcount(char const *s, char c)
{
	size_t	n;
	size_t	i;

	n = 0;
	i = 0;
	while (s[i])
	{
		while (ft_check(s[i], c) == 1 && s[i])
			i++;
		if (s[i])
			n++;
		while (ft_check(s[i], c) == 0 && s[i])
			i++;
	}
	return (n);
}

static int	ft_size(char const *s, char c, size_t index)
{
	size_t	n;

	n = 0;
	while (s[index])
	{
		if (ft_check(s[index], c) == 0)
		{
			n++;
			index++;
		}
		else
			return (n);
	}
	return (n);
}

static char	*ft_sep(char const *s, char c, size_t index)
{
	size_t	i;
	size_t	n;
	size_t	j;
	char	*ptr;

	i = 0;
	n = ft_size(s, c, index);
	ptr = (char *)malloc(sizeof(char) * (n + 1));
	if (!ptr)
		return (NULL);
	j = index + n;
	while (index < j)
	{
		if (ft_check(s[index], c) == 0)
			ptr[i] = (unsigned char) s[index];
		i++;
		index++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	ptr = (char **)malloc(sizeof(char *) * (ft_wordcount(s, c) + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (ft_check(s[i], c) == 1 && s[i])
			i++;
		if (s[i])
		{
			ptr[j] = ft_sep(s, c, i);
			j++;
		}
		while (ft_check(s[i], c) == 0 && s[i])
			i++;
	}
	ptr[j] = 0;
	return (ptr);
}
/*
#include <stdio.h>

int	main()
{
	char	str[] = "lorem Sed non risus. Suspendisse";
	char	**ptr = ft_split(str, ' ');
	size_t	n = ft_wordcount(str, ' ');
	printf("n: %zu\n", n);
	for (size_t i = 0; i < n; i++)
	{
		printf("%s\n", ptr[i]);
	}
}
*/
