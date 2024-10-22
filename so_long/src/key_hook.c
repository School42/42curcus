/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:44:39 by talin             #+#    #+#             */
/*   Updated: 2024/10/22 12:49:32 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_move_up(t_mapping *game)
{
	int	x;
	int	y;

	y = game->player.y;
	x = game->player.x;
	if (y < game->size.y && x < game->size.x)
	{
		if (game->game_map[y - 1][x] != '1')
		{
			if (ft_check_count(game, game->game_map[y - 1][x]))
				return ;
			game->game_map[y - 1][x] = 'P';
			game->game_map[y][x] = '0';
			game->player.y -= 1;
			game->move++;
			ft_print_moves(game);
		}
	}
}

void	ft_move_down(t_mapping *game)
{
	int	x;
	int	y;

	y = game->player.y;
	x = game->player.x;
	if (y < game->size.y && x < game->size.x)
	{
		if (game->game_map[y + 1][x] != '1')
		{
			if (ft_check_count(game, game->game_map[y + 1][x]))
				return ;
			game->game_map[y + 1][x] = 'P';
			game->game_map[y][x] = '0';
			game->player.y += 1;
			game->move++;
			ft_print_moves(game);
		}
	}
}

void	ft_move_left(t_mapping *game)
{
	int	x;
	int	y;

	y = game->player.y;
	x = game->player.x;
	if (y < game->size.y && x < game->size.x)
	{
		if (game->game_map[y][x - 1] != '1')
		{
			if (ft_check_count(game, game->game_map[y][x - 1]))
				return ;
			game->game_map[y][x - 1] = 'P';
			game->game_map[y][x] = '0';
			game->player.x -= 1;
			game->move++;
			ft_print_moves(game);
		}
	}
}

void	ft_move_right(t_mapping *game)
{
	int	x;
	int	y;

	y = game->player.y;
	x = game->player.x;
	if (y < game->size.y && x < game->size.x)
	{
		if (game->game_map[y][x + 1] != '1')
		{
			if (ft_check_count(game, game->game_map[y][x + 1]))
				return ;
			game->game_map[y][x + 1] = 'P';
			game->game_map[y][x] = '0';
			game->player.x += 1;
			game->move++;
			ft_print_moves(game);
		}
	}
}

void	ft_key_hook(mlx_key_data_t keydata, void *param)
{
	t_mapping	*game;

	game = param;
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
		{
			ft_delete_enemy_assets(game);
			mlx_close_window(game->mlx);
			game->playing = CLOSING;
			ft_print_game(game);
		}
		if (game->portal == FALSE)
		{
			if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
				ft_move_up(game);
			if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
				ft_move_down(game);
			if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
				ft_move_left(game);
			if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
				ft_move_right(game);
		}
	}
}
