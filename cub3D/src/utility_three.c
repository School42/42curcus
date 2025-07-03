/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 16:38:26 by talin             #+#    #+#             */
/*   Updated: 2025/07/03 15:59:00 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

int	valid_char(int c)
{
	if (!(c == '0' || c == '1' || c == ' ' || c == 'N' || c == 'S' || c == 'W' || c == 'E'))
		return (0);
	return (1);
}

int	is_player(int c)
{
	return ((c == 'N' || c == 'S' || c == 'W' || c == 'E'));
}

int	is_floor_player(int c)
{
	return ((c == 'N' || c == 'S' || c == 'W' || c == 'E' || c == '0'));
}

void	error_ft(char *err)
{
	printf("Error\n%s\n", err);
}
