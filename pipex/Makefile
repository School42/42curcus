NAME        = pipex
LIBFT       = ./libft
HEADERS     = -I ./include -I ${LIBFT}

LIBS        = ${LIBFT}/libft.a

SRCS_DIR    = src/

SRC         = pipex.c utils_bonus.c utils_one.c utils_two.c utils_three.c

SRCS        = $(addprefix ${SRCS_DIR}, ${SRC})
OBJS        = ${SRCS:.c=.o}

SRC_B       = pipex_bonus.c utils_bonus.c utils_one.c utils_two.c utils_three.c

SRCS_B      = $(addprefix ${SRCS_DIR}, ${SRC_B})
OBJS_B      = ${SRCS_B:.c=.o}

CC          = cc

CFLAGS      = -Wall -Werror -Wextra -g3 -fsanitize=address 

all:        libft ${NAME}

norm: 
	@norminette libft src include

libft:
	@${MAKE} -C ${LIBFT}

%.o: %.c include/pipex.h
	${CC} ${CFLAGS} -o $@ -c $< ${HEADERS}

${NAME}: ${OBJS} include/pipex.h
	${CC} ${CFLAGS} ${OBJS} ${LIBS} ${HEADERS} -o ${NAME}

bonus:      libft ${OBJS_B}
	${CC} ${CFLAGS} ${OBJS_B} ${LIBS} ${HEADERS} -o ${NAME}

clean:
	@rm -rf ${OBJS} ${OBJS_B}
	@rm -rf ${LIBFT}/*.o

fclean:     clean
	@rm -rf ${NAME}
	@rm -rf ${LIBS}

re:         fclean all

.PHONY:     all clean fclean re libft norm bonus
