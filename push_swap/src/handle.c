/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 11:45:39 by talin             #+#    #+#             */
/*   Updated: 2024/11/19 13:07:16 by talin            ###   ########.fr       */
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

void	ft_handle_error_and_free(t_list **lst, char **result)
{
	int	i;

	ft_lstclear(lst, &delete);
	ft_putstr_fd("Error\n", 2);
	i = -1;
	while (result[++i])
		free(result[i]);
	free(result);
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

void	ft_handle_sign_order_two(char *str, t_list **lst, char **result)
{
	int	i;

	if (ft_strlen(str) == 1 && (str[0] == '+' || str[0] == '-'))
		ft_handle_error_and_free(lst, result);
	else
	{
		i = 0;
		while (str[++i])
		{
			if ((str[i] == '+' || str[i] == '-') && \
			((str[i -1] == '+' || str[i - 1] == '-') || \
			(str[i -1] >= '0' && str[i - 1] <= '9')))
				ft_handle_error_and_free(lst, result);
		}
	}
}
