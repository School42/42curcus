/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:55:43 by talin             #+#    #+#             */
/*   Updated: 2024/11/16 12:08:27 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int content)
{
	t_list	*result;

	result = (t_list *)malloc(sizeof(t_list));
	if (!result)
		return (NULL);
	result->content = content;
	result->next = NULL;
	return (result);
}
/*
#include <stdio.h>

int	main()
{
	t_list	*head;
	t_list	*ptr;

	head = ft_lstnew("hello");
	ptr = ft_lstnew("world");
	head->next = ptr;
	while (head != NULL)
	{
		printf("%s\n", (char *)head->content);
		head = head->next;
	}
}
*/
