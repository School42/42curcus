/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 13:07:27 by talin             #+#    #+#             */
/*   Updated: 2025/07/01 13:07:37 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

void	ft_free_string_arr(char **string_arr)
{
	int	i;

	i = 0;
	if (!string_arr)
		return ;
	while (string_arr[i])
	{
		if (string_arr[i])
			free(string_arr[i]);
		i++;
	}
	free(string_arr);
}