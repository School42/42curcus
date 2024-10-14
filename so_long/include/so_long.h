/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 10:45:00 by talin             #+#    #+#             */
/*   Updated: 2024/10/14 15:56:43 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>
# include <errno.h>
# include <string.h>
# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"

# define WIDTH 100

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_mapping
{
	mlx_t	*mlx;
	char	**map;
	char	**game_map;
	int		num_exit;
	int		num_player;
	int		num_collectible;
	int		valid;
	t_point	size;
}	t_mapping;

int			ft_size_map(char *filename, int fd);
char		*ft_strdup_sl(const char *s);
char		**ft_making_map(char **av, int fd);
int			ft_char_check(char str, char c);
t_mapping	ft_init_mapping(void);
t_mapping	ft_error(char *str, t_mapping new);
t_mapping	ft_checking_map(t_mapping new);
int			ft_wall(char *str);
t_mapping	ft_valid_map(t_mapping new);
int			ft_right_path(t_mapping new);
int			ft_player_exit(t_mapping new, t_point size);
t_point		ft_get_exit(t_mapping new, char c);
void		fill(char **map, t_point size, int row, int col);
void		flood_fill(char **map, t_point size, t_point begin);
int			ft_right_path(t_mapping new);
int			ft_outsider(t_mapping new);
int			ft_outside(char c);
t_mapping	ft_creat_game_map(char **av, int fd);
int			ft_collectible(t_mapping new);
int			ft_free(t_mapping game);
void		ft_game_window(t_mapping game);
#endif