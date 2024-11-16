/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 09:52:32 by talin             #+#    #+#             */
/*   Updated: 2024/11/16 16:34:30 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = ft_create_stack(ac, av);
	b = NULL;
	ft_init_statck(a, &b);
	ft_check_sorted(a, b);
	ft_free_stack(a, b);
	return (0);
}
