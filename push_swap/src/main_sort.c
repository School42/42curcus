/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:15:48 by talin             #+#    #+#             */
/*   Updated: 2024/11/18 15:23:34 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_push_median(t_stack *a, t_stack *b, int median)
{
	int	i;

	i = 0;
	while (a->arr[i] != median)
		i++;
	if (i <= a->len - i)
	{
		while (i--)
			ft_rotate(a, 1);
	}
	else
	{
		i = a->len - i;
		while (i--)
			ft_reverse_rotate(a, 1);
	}
	ft_push(b, a, 2);
}

void	ft_max_stack(t_stack *a, t_stack *b, t_sorted *tmp)
{
	int	i;
	int	size;

	if (a->len <= 5)
		return ;
	i = -1;
	size = a->len;
	while (++i < size)
	{
		if (!ft_ismax(tmp, a->arr[0]))
		{
			ft_push(b, a, 2);
			if (b->arr[0] > tmp->median)
				ft_rotate(b, 2);
		}
		else
			ft_rotate(a, 1);
	}
}

void	ft_movement(t_stack *a, t_stack *b, t_moves *move)
{
	while (move->num_rr--)
		ft_rotate_both(a, b);
	while (move->num_rrr--)
		ft_reverse_both(a, b);
	while (move->num_rrb--)
		ft_reverse_rotate(b, 2);
	while (move->num_rb--)
		ft_rotate(b, 2);
	while (move->num_ra--)
		ft_rotate(a, 1);
	while (move->num_rra--)
		ft_reverse_rotate(a, 1);
	ft_push(a, b, 1);
}

void	ft_sorting(t_stack *a, t_stack *b, t_sorted *tmp, int i)
{
	t_moves	*move;

	move = (t_moves *)malloc(sizeof(t_moves));
	if (!move)
		ft_error_free(a, b, tmp);
	ft_init_moves(move);
	while (b->len)
	{
		ft_calculate_moves(a, b, tmp, move);
		ft_movement(a, b, move);
		move->total = INT_MAX;
	}
	while (a->arr[i] != tmp->min)
		i++;
	if (i <= a->len - i)
		while (i--)
			ft_rotate(a, 1);
	else
	{
		i = a->len - i;
		while (i--)
			ft_reverse_rotate(a, 1);
	}
	free(move);
}

void	ft_sort_main(t_stack *a, t_stack *b)
{
	t_sorted	*tmp;

	tmp = ft_init_sorted(a, b);
	ft_push_median(a, b, tmp->median);
	ft_max_stack(a, b, tmp);
	if (a->len == 4)
		ft_sort_four(a, b);
	if (a->len == 5)
		ft_sort_five(a, b);
	ft_sorting(a, b, tmp, 0);
	free(tmp->arr);
	free(tmp);
}
