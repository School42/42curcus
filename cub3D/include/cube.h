/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:34:38 by talin             #+#    #+#             */
/*   Updated: 2025/08/18 17:06:54 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <errno.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include <X11/keysym.h>
# include <X11/X.h>

# ifndef BONUS
#  define BONUS 0
# endif

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

// # define KEY_ESCAPE 53
// # define KEY_W 13
// # define KEY_A 0
// # define KEY_S 1
// # define KEY_D 2
// # define KEY_LEFT 123
// # define KEY_RIGHT 124

# define ERR_USAGE "usage: ./cub3d <path/to/map.cub>"

# define ERR_FILE_NOT_CUB "Not a .cub file"
# define ERR_FILE_NOT_XPM "Not an .xpm file"
# define ERR_TEXTURE_FILE "More than one texture file is provided"
# define ERR_EMPTY "Empty file"
# define ERR_FILE_IS_DIR "Is a directory"
# define ERR_COLOR_CODE "Not a valid color code"
# define ERR_MUL_COL "So many color codes than needed"
# define ERR_INVALID_ELE "Invalid element information is found"
# define ERR_CANT_COPY "Cannot be copied, system error"
# define ERR_MAP_NOT_CREATED "Map is not created"
# define ERR_FLOOR_CEILING "Invalid floor/ceiling RGB color(s)"
# define ERR_COLOR_FLOOR "Invalid floor RGB color"
# define ERR_COLOR_CEILING "Invalid ceiling RGB color"
# define ERR_INVALID_MAP "Map description is either wrong or incomplete"
# define ERR_INV_LETTER "Invalid character in map"
# define ERR_NUM_PLAYER "Map has more than one player"
# define ERR_NO_PLAYER "No player"
# define ERR_COLOR_RGB_VAL "Invalid RGB value (min: 0, max: 255)"
# define ERR_TEX_MISSING "Missing texture(s)"
# define ERR_TEX_INVALID "Invalid texture(s)"
# define ERR_COLOR_MISSING "Missing color(s)"
# define ERR_MAP_MISSING "Missing map"
# define ERR_MAP_TOO_SMALL "Map is not at least 3 lines high"
# define ERR_MAP_SPACE_FLOOR "Floor is near space"
# define ERR_MAP_NO_WALLS "Map is not surrounded by walls"
# define ERR_MAP_NL "New line is found in the map"
# define ERR_MAP_LAST "Map is not the last element in file"
# define ERR_PLAYER_POS "Invalid player position"
# define ERR_PLAYER_DIR "Map has no player position (expected N, S, E or W)"
# define ERR_MALLOC "Could not allocate memory"
# define ERR_MLX_START "Could not start mlx"
# define ERR_MLX_WIN "Could not create mlx window"
# define ERR_MLX_IMG "Could not create mlx image"
# define ERR_MUL_ELE "More than needed element informations (duplicate data)"

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080

# define MINI_PIXEL_SIZE 128
# define MINI_VIEW_DIST 5
# define MINI_COLOR_PLAYER 0xFFFFFF
# define MINI_COLOR_WALL 0x808080
# define MINI_COLOR_FLOOR 0xE6E6E6
# define MINI_COLOR_SPACE 0x404040

# define SPEED 0.1
# define MOUSE_SPEED 0.03
# define ROTATE_SPEED 0.05
# define TEX_SIZE 64

enum e_texture_index
{
	NORTH = 0,
	SOUTH = 1,
	EAST = 2,
	WEST = 3
};

typedef struct s_tex_color
{
	char			*north_texture;
	char			*south_texture;
	char			*east_texture;
	char			*west_texture;
	int				*floor_color;
	int				*ceiling_color;
	int				check_texture_color;
	unsigned int	hex_floor;
	unsigned int	hex_ceiling;
	int				size;
	int				index;
	double			step;
	double			pos;
	int				y;
	int 			x;
}	t_tex_color;

typedef struct s_vec
{
	int		x;
	int		y;
}	t_vec;

typedef struct s_player_pos
{
	double	x;
	double	y;
	char	pos;
}	t_player_pos;


typedef struct s_game_map
{
	char			**map;
	char			**game_map;
	int				num_player;
	t_player_pos	*player;
	int				ln_count;
	int				start;
	int				end;
	int				width;
	int				height;
}	t_game_map;

typedef struct s_img
{
	void 	*img;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_ray
{
	double 	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	side_dist_x;
	double	side_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	double	wall_x;
}	t_ray;

typedef struct s_window
{
	void	*mlx;
	void	*mlx_win;
	int		win_width;
	int		win_height;
	int		**t_pixel;
	int		**textures;
}	t_window;

typedef struct s_player
{
	char	dir;
	double	pos_x;
	double	pos_y;
	double	plane_x;
	double	plane_y;
	double	dir_x;
	double	dir_y;
	int		has_moved;
	int		move_x;
	int		move_y;
	int		mouse_x;
	int		rotate;
}	t_player;


typedef struct s_data
{
	t_tex_color	*tex_color;
	t_game_map	*map;
	t_window	*win;
	t_player	*player;
	t_ray		ray;
}	t_data;

void		error_ft(char *err);
void		free_data(t_data *data);
int			ft_file_extension(char *filename, char *ext);
int			ft_strcmp(char *s1, char *s2);
t_data		*ft_create_game_map(char **av, int fd);
void		print_map(t_data *data);
size_t		ft_length_str_arr(char **string_arr);
int			ft_color_check(char *color);
int			ft_check_texture_color(t_tex_color *tex_color);
void		copy_texture_color(t_data *data, char **string_arr);
char		*copy_color_codes(char **string_arr);
char		**ft_making_map(int fd, int size);
void		ft_free_string_arr(char **string_arr);
t_game_map	*ft_init_mapping(void);
char		*concat(const char *s1, const char *s2);
int			ft_size_map(char *filename);
char		*ft_strdup_cu(const char *s);
int			ft_file_exist(char *filename);
int			ft_check_digit(char *c_code);
int			texture_and_color(t_data *data, int i);
t_data		*init_data(void);
t_tex_color	*ft_init_tex_color(void);
int			*copy_codes(char **string_arr);
int			ft_finding_pos_map(t_data *data);
void		print_game_map(char **game_map);
int			ft_find_longest_length(t_data *data);
char		*copy_map_lines(int size, char *src);
int			validate_game_map(t_game_map *map);
int			valid_char(int c);
int			is_player(int c);
int			is_floor_player(int c);
int			contain_only_certain_characters(char *src, char *allowed);
void		render_game(t_data *data);
void		init_mlx(t_data *data);
void		init_textures(t_data *d);
int 		handle_mouse_move(int x, int y, t_data *data);
int			render_frame(t_data *data);
int			handle_key_release(int key, t_data *data);
int			handle_key_press(int key, t_data *data);
void		quit_game(t_data *data);
int			handle_close(t_data *data);
void		init_ray(t_ray *ray);
void		init_img_clean(t_img *img);
void		init_texture_img(t_data *data, t_img *tmp, char *filename);
void		init_t_pixel(t_data *data, int h, int w);
void		init_raycasting(int x, t_ray *ray, t_player *player);
int			raycasting(t_player *player, t_data *data);
void		init_img(t_data *data, t_img *img, int width, int height);
void		set_image_pixel(t_img *img, int x, int y, int color);
void		render_images(t_data *data);
void		render_raycast(t_data *data);
void		update_texture(t_ray *ray, t_data *data, int x, t_tex_color *tex);
void		free_t_pixel(void **t_pixel);
int			render(t_data *data);
int			player_move(t_data *data);
int			validate_move(t_data *data, double x, double y);
int			player_rotate(t_data *data, double rotate, double mov_speed);
t_window	*ft_init_win(void);
t_player	*ft_init_player(void);
void		init_player_direction(t_data *d);
int			rotating(t_data *data, double speed);
void		free_window(t_window *w);
void		free_int_arr(int **arr);
int			check_line_by_line(t_game_map *map, char *line, int row);
int			valid_pos(t_game_map *map, int row, int col);
int			upper_wall(t_game_map *map, int row, int col);
int			lower_wall(t_game_map *map, int row, int col);

#endif