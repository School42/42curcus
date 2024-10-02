SRCS = ft_parse.c ft_printf.c ft_printf_char.c ft_printf_int.c ft_put_util.c ft_util.c ft_printf_uint.c ft_printf_ptr.c ft_printf_hex.c
#ft_printf.c ft_puthex.c ft_putptr.c ft_putstr.c ft_uint.c
OBJS = ${SRCS:.c=.o}
NAME = libftprintf.a
LIBC = ar rcs
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

bonus: all

.PHONY : all clean fclean re bonus