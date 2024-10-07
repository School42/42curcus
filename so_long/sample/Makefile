NAME        = so_long
LIBMLX      = ./MLX42
LIBFT       = ./libft
LIBPRINTF   = ./ft_printf

HEADERS 	=  -I ./includes -I ${LIBMLX}/include -I ${LIBFT} -I ${LIBPRINTF}

LIBGL 		= -lglfw -L"/Users/erigolon/.brew/opt/glfw/lib" -g3 -fsanitize=address

LIBS		= ${LIBGL} ${LIBMLX}/libmlx42.a ${LIBPRINTF}/libftprintf.a ${LIBFT}/libft.a 


SRCS    	= so_long.c	\
			sprites.c \
			sprite_loader.c \
			setup.c \
			events.c \
			utils.c \
			errors.c \
			validate.c \
			validate_utils.c \
			flood_fill.c \
			render.c \
			render_map.c \
			render_display.c \
			animate.c \
			animate_colls.c \
			animate_player.c \
			animate_monsters.c \
			monster_moves.c \
			game_utils.c \
			game_moves.c \
			nick.c

OBJS 		= ${SRCS:.c=.o}

CC			= cc
CFLAGS 		= -Wall -Werror -Wextra -g3 -fsanitize=address 


all:      libft   libmlx libprintf ${NAME}



libft:
	@${MAKE} -C ${LIBFT}

libmlx:
	@${MAKE} -C ${LIBMLX}

libprintf:
	@${MAKE} -C ${LIBPRINTF}

%.o: %.c	Makefile so_long.h
	${CC} ${CFLAGS} -o $@ -c $< ${HEADERS}

${NAME}: ${OBJS}	so_long.h
	${CC} ${CFLAGS} ${OBJS} ${LIBS} ${HEADERS} -o ${NAME}

clean:
	@${MAKE} -C ${LIBFT} clean
	@${MAKE} -C ${LIBMLX} clean
	@${MAKE} -C ${LIBPRINTF} clean
	rm -f ${OBJS}

fclean:		clean
	rm -f ${NAME}
	@${MAKE} -C ${LIBFT} fclean
	@${MAKE} -C ${LIBMLX} fclean
	@${MAKE} -C ${LIBPRINTF} fclean
	

re:		clean all


.PHONY:	 all,clean , fclean, re , libmlx  , libft