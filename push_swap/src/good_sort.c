/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   good_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 20:09:54 by ubuntu            #+#    #+#             */
/*   Updated: 2024/11/19 12:04:10 by talin            ###   ########.fr       */
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
	int	i;
	int	tmp;

	if (ft_check_sorting(a))
		return ;
	tmp = a->arr[0];
	i = -1;
	while (++i < 3)
		if (a->arr[i] > tmp)
			tmp = a->arr[i];
	if (a->arr[0] == tmp)
		ft_rotate(a, 1);
	else if (a->arr[1] == tmp)
		ft_reverse_rotate(a, 1);
	ft_sort_two(a);
}

int	ft_min_num(t_stack *a)
{
	int	i;
	int	tmp;

	tmp = a->arr[0];
	i = -1;
	while (++i < a->len)
		if (a->arr[i] < tmp)
			tmp = a->arr[i];
	return (tmp);
}

void	ft_sort_four(t_stack *a, t_stack *b)
{
	int	tmp;

	if (ft_check_sorting(a))
		return ;
	tmp = ft_min_num(a);
	if (a->arr[1] == tmp)
		ft_rotate(a, 1);
	else if (a->arr[2] == tmp)
	{
		ft_rotate(a, 1);
		ft_rotate(a, 1);
	}
	else if (a->arr[3] == tmp)
		ft_reverse_rotate(a, 1);
	if (ft_check_sorting(a))
		return ;
	ft_push(b, a, 2);
	ft_sort_three(a);
	ft_push(a, b, 1);
}

void	ft_sort_five(t_stack *a, t_stack *b)
{
	int	tmp;

	if (ft_check_sorting(a))
		return ;
	tmp = ft_min_num(a);
	if (a->arr[1] == tmp)
		ft_rotate(a, 1);
	else if (a->arr[2] == tmp)
	{
		ft_rotate(a, 1);
		ft_rotate(a, 1);
	}
	else if (a->arr[3] == tmp)
	{
		ft_reverse_rotate(a, 1);
		ft_reverse_rotate(a, 1);
	}
	else if (a->arr[4] == tmp)
		ft_reverse_rotate(a, 1);
	if (ft_check_sorting(a))
		return ;
	ft_push(b, a, 2);
	ft_sort_four(a, b);
	ft_push(a, b, 1);
}
