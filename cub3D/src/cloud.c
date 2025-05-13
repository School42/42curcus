/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 14:14:22 by talin             #+#    #+#             */
/*   Updated: 2025/05/13 15:28:43 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"
#include <mlx.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdio.h>

#define WIDTH 1920
#define HEIGHT 1080
#define CLOUD_SPEED 200 // the larger, the faster the cloud moves (don't exceed than 200)
#define CLOUD_COUNT 20
#define MAX_BLOBS 40    // Increased for more complex cloud shapes

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Added for improved noise function
unsigned int g_seed = 0;

// Fast random function for noise generation
unsigned int fast_rand() {
    g_seed = (214013 * g_seed + 2531011);
    return (g_seed >> 16) & 0x7FFF;
}

// Improved Perlin-like noise function
float noise2d(float x, float y) {
    int xi = (int)floor(x) & 255;
    int yi = (int)floor(y) & 255;
    float xf = x - floor(x);
    float yf = y - floor(y);
    
    // Hash values for noise
    unsigned int hash = (xi + yi * 13) ^ (yi + xi * 7);
    return (fast_rand() % 1000) / 1000.0f;
}

typedef struct s_blob {
    float x_offset;   // Offset from cloud center
    float y_offset;   // Offset from cloud center
    float radius;     // Blob size
    float density;    // Cloud density factor (0-1)
    float brightness; // Brightness variation (0-1)
} t_blob;

typedef struct s_cloud {
    float x;
    float y;
    float speed;      // Individual cloud speed
    int blob_count;   // Number of blobs in this cloud
    t_blob blobs[MAX_BLOBS];
    float cloud_type; // 0-1 value determining cloud type (fluffy, wispy, etc)
    float altitude;   // Relative altitude (affects coloring)
} t_cloud;

typedef struct s_data {
    void *mlx;
    void *win;
    void *img;
    char *addr;
    int bpp;
    int line_len;
    int endian;
    float frame;
    t_cloud clouds[CLOUD_COUNT];
    float sun_x;      // Sun position
    float sun_y;
    float time_of_day; // 0-1 value for time of day lighting
} t_data;

// Color utilities
unsigned int rgba(unsigned char r, unsigned char g, unsigned char b, unsigned char a) {
    return ((a << 24) | (r << 16) | (g << 8) | b);
}

// Smoothstep function for smooth transitions
float smoothstep(float edge0, float edge1, float x) {
    // Scale, bias and saturate x to 0..1 range
    x = fmaxf(0.0, fminf(1.0, (x - edge0) / (edge1 - edge0)));
    // Evaluate polynomial
    return x * x * (3 - 2 * x);
}

// Linear interpolation helper
float lerp(float a, float b, float t) {
    return a + t * (b - a);
}

// Improved soft edge cloud blob with realistic density variations
void draw_blob(t_data *data, float cx, float cy, float radius, t_blob *blob, float cloud_type, float altitude) {
    int r_squared = radius * radius;
    int draw_start_x = fmaxf(0, cx - radius - 10); // Extra margin for noise effects
    int draw_end_x = fminf(WIDTH - 1, cx + radius + 10);
    int draw_start_y = fmaxf(0, cy - radius - 10);
    int draw_end_y = fminf(HEIGHT - 1, cy + radius + 10);
    
    // Cloud coloring based on altitude and time of day
    unsigned char base_r = 255;
    unsigned char base_g = 255;
    unsigned char base_b = 255;
    
    // Apply slight coloring based on altitude (higher clouds are whiter)
    base_r = lerp(252, 255, altitude);
    base_g = lerp(248, 255, altitude);
    base_b = lerp(245, 255, altitude);
    
    // Apply time of day tinting (sunset creates orange/pink hues)
    if (data->time_of_day > 0.5) {
        float sunset_factor = (data->time_of_day - 0.5) * 2.0;
        base_r = lerp(base_r, 255, sunset_factor * 0.4);
        base_g = lerp(base_g, 223, sunset_factor * 0.6);
        base_b = lerp(base_b, 230, sunset_factor * 0.3);
    }
    
    float noise_scale = 0.05; // Scale of the noise pattern
    float noise_strength = 0.4; // Strength of noise influence on density
    
    for (int y = draw_start_y; y <= draw_end_y; y++) {
        for (int x = draw_start_x; x <= draw_end_x; x++) {
            float dx = x - cx;
            float dy = y - cy;
            float dist_squared = dx * dx + dy * dy;
            
            if (dist_squared <= r_squared * 1.2) { // Extend a bit beyond radius for soft edges
                float dist = sqrt(dist_squared);
                
                // Base opacity calculation with distance falloff
                float opacity_factor = 1.0 - smoothstep(radius * 0.5, radius, dist);
                
                // Add noise-based density variation
                float noise_val = noise2d((x + data->frame * 0.01) * noise_scale, 
                                         (y + blob->y_offset) * noise_scale);
                
                // Modify noise based on cloud type (fluffy vs. wispy)
                float type_noise = noise_val;
                if (cloud_type < 0.5) {
                    // Fluffy cumulus-like clouds (more solid with defined edges)
                    type_noise = powf(noise_val, 0.7);
                } else {
                    // Wispy cirrus-like clouds (more gradient and diffuse)
                    type_noise = powf(noise_val, 1.5);
                }
                
                // Create density variations within the cloud
                float density_variation = lerp(0.7, 1.0, type_noise);
                
                // Combine all factors for final opacity
                float alpha = opacity_factor * blob->density * density_variation;
                alpha = powf(alpha, 0.8); // Adjust contrast
                
                // Apply altitude effects (higher clouds are thinner)
                alpha *= lerp(1.0, 0.8, altitude);
                
                // Scale to 0-255 range and apply brightness variation
                alpha = alpha * 245 * lerp(0.9, 1.1, blob->brightness);
                
                if (alpha > 10) { // Only draw if significantly visible
                    char *dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
                    unsigned int *pixel = (unsigned int *)dst;
                    
                    // Existing color components
                    unsigned char r1 = (*pixel >> 16) & 0xFF;
                    unsigned char g1 = (*pixel >> 8) & 0xFF;
                    unsigned char b1 = *pixel & 0xFF;
                    
                    // Add very subtle blue tint to bottom of clouds
                    float bottom_factor = fmaxf(0, (cy - y) / radius) * 0.1;
                    unsigned char r2 = base_r - (unsigned char)(bottom_factor * 15);
                    unsigned char g2 = base_g - (unsigned char)(bottom_factor * 5);
                    unsigned char b2 = base_b;
                    
                    // Alpha blending
                    unsigned char r = r1 + (r2 - r1) * alpha / 255;
                    unsigned char g = g1 + (g2 - g1) * alpha / 255;
                    unsigned char b = b1 + (b2 - b1) * alpha / 255;
                    
                    *pixel = rgba(r, g, b, 0xFF);
                }
            }
        }
    }
}

// Draw an entire cloud composed of multiple blobs with better structure
void draw_cloud(t_data *data, t_cloud *cloud) {
    // Draw blobs from back to front (larger ones first)
    // Sort blobs by size (bubble sort) - simple but effective for small lists
    for (int i = 0; i < cloud->blob_count; i++) {
        for (int j = 0; j < cloud->blob_count - i - 1; j++) {
            if (cloud->blobs[j].radius < cloud->blobs[j + 1].radius) {
                t_blob temp = cloud->blobs[j];
                cloud->blobs[j] = cloud->blobs[j + 1];
                cloud->blobs[j + 1] = temp;
            }
        }
    }
    
    // Determine cloud's vertical position in the sky
    float rel_altitude = cloud->altitude;
    
    // Draw each blob with subtle movement
    for (int i = 0; i < cloud->blob_count; i++) {
        t_blob *blob = &cloud->blobs[i];
        float blob_x = cloud->x + blob->x_offset;
        float blob_y = cloud->y + blob->y_offset;
        
        // Add more natural movement - different for each blob
        float y_offset = sinf((data->frame * 0.01 + blob->x_offset * 0.1) * (0.3 + blob->density * 0.3)) * 1.5;
        float x_offset = cosf((data->frame * 0.008 + blob->y_offset * 0.1) * (0.2 + blob->density * 0.2)) * 1.0;
        
        draw_blob(data, 
                 blob_x + x_offset, 
                 blob_y + y_offset, 
                 blob->radius, 
                 blob, 
                 cloud->cloud_type,
                 rel_altitude);
    }
}

// Draw the sun
void draw_sun(t_data *data) {
    // Main sun body
    for (int y = -40; y <= 40; y++) {
        for (int x = -40; x <= 40; x++) {
            float dist = sqrtf(x * x + y * y);
            if (dist <= 40) {
                int px = (int)(data->sun_x + x);
                int py = (int)(data->sun_y + y);
                if (px >= 0 && px < WIDTH && py >= 0 && py < HEIGHT) {
                    float alpha = 1.0 - smoothstep(30, 40, dist);
                    
                    // Sun gradient from yellow to orange
                    unsigned char r = 255;
                    unsigned char g = lerp(154, 225, 1.0 - dist/40);
                    unsigned char b = lerp(0, 120, 1.0 - dist/40);
                    
                    unsigned int color = rgba(r, g, b, (int)(alpha * 255));
                    char *dst = data->addr + (py * data->line_len + px * (data->bpp / 8));
                    *(unsigned int *)dst = color;
                }
            }
        }
    }
    
    // Sun rays
    float ray_intensity = 0.7;  // Adjust based on time of day
    if (data->time_of_day > 0.5) {
        ray_intensity = 0.7 + (data->time_of_day - 0.5) * 0.6;  // Stronger rays during sunset
    }
    
    for (int i = 0; i < 12; i++) {
        float angle = i * (M_PI / 6);
        float ray_length = 60 + 10 * sinf(data->frame * 0.05);
        float ray_end_x = data->sun_x + cosf(angle) * ray_length;
        float ray_end_y = data->sun_y + sinf(angle) * ray_length;
        
        for (float t = 0; t <= 1.0; t += 0.01) {
            float px = lerp(data->sun_x, ray_end_x, t);
            float py = lerp(data->sun_y, ray_end_y, t);
            
            if (px >= 0 && px < WIDTH && py >= 0 && py < HEIGHT) {
                float alpha = (1.0 - t) * ray_intensity;
                
                // Rays color based on time of day
                unsigned char r = 255;
                unsigned char g = data->time_of_day > 0.5 ? 
                                 lerp(220, 180, (data->time_of_day - 0.5) * 2) : 220;
                unsigned char b = data->time_of_day > 0.5 ? 
                                 lerp(100, 50, (data->time_of_day - 0.5) * 2) : 100;
                
                unsigned int color = rgba(r, g, b, (int)(alpha * 255));
                char *dst = data->addr + ((int)py * data->line_len + (int)px * (data->bpp / 8));
                *(unsigned int *)dst = color;
            }
        }
    }
}

// Create a gradient sky background
void draw_sky_gradient(t_data *data) {
    // Color variations based on time of day
    unsigned char top_r, top_g, top_b;
    unsigned char bot_r, bot_g, bot_b;
    
    if (data->time_of_day < 0.4) {
        // Morning to midday
        top_r = 135;
        top_g = 206;
        top_b = 235;
        bot_r = 95;
        bot_g = 165;
        bot_b = 215;
    } else if (data->time_of_day < 0.6) {
        // Midday
        top_r = 135;
        top_g = 206;
        top_b = 235;
        bot_r = 95;
        bot_g = 165;
        bot_b = 215;
    } else {
        // Sunset/evening
        float sunset_factor = (data->time_of_day - 0.6) / 0.4;
        top_r = lerp(135, 190, sunset_factor);
        top_g = lerp(206, 158, sunset_factor);
        top_b = lerp(235, 208, sunset_factor);
        bot_r = lerp(95, 255, sunset_factor);
        bot_g = lerp(165, 183, sunset_factor);
        bot_b = lerp(215, 107, sunset_factor);
    }
    
    for (int y = 0; y < HEIGHT; y++) {
        // Calculate gradient ratio (0 at top, 1 at bottom)
        float ratio = (float)y / HEIGHT;
        
        // Sky gradient
        unsigned char r = lerp(top_r, bot_r, ratio);
        unsigned char g = lerp(top_g, bot_g, ratio);
        unsigned char b = lerp(top_b, bot_b, ratio);
        
        unsigned int color = rgba(r, g, b, 0xFF);
        
        for (int x = 0; x < WIDTH; x++) {
            char *dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
            *(unsigned int *)dst = color;
        }
    }
}

// Initialize a single cloud with more realistic blob configuration
void init_cloud(t_cloud *cloud, float start_x) {
    cloud->x = start_x;
    cloud->y = 50 + rand() % (HEIGHT / 2 - 100);  // Top half of screen, with margin
    cloud->speed = (0.001 * CLOUD_SPEED) + ((float)rand() / (float)RAND_MAX) * 0.3;  // Slower, more realistic motion
    cloud->cloud_type = ((float)rand() / (float)RAND_MAX); // Type of cloud (0=fluffy, 1=wispy)
    cloud->altitude = ((float)rand() / (float)RAND_MAX); // Relative altitude (affects coloring)
    
    // Vary the cloud complexity based on type
    int base_blobs = cloud->cloud_type < 0.5 ? 6 : 4; // Fluffy clouds have more base blobs
    cloud->blob_count = base_blobs + rand() % (MAX_BLOBS - base_blobs);
    
    // Create a main central blob
    cloud->blobs[0].x_offset = 0;
    cloud->blobs[0].y_offset = 0;
    cloud->blobs[0].radius = 35 + rand() % 30;  // 35-65 pixels
    cloud->blobs[0].density = 0.7 + ((float)rand() / (float)RAND_MAX) * 0.3; // 0.7-1.0
    cloud->blobs[0].brightness = 0.9 + ((float)rand() / (float)RAND_MAX) * 0.2; // 0.9-1.1
    
    // Determine overall cloud width for blob placement
    float cloud_width_factor = 1.0 + ((float)rand() / (float)RAND_MAX) * 1.5; // 1.0-2.5
    
    // Add surrounding blobs with varying properties based on cloud type
    for (int i = 1; i < cloud->blob_count; i++) {
        // Different blob patterns based on cloud type
        float angle;
        float distance;
        
        if (cloud->cloud_type < 0.5) { // Fluffy cumulus
            angle = ((float)rand() / (float)RAND_MAX) * M_PI * 2;
            distance = (20 + ((float)rand() / (float)RAND_MAX) * 40) * cloud_width_factor;
        } else { // Wispy cirrus/stratus
            // More horizontal stretching for wispy clouds
            angle = ((float)rand() / (float)RAND_MAX) * M_PI * 0.7 - M_PI * 0.35; // Mostly horizontal
            distance = (25 + ((float)rand() / (float)RAND_MAX) * 50) * cloud_width_factor;
        }
        
        // Calculate position
        cloud->blobs[i].x_offset = cosf(angle) * distance;
        // Flatten cloud vertically - more for wispy clouds
        float vertical_factor = cloud->cloud_type < 0.5 ? 0.6 : 0.35;
        cloud->blobs[i].y_offset = sinf(angle) * distance * vertical_factor;
        
        // Randomize blob properties
        if (cloud->cloud_type < 0.5) { // fluffy
            cloud->blobs[i].radius = 20 + rand() % 35;  // 20-55 pixels
            cloud->blobs[i].density = 0.6 + ((float)rand() / (float)RAND_MAX) * 0.4; // 0.6-1.0
        } else { // wispy
            cloud->blobs[i].radius = 15 + rand() % 25;  // 15-40 pixels
            cloud->blobs[i].density = 0.3 + ((float)rand() / (float)RAND_MAX) * 0.5; // 0.3-0.8
        }
        
        // Vary brightness slightly for more natural look
        cloud->blobs[i].brightness = 0.85 + ((float)rand() / (float)RAND_MAX) * 0.3; // 0.85-1.15
    }
    
    // Add a few extra small detail blobs near the edges for more complexity
    int extra_blobs = cloud->blob_count < MAX_BLOBS - 2 ? 2 : MAX_BLOBS - cloud->blob_count;
    for (int i = 0; i < extra_blobs && cloud->blob_count < MAX_BLOBS; i++) {
        int idx = cloud->blob_count;
        
        // Find a random existing blob to attach to (preferring edge blobs)
        int attach_idx = 1 + rand() % (cloud->blob_count - 1);
        
        // Small offset from the existing blob
        float angle = ((float)rand() / (float)RAND_MAX) * M_PI * 2;
        float distance = 5 + ((float)rand() / (float)RAND_MAX) * 15;
        
        cloud->blobs[idx].x_offset = cloud->blobs[attach_idx].x_offset + cosf(angle) * distance;
        cloud->blobs[idx].y_offset = cloud->blobs[attach_idx].y_offset + sinf(angle) * distance * 0.7;
        cloud->blobs[idx].radius = 10 + rand() % 20;  // 10-30 pixels
        cloud->blobs[idx].density = 0.4 + ((float)rand() / (float)RAND_MAX) * 0.3; // 0.4-0.7
        cloud->blobs[idx].brightness = 0.9 + ((float)rand() / (float)RAND_MAX) * 0.2; // 0.9-1.1
        
        cloud->blob_count++;
    }
}

void init_clouds(t_data *data) {
    srand(time(NULL));
    g_seed = time(NULL); // Initialize noise generator
    
    // Random time of day (affects cloud coloring)
    data->time_of_day = ((float)rand() / (float)RAND_MAX);
    
    // Position clouds across the whole screen initially
    for (int i = 0; i < CLOUD_COUNT; i++) {
        float start_x = (i * WIDTH / CLOUD_COUNT) - 100 + rand() % 200;
        init_cloud(&data->clouds[i], start_x);
    }
    
    // Set sun position
    data->sun_x = WIDTH * 0.85;
    data->sun_y = HEIGHT * 0.2;
}

int render_next_frame(void *param) {
    t_data *data = (t_data *)param;
    
    // Draw sky gradient
    draw_sky_gradient(data);
    
    // Draw sun
    draw_sun(data);
    
    // Update and draw clouds
    for (int i = 0; i < CLOUD_COUNT; i++) {
        t_cloud *cloud = &data->clouds[i];
        
        // Update cloud position
        cloud->x += cloud->speed;
        
        // Calculate cloud width for wrapping
        float rightmost_blob_offset = 0;
        float leftmost_blob_offset = 0;
        
        for (int j = 0; j < cloud->blob_count; j++) {
            rightmost_blob_offset = fmaxf(rightmost_blob_offset, 
                                     cloud->blobs[j].x_offset + cloud->blobs[j].radius);
            leftmost_blob_offset = fminf(leftmost_blob_offset, 
                                    cloud->blobs[j].x_offset - cloud->blobs[j].radius);
        }
        
        // If cloud has moved fully off screen to the right
        if (cloud->x - leftmost_blob_offset > WIDTH) {
            // Respawn from the left side with new random properties
            float max_radius = 0;
            for (int j = 0; j < cloud->blob_count; j++) {
                max_radius = fmaxf(max_radius, cloud->blobs[j].radius);
            }
            
            cloud->x = -rightmost_blob_offset - 20;  // Ensure it's fully off-screen
            
            // Reset this cloud with new properties
            init_cloud(cloud, cloud->x);
        }
        
        // Draw the cloud
        draw_cloud(data, cloud);
    }
    
    // Update frame counter
    data->frame += 1;
    
    // Display the image
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
    
    return (0);
}

int key_handler(int keycode, void *param) {
    t_data *data = (t_data *)param;
    
    // ESC key exits the program
    if (keycode == 53) {
        mlx_destroy_window(data->mlx, data->win);
        exit(0);
    }
    
    // Space key cycles time of day
    if (keycode == 49) {
        data->time_of_day += 0.2;
        if (data->time_of_day > 1.0)
            data->time_of_day = 0.0;
        
        printf("Time of day changed: %.1f\n", data->time_of_day);
    }
    
    return (0);
}

int main(void) {
    t_data data;
    
    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Realistic Cloud Simulation");
    data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
    data.addr = mlx_get_data_addr(data.img, &data.bpp, &data.line_len, &data.endian);
    data.frame = 0;
    
    init_clouds(&data);
    
    mlx_hook(data.win, 2, 1L<<0, key_handler, &data);
    mlx_loop_hook(data.mlx, render_next_frame, &data);
    mlx_loop(data.mlx);
    
    return (0);
}

