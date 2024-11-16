/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:00:40 by talin             #+#    #+#             */
/*   Updated: 2024/11/16 12:07:26 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
/*
#include <stdio.h>

int     main()
{
        t_list  *head;
        t_list  *ptr;
	t_list	*new;

        head = ft_lstnew("hello");
        ptr = ft_lstnew("world");
	new = ft_lstnew("kernel");
        head->next = ptr;
	ft_lstadd_front(&head, new);
	while (head != NULL)
	{
		printf("%s\n", (char *)head->content);
		head = head->next;
	}
}
*/
