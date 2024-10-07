/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bworrawa <bworrawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 10:16:19 by bworrawa          #+#    #+#             */
/*   Updated: 2024/09/30 10:46:17 by bworrawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>
# include <MLX42/MLX42.h>
# include "libft.h"
# include "ft_printf.h"

# define SL_GAME_TITLE "So Long ... and Thanks for the Fish"
# define GW 100
# define GH 100

# define MIN_MW	 3
# define MIN_MH  3
# define MAX_MW  35
# define MAX_MH  18

// fonts
# define FW 50
# define FH 50
# define FS 5

// player width / heigth 
# define PW 100
# define PH 150 

# define READ_BUF_SIZE  2500

// Codes (for map) 
# define CP 'P'
# define CC 'C'
# define CE 'E'
# define CW '1'
# define CF '0'
# define CM 'M'

// Sprites Indexes
# define SI_F 0
# define SI_WU 1
# define SI_WR 2
# define SI_WD 3
# define SI_WL 4
# define SI_WI 5
# define SI_WII 6
# define SI_WIII 7
# define SI_C1 8
# define SI_C2 9
# define SI_M 10
# define SI_M2 11

# define SI_P  12
# define SI_PW 13
# define SI_E  14
# define SI_MOVES    15
# define SI_MAX 16

// digits offet
# define SP_D_OS 20

// monsters
# define SP_MAX 31
# define SI_PMAX 14

// Player status
# define PS_IDLE    1
# define PS_WALKING 2
# define PS_DEAD    3

// Monster status
# define MS_IDLE    1
# define MS_WALKING 2
# define MS_THINKING 3

# define PS_WON    5

// direction , player face direction
# define DU    1
# define DR    2
# define DD    3
# define DL    4

// borders
# define BT     100
# define BL     100
# define BB     100
# define BR     100

// translated map   F = floor , W = wall , P = path 
# define TM_F   '0'
# define TM_W   'X'
# define TM_P   '1'
# define TM_M   'M'

# define GS_ACTIVE    1
# define GS_INACTIVE  0  
# define GS_GAMEOVER_WON  10
# define GS_GAMEOVER_LOSE  5

# define MAX_MONSTERS   10
# define MAX_COLLS      30

# define CS_IDLE        1
# define CS_COLLECTED   10

// Player Sprite index
# define PSI_WON    12
# define PSI_LOST   13

// Frame Rate
# define FR_PLAYER          25
# define FR_MONSTER_THINK   20
# define FR_MONSTER_WALK    25

// Total Frame Rate
# define TFR_COLL 120
# define TFR_COLL_V 360

# define P_STEP_SIZE 4
# define M_STEP_SIZE 4

typedef struct s_coord
{
	ssize_t	x;
	ssize_t	y;
}	t_coord;

typedef struct s_dim
{
	size_t	w;
	size_t	h;
}	t_dim;

typedef struct s_sl_player
{
	t_coord		pos;
	size_t		face;
	int			status;
	mlx_image_t	*sprites[15];
}	t_sl_player;

typedef struct s_sl_monster
{
	t_coord	pos;
	size_t	frame_value;
	size_t	think_frames;
	size_t	walk_frames;
	size_t	next_move;
	int		status;
}	t_sl_monster;

typedef struct s_sl_coll
{
	t_coord			pos;
	int				enabled;
	unsigned int	status;
}	t_sl_coll;

typedef struct s_sl_exit
{
	t_coord	pos;
	int		enable;
}	t_sl_exit;

typedef struct s_game
{
	mlx_t			*mlx;
	size_t			n_monsters;
	size_t			n_colls;
	size_t			n_collected;
	size_t			n_moves;
	t_coord			msize;
	char			**map;
	char			**path;
	char			**m_path;
	int				status;
	t_sl_player		player;
	t_sl_exit		exit;
	t_sl_monster	monsters[MAX_MONSTERS];
	t_sl_coll		colls[MAX_COLLS];
	mlx_image_t		*sprites[SP_MAX];
}	t_game;

// sprites.c
char	**get_p_sprites(void);
char	**get_font_sprites(void);
char	**get_misc_sprites(void);

// sprite_loader.c
int		load_sprite(mlx_t *mlx, char *path, mlx_image_t **img, t_dim dim);
int		load_p_sprites(t_game *g);
int		load_misc_sprites(t_game *g);
int		load_font_sprites(t_game *g);

// setup.c
int		load_assets(t_game *g);
int		read_map(t_game *g, const char *path);

// nick.h
int32_t	im_to_w(mlx_t *mlx, mlx_image_t *im, int32_t x, int32_t y);

// render.c
void	render(t_game *g);
void	render_score(t_game *g);
void	render_score_misc(t_game *g);

// render_map.c
void	render_map(t_game *g, ssize_t *offset_y, ssize_t *offest_x);
void	render_colls(t_game *g, ssize_t *offset_y, ssize_t *offest_x);

// redner_display.c
void	display_left(t_game *g);
void	display_full_score(t_game *g);
void	display_moves(t_game *g);

// events
int		is_valid_move(t_game *g, ssize_t dir);
void	cb_x_button_pressed(void *param);
void	cb_detect_keys(mlx_key_data_t keydata, void *param);

// validate.c
int		validate_first(t_game *g, char *buf);
int		validate_map(t_game *g);
int		validate_map_shape(t_game *g);
int		valid_map_path(t_game *g);

// validate_utils.c
int		validate_map_items(t_game *g);
int		check_map_char(t_game *g, char c, t_coord pos);
int		check_map_mon(t_game *g, char c, t_coord pos);

// errors.c
int		sl_exit(t_game *g, char *message);
int		sl_clean_exit(t_game *g, char *message);

// animate_colls.c
void	animate_colls(t_game *g);
void	animate_colls_v(t_game *g);

// animate_player.c
void	animate_player(t_game *g);

// animate_monsters.c
int		animate_monsters_move(t_game *g);
void	animate_monsters(t_game *g);

// game_utils.c
int		check_player_pos(t_game *g, t_sl_player *pl);
void	get_dir_delta(int d, ssize_t *dlt_x, ssize_t *dlt_y);
t_dim	get_dim(size_t w, size_t h);
t_coord	get_coord(ssize_t x, ssize_t y);
char	**copy_map(char **map, void (*f)(unsigned int, char *));
char	least_of_four_side(t_game *g, char **map, t_coord xy);

// utils.c
int		cleanup_all(t_game *g);
int		cleanup_map(char **map);

// flood_fill.c 
int		ir(int num, int min, int max);
void	flood_fill(t_game *g, char **map, t_coord coord, int number);
void	flood_fill_inc(t_game *g, char **map, t_coord coord, int number);

// animate.c
void	animate(void *param);
void	check_monster_kill(t_game *g);

// game_utils.c
int		monsters_think(t_game *g);
int		monster_can_move(t_game *g, size_t index, size_t d);

#endif
