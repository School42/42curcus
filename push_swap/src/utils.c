/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 11:53:15 by talin             #+#    #+#             */
/*   Updated: 2024/11/16 16:44:44 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_check_sorted(t_stack *a, t_stack *b)
{
	int	i;

	i = 1;
	while (i < a->len - 1)
	{
		if (a->arr[i] > a->arr[i - 1] && a->arr[i] < a->arr[i + 1])
			i++;
		else
			break ;
	}
	if (i == a->len - 1)
	{
		ft_putstr_fd("Error\n", 2);
		ft_stack_error(a, b);
	}
}
