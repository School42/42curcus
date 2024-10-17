/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:44:59 by talin             #+#    #+#             */
/*   Updated: 2024/10/17 14:52:38 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"
#include <stdio.h>
#include <stdlib.h>

#define WIN_WIDTH 800
#define WIN_HEIGHT 600
#define FRAME_COUNT 6  // Number of animation frames

typedef struct s_game
{
    mlx_t* mlx;                        // MLX42 context
    mlx_image_t* player_images[FRAME_COUNT]; // Player images for each animation frame
    int frame_count;                   // Counter to track frames
    int frame_speed;                   // Speed of animation
    int current_frame;                 // Current frame index
    int player_x;                      // Player's x position
    int player_y;                      // Player's y position
} t_game;

// Load textures for animation frames and create separate images for each frame
void load_player_frames(t_game *game)
{
    // Manually specify the file paths for each frame
    mlx_texture_t *frame_texture1 = mlx_load_png("assets/en_right1.png");
    mlx_texture_t *frame_texture2 = mlx_load_png("assets/en_right2.png");
    mlx_texture_t *frame_texture3 = mlx_load_png("assets/en_right3.png");
	mlx_texture_t *frame_texture4 = mlx_load_png("assets/en_right4.png");
    mlx_texture_t *frame_texture5 = mlx_load_png("assets/en_right5.png");
    mlx_texture_t *frame_texture6 = mlx_load_png("assets/en_right6.png");

    // Check if textures are loaded successfully
    if (!frame_texture1 || !frame_texture2 || !frame_texture3 || !frame_texture4 || !frame_texture5 || !frame_texture6)
    {
        printf("Error loading animation frames!\n");
        exit(EXIT_FAILURE);
    }

    // Create images from the textures
    game->player_images[0] = mlx_texture_to_image(game->mlx, frame_texture1);
    game->player_images[1] = mlx_texture_to_image(game->mlx, frame_texture2);
    game->player_images[2] = mlx_texture_to_image(game->mlx, frame_texture3);
	game->player_images[3] = mlx_texture_to_image(game->mlx, frame_texture4);
    game->player_images[4] = mlx_texture_to_image(game->mlx, frame_texture5);
    game->player_images[5] = mlx_texture_to_image(game->mlx, frame_texture6);

    // Check if images were created successfully
    for (int i = 0; i < FRAME_COUNT; i++)
    {
        if (!game->player_images[i])
        {
            printf("Failed to create image for frame %d!\n", i + 1);
            exit(EXIT_FAILURE);
        }

        // Initially disable all frames except the first one
        if (i > 0)
            game->player_images[i]->enabled = false;

        // Place the image at the initial player position
		mlx_resize_image(game->player_images[i], 500, 500);
        mlx_image_to_window(game->mlx, game->player_images[i], game->player_x, game->player_y);
    }

    // Free the textures after creating the images
    mlx_delete_texture(frame_texture1);
    mlx_delete_texture(frame_texture2);
    mlx_delete_texture(frame_texture3);
	mlx_delete_texture(frame_texture4);
    mlx_delete_texture(frame_texture5);
    mlx_delete_texture(frame_texture6);
}


// Update animation frames
void update_animation(void *param)
{
    t_game *game = (t_game *)param;

    // Only update every `frame_speed` frames
    if (game->frame_count % game->frame_speed == 0)
    {
        // Disable the previous frame
        game->player_images[game->current_frame]->enabled = false;

        // Cycle through frames
        game->current_frame = (game->current_frame + 1) % FRAME_COUNT;

        // Enable the new frame
        game->player_images[game->current_frame]->enabled = true;
    }

    // Increase the frame count
    game->frame_count++;
}

// Key press handling for player movement (for example)
void handle_key_input(mlx_key_data_t keydata, void *param)
{
    t_game *game = (t_game *)param;

    if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
        mlx_close_window(game->mlx); // Close game on ESC press

    // Basic player movement handling
    if (keydata.key == MLX_KEY_W)
        game->player_y -= 5;
    if (keydata.key == MLX_KEY_S)
        game->player_y += 5;
    if (keydata.key == MLX_KEY_A)
        game->player_x -= 5;
    if (keydata.key == MLX_KEY_D)
        game->player_x += 5;
}

int main(void)
{
    t_game game;

    // Initialize MLX42
    game.mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "so_long Animation Example", true);
    if (!game.mlx)
        return EXIT_FAILURE;

    // Initialize game variables
    game.player_x = WIN_WIDTH / 2;     // Starting X position of the player
    game.player_y = WIN_HEIGHT / 2;    // Starting Y position of the player
    game.frame_count = 0;              // Initial frame count
    game.frame_speed = 6;             // Adjust the animation speed (lower is faster)
    game.current_frame = 0;            // Start at frame 0

    // Load animation frames (each frame is a separate image)
    load_player_frames(&game);

    // Hook the animation update function to the MLX42 loop
    mlx_loop_hook(game.mlx, update_animation, &game);

    // Hook the key input for player movement
    mlx_key_hook(game.mlx, handle_key_input, &game);

    // Start the game loop
    mlx_loop(game.mlx);

    // Free resources after game ends
    for (int i = 0; i < FRAME_COUNT; i++)
        mlx_delete_image(game.mlx, game.player_images[i]);

    mlx_terminate(game.mlx);

    return EXIT_SUCCESS;
}
