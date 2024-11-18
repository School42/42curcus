/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 11:53:15 by talin             #+#    #+#             */
/*   Updated: 2024/11/18 15:24:04 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_check_sorted(t_stack *a, t_stack *b)
{
	int	i;

	i = 1;
	if (a->len == 2)
	{
		if (a->arr[0] < a->arr[1])
		{
			ft_free_stack(a, b);
			exit(EXIT_SUCCESS);
		}
		else
			return ;
	}
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

int	ft_ismax(t_sorted *tmp, int x)
{
	if (x == tmp->first_max || x == tmp->sec_max \
	|| x == tmp->third_max || x == tmp->forth_max || x == tmp->fifth_max)
		return (1);
	return (0);
}

void	ft_copy_moves(t_moves *tmp_move, t_moves *move)
{
	move->num_ra = tmp_move->num_ra;
	move->num_rb = tmp_move->num_rb;
	move->num_rr = tmp_move->num_rr;
	move->num_rra = tmp_move->num_rra;
	move->num_rrb = tmp_move->num_rrb;
	move->num_rrr = tmp_move->num_rrr;
	move->total = tmp_move->total;
}
