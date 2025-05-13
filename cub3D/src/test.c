/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 14:14:22 by talin             #+#    #+#             */
/*   Updated: 2025/05/13 13:40:34 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"
#include <mlx.h>

int	main(void)
{
	int		i;
	void	*mlx;
	void	*mlx_win;

	i = ft_printf("hello %s!\n", "world");
	printf("i: %d\n", i);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	mlx_loop(mlx);
}
