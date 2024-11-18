/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 09:52:16 by talin             #+#    #+#             */
/*   Updated: 2024/11/16 20:24:30 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_stack
{
	int	*arr;
	int	len;
}	t_stack;

t_stack	*ft_create_stack(int ac, char **av);
void	ft_create_list(char	*str, t_list **lst);
void	ft_parse_str(char *str, t_list **lst);
void	ft_add_node(t_list **lst, char *str);
t_stack	*ft_lst_to_stack(t_list **lst, t_stack *a);
void	delete(int i);
void	ft_handle_error(t_list **lst);
int		ft_handle_outsider(char *str);
void	ft_handle_sign_order(char *str, t_list **lst);
int		ft_find_double(t_list *lst, int n);
void	quick_sort(int *arr, int low, int high);
void	ft_swap_num(int *a, int *b);
void	ft_swap_both(t_stack *a, t_stack *b);
void	ft_swap(t_stack *stk, int ab);
void	ft_push(t_stack *one, t_stack *two, int ab);
void	ft_rotate_both(t_stack *a, t_stack *b);
void	ft_rotate(t_stack *stk, int ab);
void	ft_reverse_both(t_stack *a, t_stack *b);
void	ft_reverse_rotate(t_stack *stk, int ab);
void	ft_init_statck(t_stack *a, t_stack **b);
void	ft_free_stack(t_stack *a, t_stack *b);
void	ft_stack_error(t_stack *a, t_stack *b);
void	ft_check_sorted(t_stack *a, t_stack *b);
int		ft_check_sorting(t_stack *a);
#endif