/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:14:47 by talin             #+#    #+#             */
/*   Updated: 2024/10/21 14:56:00 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_print_moves(t_mapping *game)
{
	char	*move_count;

	move_count = ft_itoa(game->move);
	mlx_delete_image(game->mlx, game->texts.move);
	game->texts.move = mlx_put_string(game->mlx, \
	move_count, 70, game->size.y * WIDTH + 10);
	free(move_count);
}

void	ft_print_strings(t_mapping *game)
{
	char	*total_count;

	game->texts.mo_ve = mlx_put_string(game->mlx, \
	"MOVES:", 3, game->size.y * WIDTH + 10);
	game->texts.me_at = mlx_put_string(game->mlx, \
	"MEATS: ", 3, game->size.y * WIDTH + 40);
	total_count = ft_itoa(game->num_collectible);
	game->texts.meat = mlx_put_string(game->mlx, \
	total_count, 125, game->size.y * WIDTH + 40);
	free(total_count);
}

void	ft_print_meat(t_mapping *game)
{
	char	*meat_total;

	meat_total = ft_itoa(game->consumed_meat);
	mlx_delete_image(game->mlx, game->texts.meat);
	game->texts.meat = mlx_put_string(game->mlx, \
	meat_total, 80, game->size.y * WIDTH + 40);
	free(meat_total);
}
