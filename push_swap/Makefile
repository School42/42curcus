NAME        = push_swap
LIBFT       = ./libft
HEADERS     = -I ./include -I ${LIBFT}

LIBS        = ${LIBFT}/libft.a

SRCS_DIR    = src/

SRC         = create_stack.c \
				handle.c \
				push_swap.c \
				quick_sort.c \
				push_operations.c \
				reverse_rotate_operations.c \
				rotate_operations.c \
				swap_operations.c \
				utils_init.c \
				utils.c \
				utils_two.c \
				good_sort.c \
				main_sort.c \
				moves.c \
				error_free.c 

SRCS        = $(addprefix ${SRCS_DIR}, ${SRC})
OBJS        = ${SRCS:.c=.o}


CC          = cc

CFLAGS      = -Wall -Werror -Wextra

all:        libft ${NAME}

norm: 
	@norminette libft src include

libft:
	@${MAKE} -C ${LIBFT}

%.o: %.c include/push_swap.h
	${CC} ${CFLAGS} -o $@ -c $< ${HEADERS}

${NAME}: ${OBJS} include/push_swap.h Makefile
	${CC} ${CFLAGS} ${OBJS} ${LIBS} ${HEADERS} -o ${NAME}


clean:
	@rm -rf ${OBJS} ${OBJS_B}
	@rm -rf ${LIBFT}/*.o

fclean:     clean
	@rm -rf ${NAME}
	@rm -rf ${LIBS}

re:         fclean all

.PHONY:     all clean fclean re libft norm
