/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_operations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 15:34:31 by talin             #+#    #+#             */
/*   Updated: 2024/11/16 15:45:09 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_reverse_rotate(t_stack *stk, int ab)
{
	int	i;
	int	tmp;

	if (stk->len > 1)
	{
		tmp = stk->arr[stk->len - 1];
		i = stk->len - 1;
		while (i > 0)
		{
			stk->arr[i] = stk->arr[i - 1];
			i--;
		}
		stk->arr[i] = tmp;
		if (ab == 1)
			ft_printf("rra\n");
		else if (ab == 2)
			ft_printf("rrb\n");
	}
}

static void	ft_reverse_no_print(t_stack *stk)
{
	int	i;
	int	tmp;

	if (stk->len > 1)
	{
		tmp = stk->arr[stk->len - 1];
		i = stk->len - 1;
		while (i > 0)
		{
			stk->arr[i] = stk->arr[i - 1];
			i--;
		}
		stk->arr[i] = tmp;
	}
}

void	ft_reverse_both(t_stack *a, t_stack *b)
{
	ft_reverse_no_print(a);
	ft_reverse_no_print(b);
	ft_printf("rrr\n");
}
