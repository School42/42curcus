NAME        = so_long
LIBFT       = ./libft
LIBMLX      = ./MLX42
HEADERS 	=  -I ./includes -I ${LIBFT} -I ${LIBMLX}/include

LIBS		= ${LIBMLX}/build/libmlx42.a -ldl -lglfw -pthread -lm ${LIBFT}/libft.a

SRCS_DIR	= src/

SRC 		= map_reader.c \
				map_reader_two.c \
				map_reader_three.c \
				flood_fill.c \
				flood_fill_two.c \
				so_long.c \
				game_window.c \
				put_img.c \
				load_assets.c \
				key_hook.c \
				check_finish.c \
				enemy_move.c \
				print_moves.c \
				game_over.c

SRCS    	= ${addprefix ${SRCS_DIR}, ${SRC}}

OBJS 		= ${SRCS:.c=.o}

CC			= cc

CFLAGS 		= -Wall -Werror -Wextra -g3 -fsanitize=address 


all:   libmlx libft ${NAME}

norm: 
	@norminette libft src include

libft:
	@${MAKE} -C ${LIBFT}

libmlx:
	@cmake ${LIBMLX} -B ${LIBMLX}/build && make -C ${LIBMLX}/build -j4

%.o: %.c	Makefile include/so_long.h
	${CC} ${CFLAGS} -o $@ -c $< ${HEADERS}

${NAME}: ${OBJS}	include/so_long.h
	${CC} ${CFLAGS} ${OBJS} ${LIBS} ${HEADERS} -o ${NAME}

clean:
	@rm -rf ${OBJS}
	@rm -rf ${LIBMLX}/build
	@rm -rf ${LIBFT}/*.o

fclean:		clean
	@rm -rf ${NAME}
	@rm -rf ${LIBFT}/libft.a
	

re:		clean all


.PHONY:	 all, clean , fclean, re , libft , libmlx , norm
