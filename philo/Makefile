NAME        = philo
HEADERS     = -I ./include

LIBS        = ${LIBFT}/libft.a

SRCS_DIR    = src/

SRC         = philo.c \
				utils.c \
				utils_two.c \
				init.c \
				routine.c \
				life.c

SRCS        = $(addprefix ${SRCS_DIR}, ${SRC})
OBJS        = ${SRCS:.c=.o}


CC          = cc

CFLAGS      = -Wall -Werror -Wextra

all:        ${NAME}

norm: 
	@norminette src include


%.o: %.c include/philo.h
	${CC} ${CFLAGS} -o $@ -c $< ${HEADERS}

${NAME}: ${OBJS} include/philo.h Makefile
	${CC} ${CFLAGS} ${OBJS} ${HEADERS} -o ${NAME}


clean:
	@rm -rf ${OBJS}

fclean:     clean
	@rm -rf ${NAME}

re:         fclean all

.PHONY:     all clean fclean re norm
