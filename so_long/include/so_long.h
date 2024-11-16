/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 10:45:00 by talin             #+#    #+#             */
/*   Updated: 2024/10/28 12:46:01 by talin            ###   ########.fr       */
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

# define WIDTH 64

# define FALSE 0
# define TRUE 1

# define PLAYING 1
# define GAME 2
# define GAMEOVER 3
# define CLOSING 4

# define ENEMY 12

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_assets
{
	mlx_image_t	*rock;
	mlx_image_t	*dino;
	mlx_image_t	*meat;
	mlx_image_t	*grass;
	mlx_image_t	*portal;
	mlx_image_t	*enemy;
}	t_assets;

typedef struct s_texts
{
	mlx_image_t	*move;
	mlx_image_t	*meat;
	mlx_image_t	*mo_ve;
	mlx_image_t	*me_at;
	mlx_image_t	*won;
	mlx_image_t	*playing;
}	t_texts;

typedef struct s_mapping
{
	mlx_t		*mlx;
	t_assets	assets;
	t_assets	images;
	t_texts		texts;
	mlx_image_t	*enemy[ENEMY];
	char		**map;
	char		**game_map;
	int			num_exit;
	int			num_player;
	int			num_collectible;
	int			valid;
	t_point		size;
	bool		portal;
	t_point		player;
	t_point		exit;
	int			playing;
	int			move;
	int			loop;
	int			enemy_int;
	bool		gameover;
	int			consumed_meat;
	int			frame_speed;
	int			frame_count;
	int			current_frame;
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
int			ft_right_path(t_mapping *new);
int			ft_player_exit(t_mapping new, t_point size);
t_point		ft_get_exit(t_mapping new, char c);
void		fill(char **map, t_point size, int row, int col);
void		flood_fill(char **map, t_point size, t_point begin);
int			ft_outsider(t_mapping new);
int			ft_outside(char c);
t_mapping	ft_creat_game_map(char **av, int fd);
int			ft_collectible(t_mapping new);
int			ft_free(t_mapping game);
void		ft_game_window(t_mapping game);
int			ft_load_assets(t_mapping *game);
void		ft_key_hook(mlx_key_data_t keydata, void *param);
int			ft_check_count(t_mapping *game, char c);
void		ft_put_img(t_mapping *game);
void		ft_delete_assets(t_mapping *game);
void		ft_game_won(t_mapping *game);
void		ft_print_game(t_mapping *game);
bool		ft_move_enemy(t_mapping *game, int x, int y);
void		ft_enemy_moves(t_mapping *game);
void		ft_print_moves(t_mapping *game);
void		ft_game_over(t_mapping *game);
void		ft_print_strings(t_mapping *game);
void		ft_print_meat(t_mapping *game);
mlx_image_t	*ft_asset_to_image(mlx_t *mlx, char *img_path);
void		ft_game_over_window(t_mapping *game);
void		ft_get_current_frame(t_mapping *game);
void		ft_delete_enemy_assets(t_mapping *game);
#endif