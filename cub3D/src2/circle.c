/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 15:31:24 by talin             #+#    #+#             */
/*   Updated: 2025/05/13 15:56:47 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"
#include <mlx.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <time.h>  // For seeding the random number generator

#define WIDTH 800
#define HEIGHT 600
#define RADIUS 30
#define STEP 10

typedef struct s_data {
    void *mlx;
    void *win;
    void *img;
    char *addr;
    int bpp;
    int line_len;
    int endian;
    int cx;
    int cy;
	bool transparent;
	unsigned int prev_color;
    unsigned int color;  // Added to store current circle color
} t_data;

// Function to generate a random color
unsigned int generate_random_color(void)
{
    // Generate random RGB values (0-255)
    int r = rand() % 256;
    int g = rand() % 256;
    int b = rand() % 256;
    
    // Combine into a single color value (0xRRGGBB)
    return (r << 16) | (g << 8) | b;
}

void clear_screen(t_data *data)
{
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            char *dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
            *(unsigned int *)dst = 0x000000; // black
        }
    }
}

void draw_circle(t_data *data, int cx, int cy, int r, unsigned int color)
{
    for (int y = -r; y <= r; y++) {
        for (int x = -r; x <= r; x++) {
            if (x * x + y * y <= r * r) {
                int px = cx + x;
                int py = cy + y;
                if (px >= 0 && px < WIDTH && py >= 0 && py < HEIGHT) {
                    char *dst = data->addr + (py * data->line_len + px * (data->bpp / 8));
                    *(unsigned int *)dst = color;
                }
            }
        }
    }
}

int render(t_data *data)
{
    clear_screen(data);
    draw_circle(data, data->cx, data->cy, RADIUS, data->color);
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
    return (0);
}

int handle_keydown(int keycode, void *param)
{
    t_data *data = (t_data *)param;
    
    printf("Key pressed: %d\n", keycode); // Debug keycode
    
    if (keycode == 53 || keycode == 65307) // ESC (macOS/Linux)
        exit(0);
    if (keycode == 13 || keycode == 119) // W
        data->cy -= STEP;
    if (keycode == 1 || keycode == 115) // S
        data->cy += STEP;
    if (keycode == 0 || keycode == 97) // A
        data->cx -= STEP;
    if (keycode == 2 || keycode == 100) // D
        data->cx += STEP;
    
    // Change color with Space bar
    if (keycode == 49 || keycode == 32) // Space
	{
        data->color = generate_random_color();
	}
	if (keycode == 65293)
	{
		if (!data->transparent) {
			data->prev_color = data->color;
			data->color = 0x000000;
		} else {
			data->color = data->prev_color;
		}
		data->transparent = !data->transparent;
	}
    // Ensure the circle stays within the window bounds
    if (data->cx < RADIUS)
        data->cx = RADIUS;
    if (data->cx > WIDTH - RADIUS)
        data->cx = WIDTH - RADIUS;
    if (data->cy < RADIUS)
        data->cy = RADIUS;
    if (data->cy > HEIGHT - RADIUS)
        data->cy = HEIGHT - RADIUS;
    
    render(data);
    return (0);
}

// Add window close handler
int handle_close(void *param)
{
    (void)param;
    exit(0);
    return (0);
}

int main(void)
{
    t_data data;
    
    // Seed the random number generator with current time
    srand(time(NULL));
    
    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Move the Circle");
    data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
    data.addr = mlx_get_data_addr(data.img, &data.bpp, &data.line_len, &data.endian);
    data.cx = WIDTH / 2;
    data.cy = HEIGHT / 2;
    data.color = 0x00FF00;  // Start with green
    data.prev_color= 0x000000;
	data.transparent = false;
    render(&data);
    
    // Key press event
    mlx_hook(data.win, 2, 1L<<0, handle_keydown, &data);
    
    // Window close event (red X button)
    mlx_hook(data.win, 17, 0, handle_close, &data);
    
    mlx_loop(data.mlx);
    return (0);
}
