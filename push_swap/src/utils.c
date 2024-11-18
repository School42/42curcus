/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 11:53:15 by talin             #+#    #+#             */
/*   Updated: 2024/11/16 21:05:32 by ubuntu           ###   ########.fr       */
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
		ft_free_stack(a, b);
		exit(EXIT_SUCCESS);
	}
}

int	ft_check_sorting(t_stack *a)
{
	int	i;

	i = 1;
	while (i < a->len - 1)
	{
		if (a->arr[i] > a->arr[i - 1] && a->arr[i] < a->arr[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}
