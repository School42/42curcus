/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:41:26 by talin             #+#    #+#             */
/*   Updated: 2024/10/17 12:38:36 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"
#include <stdio.h>
#include <stdlib.h>

#define WIN_WIDTH 800
#define WIN_HEIGHT 600
#define FRAME_COUNT 6   // Number of animation frames

typedef struct	s_game
{
	mlx_t*			mlx;
	mlx_image_t*	player_image;
	int				frame_count;
	int				frame_speed;
	int				current_frame;
	mlx_texture_t*	walk_frames[FRAME_COUNT];
	int				player_x;
	int				player_y;
}	t_game;

void	load_player_frames(t_game *game)
{
	game->walk_frames[0] = mlx_load_png("assets/up1.png");
	game->walk_frames[1] = mlx_load_png("assets/up2.png");
	game->walk_frames[2] = mlx_load_png("assets/up3.png");
	game->walk_frames[3] = mlx_load_png("assets/up4.png");
	game->walk_frames[4] = mlx_load_png("assets/up5.png");
	game->walk_frames[5] = mlx_load_png("assets/up6.png");
	if (!game->walk_frames[0] || !game->walk_frames[1] || \
	!game->walk_frames[2] || !game->walk_frames[3] || \
	!game->walk_frames[4] || !game->walk_frames[5])
	{
		printf("Error loading animation frames!\n");
		exit(EXIT_FAILURE);
	}
}

void	free_player_frames(t_game *game)
{
	for (int i = 0; i < FRAME_COUNT; i++)
	{
		mlx_delete_texture(game->walk_frames[i]);
	}
}

void	update_animation(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (game->frame_count % game->frame_speed == 0)
	{
		game->current_frame = (game->frame_count / \
		game->frame_speed) % FRAME_COUNT;
		game->player_image = mlx_texture_to_image(game->mlx, \
		game->walk_frames[game->current_frame]);
		mlx_resize_image(game->player_image, 50, 100);
	}
	game->frame_count++;
	mlx_image_to_window(game->mlx, game->player_image, \
	game->player_x, game->player_y);
	// mlx_delete_texture(game->walk_frames[game->current_frame]);
}

// Key press handling for player movement (for example)
void	handle_key_input(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(game->mlx);
	if (keydata.key == MLX_KEY_W)
		game->player_y -= 5;
	if (keydata.key == MLX_KEY_S)
		game->player_y += 5;
	if (keydata.key == MLX_KEY_A)
		game->player_x -= 5;
	if (keydata.key == MLX_KEY_D)
		game->player_x += 5;
}

int	main(void)
{
	t_game	game;

	game.mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, \
	"so_long Animation Example", true);
	if (!game.mlx)
		return (EXIT_FAILURE);
	game.player_x = WIN_WIDTH / 2;
	game.player_y = WIN_HEIGHT / 2;
	game.frame_count = 0;
	game.frame_speed = 6;
	game.current_frame = 0;
	load_player_frames(&game);
	// game.player_image = mlx_new_image(game.mlx, 50, 100);
	// if (!game.player_image)
	// {
	// 	printf("Failed to create player image!\n");
	// 	free_player_frames(&game);
	// 	mlx_terminate(game.mlx);
	// 	return (EXIT_FAILURE);
	// }
	// mlx_texture_to_image(game.mlx, game.walk_frames[game.current_frame]);
	mlx_loop_hook(game.mlx, update_animation, &game);
	mlx_key_hook(game.mlx, handle_key_input, &game);
	mlx_loop(game.mlx);
	free_player_frames(&game);
	mlx_delete_image(game.mlx, game.player_image);
	mlx_terminate(game.mlx);
	return (EXIT_SUCCESS);
}
