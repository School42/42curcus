/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_animation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:19:08 by talin             #+#    #+#             */
/*   Updated: 2025/05/13 16:31:48 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>

#define WIDTH  800
#define HEIGHT 600
#define FRAME_COUNT 6
#define FRAME_RATE 24

typedef struct s_data {
	void	*mlx;
	void	*win;
	void	*frames[FRAME_COUNT]; // Store each frame
	char	*frame_addrs[FRAME_COUNT]; // Store addresses for each frame
	int		sprite_w;
	int		sprite_h;
	int		current_frame;
	int		line_len;
	int 	bpp;
	int 	endian;
}	t_data;

void	load_frames(t_data *data)
{
	DIR *dir = opendir("./assets/frames"); // Directory containing the frames
	if (!dir)
	{
		fprintf(stderr, "Error opening frames directory\n");
		exit(1);
	}

	struct dirent *entry;
	int i = 0;
	while ((entry = readdir(dir)) != NULL && i < FRAME_COUNT)
	{
		// Construct the file path for each frame
		if (entry->d_name[0] != '.')
		{
			char file_path[256];
			snprintf(file_path, sizeof(file_path), "./assets/frames/%s", entry->d_name);

			// Load the frame image
			data->frames[i] = mlx_xpm_file_to_image(data->mlx, file_path, &data->sprite_w, &data->sprite_h);
			if (!data->frames[i])
			{
				fprintf(stderr, "Error loading frame: %s\n", file_path);
				exit(1);
			}
			// Get the pixel data for each frame
			data->frame_addrs[i] = mlx_get_data_addr(data->frames[i], &data->bpp, &data->line_len, &data->endian);
			i++;
		}
	}
	closedir(dir);
}

void	draw_frame(t_data *data)
{
	int x, y;
	void *frame = data->frames[data->current_frame];
	char *frame_addr = data->frame_addrs[data->current_frame];

	// Create a new image to display on the window
	void *display_image = mlx_new_image(data->mlx, data->sprite_w, data->sprite_h);
	char *display_addr = mlx_get_data_addr(display_image, &data->bpp, &data->line_len, &data->endian);

	// Copy the frame data into the display image
	for (y = 0; y < data->sprite_h; y++)
	{
		for (x = 0; x < data->sprite_w; x++)
		{
			char *src = frame_addr + (y * data->line_len + x * (data->bpp / 8));
			char *dst = display_addr + (y * data->line_len + x * (data->bpp / 8));
			*(unsigned int *)dst = *(unsigned int *)src;
		}
	}

	// Position the frame in the center of the window
	int draw_x = (WIDTH - data->sprite_w) / 2;
	int draw_y = (HEIGHT - data->sprite_h) / 2;

	// Clear the window and draw the new frame
	mlx_clear_window(data->mlx, data->win);
	mlx_put_image_to_window(data->mlx, data->win, display_image, draw_x, draw_y);
	mlx_destroy_image(data->mlx, display_image);
}

int	render_frame(void *param)
{
	static struct timeval	last_time = {0, 0};
	struct timeval			now;
	t_data					*data = (t_data *)param;

	// Get the elapsed time to control the frame rate
	gettimeofday(&now, NULL);
	long elapsed_ms = (now.tv_sec - last_time.tv_sec) * 1000 +
					  (now.tv_usec - last_time.tv_usec) / 1000;

	// If enough time has passed, move to the next frame
	if (elapsed_ms >= 1000 / FRAME_RATE)
	{
		draw_frame(data);
		data->current_frame = (data->current_frame + 1) % FRAME_COUNT; // Loop through all frames
		last_time = now;
	}
	return (0);
}

int	main(void)
{
	t_data data;

	// Initialize mlx and create the window
	data.mlx = mlx_init();
	if (!data.mlx)
	{
		fprintf(stderr, "Error initializing mlx\n");
		return (1);
	}

	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Sprite Animation");
	if (!data.win)
	{
		fprintf(stderr, "Error creating window\n");
		return (1);
	}

	// Load all the frames from the directory
	load_frames(&data);

	// Start the animation loop
	mlx_loop_hook(data.mlx, render_frame, &data);
	mlx_loop(data.mlx);

	// Clean up and close the window
	mlx_destroy_window(data.mlx, data.win);
	for (int i = 0; i < FRAME_COUNT; i++)
	{
		mlx_destroy_image(data.mlx, data.frames[i]);
	}
	return (0);
}
