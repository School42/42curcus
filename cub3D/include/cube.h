/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:34:38 by talin             #+#    #+#             */
/*   Updated: 2025/07/11 16:05:19 by talin            ###   ########.fr       */
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

typedef struct s_tex_color
{
	char	*north_texture;
	char	*south_texture;
	char	*east_texture;
	char	*west_texture;
	int		*floor_color;
	int		*ceiling_color;
	int		check_texture_color;
}	t_tex_color;

typedef struct s_vec
{
	int		x;
	int		y;
}	t_vec;


typedef struct s_player_pos
{
	int		x;
	int		y;
	char	pos;
	int		dir_x;
	int		dir_y;
	int		plane_x;
	int		plane_y;
	int		has_moved;
	int		move_x;
	int		move_y;
	int		rotate;
}	t_player_pos;


typedef struct s_game_map
{
	char	**map;
	char	**game_map;
	int		num_player;
	t_player_pos	*player;
	int		ln_count;
	int		start;
	int		end;
	int		width;
	int		height;
}	t_game_map;

typedef struct s_window
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	void	*xpm_img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_window;

typedef struct s_data
{
	t_tex_color	*tex_color;
	t_game_map	*map;
	t_window	*win;
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
int			texture_and_color(t_data *data);
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

#endif