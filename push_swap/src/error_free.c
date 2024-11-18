/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:30:47 by talin             #+#    #+#             */
/*   Updated: 2024/11/18 13:51:18 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_error_free_all(t_stack *a, t_stack *b, t_sorted *tmp, t_moves *move)
{
	free(a->arr);
	free(b->arr);
	free(a);
	free(b);
	free(tmp->arr);
	free(tmp);
	free(move);
	exit(EXIT_FAILURE);
}

void	ft_error_free(t_stack *a, t_stack *b, t_sorted *tmp)
{
	free(a->arr);
	free(b->arr);
	free(a);
	free(b);
	free(tmp->arr);
	free(tmp);
	exit(EXIT_FAILURE);
}
