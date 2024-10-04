/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:28:33 by talin             #+#    #+#             */
/*   Updated: 2024/09/09 16:22:44 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;

	if (lst)
	{
		if (*lst)
		{
			ptr = ft_lstlast(*lst);
			ptr->next = new;
		}
		else
			*lst = new;
	}
}
/*
#include <stdio.h>

int     main()
{
        t_list  *head;
        t_list  *ptr;
        t_list  *new;

        head = ft_lstnew("hello");
        ptr = ft_lstnew("world");
        new = ft_lstnew("kernel");
        head->next = ptr;
        ft_lstadd_back(&head, new);
        while (head != NULL)
        {
                printf("%s\n", (char *)head->content);
                head = head->next;
        }
}
*/
