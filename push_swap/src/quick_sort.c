/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 13:20:32 by talin             #+#    #+#             */
/*   Updated: 2024/11/16 16:09:53 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_swap_num(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	partition(int *arr, int low, int high)
{
	int	pivot;
	int	random;
	int	i;
	int	j;

	random = low + rand() % (high - low + 1);
	ft_swap_num(&arr[random], &arr[low]);
	pivot = arr[low];
	i = low;
	j = high;
	while (1)
	{
		while (arr[j] > pivot)
			j--;
		while (i < j && arr[i] <= pivot)
			i++;
		if (i < j)
			ft_swap_num(&arr[i], &arr[j]);
		else
			break ;
	}
	ft_swap_num(&arr[low], &arr[j]);
	return (j);
}

void	quick_sort(int *arr, int low, int high)
{
	int	pi;

	if (low < high)
	{
		pi = partition(arr, low, high);
		quick_sort(arr, low, pi - 1);
		quick_sort(arr, pi + 1, high);
	}
}
