/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 11:45:39 by talin             #+#    #+#             */
/*   Updated: 2024/11/16 16:45:22 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	delete(int i)
{
	(void)i;
}

void	ft_handle_error(t_list **lst)
{
	ft_lstclear(lst, &delete);
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

int	ft_handle_outsider(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9') || \
		str[i] == ' ' || str[i] == '+' || str[i] == '-')
			i++;
		else
			return (0);
	}
	return (1);
}

void	ft_handle_sign_order(char *str, t_list **lst)
{
	int	i;

	if (ft_strlen(str) == 1 && (str[0] == '+' || str[0] == '-'))
		ft_handle_error(lst);
	else
	{
		i = 0;
		while (str[++i])
		{
			if ((str[i] == '+' || str[i] == '-') && \
			(str[i -1] >= '0' && str[i - 1] <= '9'))
				ft_handle_error(lst);
		}
	}
}

int	ft_find_double(t_list *lst, int n)
{
	while (lst)
	{
		if (lst->content == n)
			return (1);
		lst = lst->next;
	}
	return (0);
}
