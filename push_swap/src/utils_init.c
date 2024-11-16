/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 15:53:34 by talin             #+#    #+#             */
/*   Updated: 2024/11/16 16:30:42 by talin            ###   ########.fr       */
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
