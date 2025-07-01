/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:34:38 by talin             #+#    #+#             */
/*   Updated: 2025/07/01 16:52:36 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include "../libft/libft.h"
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

typedef struct s_player_pos
{
	int		x;
	int		y;
	char	pos;
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


typedef struct s_data
{
	t_tex_color	*tex_color;
	t_game_map	*map;
}	t_data;

int			ft_file_extension(char *filename);
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
void		ft_finding_pos_map(t_data *data);
void		print_game_map(char **game_map);
int			ft_find_longest_length(t_data *data);
char		*copy_map_lines(int size, char *src);
int			validate_game_map(t_game_map *map);
int			valid_char(int c);

#endif