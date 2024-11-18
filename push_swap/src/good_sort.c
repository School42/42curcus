/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   good_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 20:09:54 by ubuntu            #+#    #+#             */
/*   Updated: 2024/11/17 09:21:04 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_sort_two(t_stack *a)
{
	if (a->arr[0] > a->arr[1])
		ft_swap(a, 1);
}

void	ft_sort_three(t_stack *a)
{
	int	tmp;
	int	i;
	int	x;

	if (ft_check_sorting(a))
		return ;
	tmp = a->arr[0];
	i = -1;
	x = 2;
	while (++i < 3)
	{
		if (a->arr[i] > tmp)
		{
			x = 2 - i;
			tmp = a->arr[i];
		}
	}
	if (x == 2)
		ft_rotate(a, 1);
	else if (x == 1)
		ft_reverse_rotate(a, 1);
	ft_sort_two(a);
}

void	ft_sort_four(t_stack *a, t_stack *b)
{
	int	tmp;
	int	i;

	if (ft_check_sorting(a))
		return ;
	tmp = a->arr[0];
	i = -1;
	while (++i < 4)
		if (a->arr[i] < tmp)
			tmp = a->arr[i];
	i = -1;
	while (++i < 4)
	{
		if (a->arr[0] == tmp)
			break ;
		else
			ft_rotate(a, 1);
	}
	ft_push(b, a, 2);
	ft_sort_three(a);
	ft_push(a, b, 1);
}

void	ft_sort_five(t_stack *a, t_stack *b)
{
	int	tmp;
	int	i;

	if (ft_check_sorting(a))
		return ;
	tmp = a->arr[0];
	i = -1;
	while (++i < 5)
		if (a->arr[i] < tmp)
			tmp = a->arr[i];
	i = -1;
	while (++i < 5)
	{
		if (a->arr[0] == tmp)
			break ;
		else
			ft_rotate(a, 1);
	}
	ft_push(b, a, 2);
	ft_sort_four(a, b);
	ft_push(a, b, 1);
}
