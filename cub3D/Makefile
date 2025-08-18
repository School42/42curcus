NAME        = cub3D

LIBFT_PATH  = ./libft/
LIBFT_NAME 	= libft.a
LIBFT 		= ${LIBFT_PATH}${LIBFT_NAME}

MLX_PATH 	= ./minilibx-linux/
MLX_NAME 	= libmlx.a
MLX 		= ${MLX_PATH}${MLX_NAME}

SRCS_DIR    = ./src/

SRC         = main.c \
				utility.c \
				create_game_map.c \
				check_texture_color.c \
				copy_texture_color.c \
				free.c \
				free_two.c \
				init.c \
				print.c \
				utility_two.c \
				utility_three.c \
				utility_four.c \
				validation_texture_color.c \
				copy_map_lines.c \
				validate_game_map.c \
				render_game.c \
				handle_hook.c \
				init_mlx.c \
				init_ray.c \
				init_texture.c \
				mouse_move.c \
				render_frame.c \
				render_images.c \
				update_texture.c \
				raycasting.c \
				render_raycast.c \
				player_move.c \
				validate_move.c \
				player_rotate.c \
				init_player_dir.c \
				longest_line.c \
				validate_line_by_line.c \
				valid_wall.c \

OBJ_PATH 	= ./objs/
OBJ 		= ${SRC:.c=.o}
OBJS 		= ${addprefix ${OBJ_PATH}, ${OBJ}}

CC          = cc
BONUS_FLAG	= -DBONUS=0
CFLAGS      = -Wall -Wextra -Werror -g3 ${BONUS_FLAG}

INC 		= -I ./include/\
				-I ./libft/\
				-I ./minilibx-linux/

all: ${OBJ_PATH} ${MLX} ${LIBFT} ${NAME}

${OBJ_PATH}:
		mkdir -p ${OBJ_PATH}

${OBJ_PATH}%.o: ${SRCS_DIR}%.c
		@${CC} ${CFLAGS} -c $< -o $@ ${INC}

${NAME}: ${OBJS}
		${CC} ${CFLAGS} ${OBJS} -o $@ ${INC} ${LIBFT} ${MLX} -lXext -lX11 -lm -lz

norm: 
	@norminette libft src include

${LIBFT}:
	@${MAKE} -sC ${LIBFT_PATH}

${MLX}:
	@${MAKE} -sC ${MLX_PATH}

clean:
	@rm -rf ${OBJ_PATH}
	@make -C ${LIBFT_PATH} clean
	@make -C ${MLX_PATH} clean

fclean:     clean
	@rm -rf ${NAME}
	@make -C ${LIBFT_PATH} fclean

re:         fclean all

bonus: BONUS_FLAG=-DBONUS=1
bonus: fclean all

.PHONY:     all clean fclean re libft norm bonus
