/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 15:24:00 by talin             #+#    #+#             */
/*   Updated: 2024/11/16 15:35:41 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_rotate(t_stack *stk, int ab)
{
	int	i;
	int	tmp;

	if (stk->len > 1)
	{
		tmp = stk->arr[0];
		i = 0;
		while (i < stk->len - 1)
		{
			stk->arr[i] = stk->arr[i + 1];
			i++;
		}
		stk->arr[i] = tmp;
		if (ab == 1)
			ft_printf("ra\n");
		if (ab == 2)
			ft_printf("rb\n");
	}
}

static void	ft_rotate_no_print(t_stack *stk)
{
	int	i;
	int	tmp;

	if (stk->len > 1)
	{
		tmp = stk->arr[0];
		i = 0;
		while (i < stk->len - 1)
		{
			stk->arr[i] = stk->arr[i + 1];
			i++;
		}
		stk->arr[i] = tmp;
	}
}

void	ft_rotate_both(t_stack *a, t_stack *b)
{
	ft_rotate_no_print(a);
	ft_rotate_no_print(b);
	ft_printf("rr\n");
}
