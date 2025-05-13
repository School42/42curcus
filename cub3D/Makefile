NAME        = cub3D

LIBFT_PATH  = ./libft/
LIBFT_NAME 	= libft.a
LIBFT 		= ${LIBFT_PATH}${LIBFT_NAME}

MLX_PATH 	= ./minilibx-linux/
MLX_NAME 	= libmlx.a
MLX 		= ${MLX_PATH}${MLX_NAME}

HEADERS     = -I ./include -I ${LIBFT}

LIBS        = ${LIBFT}/libft.a

SRCS_DIR    = ./src/

SRC         = test.c

SRCS        = $(addprefix ${SRCS_DIR}, ${SRC})

OBJ_PATH 	= ./objs/
OBJ 		= ${SRC:.c=.o}
OBJS 		= ${addprefix ${OBJ_PATH}, ${OBJ}}

CC          = cc

CFLAGS      = -Wall -Werror -Wextra

INC 		= -I ./include/\
				-I ./libft/\
				-I ./minilibx-linux/

all: ${OBJ_PATH} ${MLX} ${LIBFT} ${NAME}

${OBJ_PATH}:
		mkdir -p ${OBJ_PATH}

${OBJ_PATH}%.o: ${SRCS_DIR}%.c
		${CC} ${CFLAGS} -c $< -o $@ ${INC}

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

.PHONY:     all clean fclean re libft norm
