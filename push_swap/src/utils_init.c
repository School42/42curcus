/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 15:53:34 by talin             #+#    #+#             */
/*   Updated: 2024/11/18 15:03:19 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_stack_error(t_stack *a, t_stack *b)
{
	free(a->arr);
	free(b->arr);
	free(a);
	free(b);
	exit(EXIT_FAILURE);
}

void	ft_free_stack(t_stack *a, t_stack *b)
{
	free(a->arr);
	free(b->arr);
	free(a);
	free(b);
}

void	ft_init_statck(t_stack *a, t_stack **b)
{
	*b = (t_stack *)malloc(sizeof(t_stack));
	if (!*b)
		ft_stack_error(a, *b);
	(*b)->arr = (int *)malloc(sizeof(int) * a->len);
	if (!(*b)->arr)
		ft_stack_error(a, *b);
	(*b)->len = 0;
}

t_sorted	*ft_init_sorted(t_stack *a, t_stack *b)
{
	t_sorted	*tmp;
	int			i;

	tmp = (t_sorted *)malloc(sizeof(t_sorted));
	if (!tmp)
		ft_stack_error(a, b);
	tmp->arr = (int *)malloc(sizeof(int) * a->len);
	if (!tmp->arr)
		ft_stack_error(a, b);
	tmp->len = a->len;
	i = -1;
	while (++i < tmp->len)
		tmp->arr[i] = a->arr[i];
	quick_sort(tmp->arr, 0, tmp->len - 1);
	if (tmp->len % 2 == 0)
		tmp->median = tmp->arr[(tmp->len - 2) / 2];
	else
		tmp->median = tmp->arr[(tmp->len - 1) / 2];
	tmp->min = tmp->arr[0];
	tmp->first_max = tmp->arr[tmp->len - 1];
	tmp->sec_max = tmp->arr[tmp->len - 2];
	tmp->third_max = tmp->arr[tmp->len - 3];
	tmp->forth_max = tmp->arr[tmp->len - 4];
	tmp->fifth_max = tmp->arr[tmp->len - 5];
	return (tmp);
}

void	ft_init_moves(t_moves *move)
{
	move->num_ra = 0;
	move->num_rb = 0;
	move->num_rr = 0;
	move->num_rra = 0;
	move->num_rrb = 0;
	move->num_rrr = 0;
	move->total = INT_MAX;
}
