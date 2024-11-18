/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:35:47 by talin             #+#    #+#             */
/*   Updated: 2024/11/18 14:20:49 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_get_num(t_stack *a, int x)
{
	int	num;
	int	i;
	int	status;

	i = -1;
	status = 0;
	num = INT_MAX;
	while (++i < a->len)
	{
		if (a->arr[i] > x && a->arr[i] < num)
		{
			num = a->arr[i];
			status = 1;
		}
	}
	if (!status)
	{
		num = a->arr[0];
		i = 0;
		while (++i < a->len)
			if (a->arr[i] < num)
				num = a->arr[i];
	}
	return (num);
}

void	ft_get_move_count(int num, t_stack *a, t_moves *tmp_move)
{
	int	i;

	i = -1;
	while (++i < a->len)
	{
		if (a->arr[i] == num)
			break ;
	}
	if (i <= a->len - i)
		tmp_move->num_ra = i;
	else
		tmp_move->num_rra = a->len - i;
}

void	ft_shrink_moves(t_moves *tmp_move)
{
	while (tmp_move->num_ra && tmp_move->num_rb)
	{
		tmp_move->num_ra--;
		tmp_move->num_rb--;
		tmp_move->num_rr++;
	}
	while (tmp_move->num_rra && tmp_move->num_rrb)
	{
		tmp_move->num_rra--;
		tmp_move->num_rrb--;
		tmp_move->num_rrr++;
	}
}

int	ft_total(t_moves *tmp_move)
{
	tmp_move->total = tmp_move->num_ra + tmp_move->num_rb + \
	tmp_move->num_rr + tmp_move->num_rra + tmp_move->num_rrb + \
	tmp_move->num_rrr;
	return (tmp_move->total);
}

void	ft_calculate_moves(t_stack *a, t_stack *b, t_sorted *tmp, t_moves *move)
{
	int		i;
	int		num;
	t_moves	*tmp_move;

	tmp_move = (t_moves *)malloc(sizeof(t_moves));
	if (!tmp_move)
		ft_error_free_all(a, b, tmp, move);
	i = -1;
	while (++i < b->len)
	{
		ft_init_moves(tmp_move);
		if (i <= b->len - i)
			tmp_move->num_rb = i;
		else
			tmp_move->num_rrb = b->len - i;
		num = ft_get_num(a, b->arr[i]);
		ft_get_move_count(num, a, tmp_move);
		ft_shrink_moves(tmp_move);
		if (ft_total(tmp_move) < move->total)
			ft_copy_moves(tmp_move, move);
		if (move->total == 0 || move->total == 1)
			break ;
	}
	free(tmp_move);
}
