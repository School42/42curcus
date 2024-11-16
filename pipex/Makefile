NAME        = pipex
NAME_BONUS 	= pipex_bonus
LIBFT       = ./libft
HEADERS     = -I ./include -I ${LIBFT}

LIBS        = ${LIBFT}/libft.a

SRCS_DIR    = src/

SRC         = pipex.c utils_bonus.c utils_one.c utils_two.c utils_three.c utils_four.c

SRCS        = $(addprefix ${SRCS_DIR}, ${SRC})
OBJS        = ${SRCS:.c=.o}

SRC_B       = pipex_bonus.c utils_bonus.c utils_one.c utils_two.c utils_three.c utils_four.c

SRCS_B      = $(addprefix ${SRCS_DIR}, ${SRC_B})
OBJS_B      = ${SRCS_B:.c=.o}

CC          = cc

CFLAGS      = -Wall -Werror -Wextra

all:        libft ${NAME}

bonus:      libft ${NAME_BONUS}

norm: 
	@norminette libft src include

libft:
	@${MAKE} -C ${LIBFT}

%.o: %.c include/pipex.h
	${CC} ${CFLAGS} -o $@ -c $< ${HEADERS}

${NAME}: ${OBJS} include/pipex.h Makefile
	${CC} ${CFLAGS} ${OBJS} ${LIBS} ${HEADERS} -o ${NAME}

${NAME_BONUS}: ${OBJS_B} include/pipex.h Makefile
	${CC} ${CFLAGS} ${OBJS_B} ${LIBS} ${HEADERS} -o ${NAME_BONUS}


clean:
	@rm -rf ${OBJS} ${OBJS_B}
	@rm -rf ${LIBFT}/*.o

fclean:     clean
	@rm -rf ${NAME}
	@rm -rf ${NAME_BONUS}
	@rm -rf ${LIBS}

re:         fclean all

.PHONY:     all clean fclean re libft norm bonus
