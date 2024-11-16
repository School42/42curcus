/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 15:03:52 by talin             #+#    #+#             */
/*   Updated: 2024/11/16 16:32:15 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_push(t_stack *one, t_stack *two, int ab)
{
	int	i;

	if (two->len > 0)
	{
		i = one->len;
		while (i > 0)
		{
			one->arr[i] = one->arr[i - 1];
			i--;
		}
		one->arr[0] = two->arr[0];
		one->len++;
		two->len--;
		while (i < two->len)
		{
			two->arr[i] = two->arr[i + 1];
			i++;
		}
		if (ab == 1)
			ft_printf("pa\n");
		else if (ab == 2)
			ft_printf("pb\n");
	}
}
