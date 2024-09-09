/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:43:13 by talin             #+#    #+#             */
/*   Updated: 2024/09/09 17:12:53 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_usize(unsigned int n)
{
	size_t		i;
	long int	num;

	num = (long int)n;
	i = 0;
	if (num < 0)
	{
		num *= -1;
		i++;
	}
	while (num > 9)
	{
		num /= 10;
		i++;
	}
	if (num < 10)
		i++;
	return (i);
}

char	*ft_uitoa(unsigned int n)
{
	char		*ptr;
	size_t		size;
	long int	num;

	num = (long int)n;
	size = ft_usize(n);
	if (n < 0)
		num *= -1;
	ptr = (char *)malloc(sizeof(char) * (size + 1));
	if (!ptr)
		return (NULL);
	*(ptr + size) = 0;
	while (size--)
	{
		*(ptr + size) = num % 10 + '0';
		num /= 10;
	}
	if (n < 0)
		*(ptr + 0) = '-';
	return (ptr);
}

int	ft_putuint(unsigned int n)
{
	int		len;
	char	*nb;

	nb = ft_uitoa(n);
	len = ft_putstr(nb);
	free(nb);
	return (len);
}
