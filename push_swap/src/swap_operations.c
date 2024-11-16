/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:38:39 by talin             #+#    #+#             */
/*   Updated: 2024/11/16 16:10:14 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_swap(t_stack *stk, int ab)
{
	if (stk->len >= 2)
	{
		ft_swap_num(&stk->arr[0], &stk->arr[1]);
		if (ab == 1)
			ft_printf("sa\n");
		else if (ab == 2)
			ft_printf("sb\n");
	}
}

static void	ft_swap_no_print(t_stack *stk)
{
	if (stk->len >= 2)
		ft_swap_num(&stk->arr[0], &stk->arr[1]);
}

void	ft_swap_both(t_stack *a, t_stack *b)
{
	ft_swap_no_print(a);
	ft_swap_no_print(b);
	ft_printf("ss\n");
}
