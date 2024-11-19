/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:43:31 by talin             #+#    #+#             */
/*   Updated: 2024/11/19 13:08:51 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_add_node(t_list **lst, char *str, char **result)
{
	long	res;
	t_list	*node;

	ft_handle_sign_order_two(str, lst, result);
	res = ft_atoi(str);
	if ((res > INT_MAX || res < INT_MIN) || ft_find_double(*lst, res))
		ft_handle_error_and_free(lst, result);
	node = ft_lstnew((int)res);
	if (!node)
		ft_handle_error(lst);
	ft_lstadd_back(lst, node);
}

void	ft_add_node_two(t_list **lst, char *str)
{
	long	res;
	t_list	*node;

	ft_handle_sign_order(str, lst);
	res = ft_atoi(str);
	if ((res > INT_MAX || res < INT_MIN) || ft_find_double(*lst, res))
		ft_handle_error(lst);
	node = ft_lstnew((int)res);
	if (!node)
		ft_handle_error(lst);
	ft_lstadd_back(lst, node);
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
			((str[i -1] == '+' || str[i - 1] == '-') || \
			(str[i -1] >= '0' && str[i - 1] <= '9')))
				ft_handle_error(lst);
		}
	}
}
