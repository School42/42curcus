NAME        = pipex
LIBFT       = ./libft
HEADERS 	=  -I ./include -I ${LIBFT}

LIBS		= ${LIBFT}/libft.a

SRCS_DIR	= src/

SRC 		= read.c \
				read_two.c \
				pipex.c

SRCS    	= ${addprefix ${SRCS_DIR}, ${SRC}}

OBJS 		= ${SRCS:.c=.o}

CC			= cc

CFLAGS 		= -Wall -Werror -Wextra -g3 
# -fsanitize=address 


all:   libft ${NAME}

norm: 
	@norminette libft src include

libft:
	@${MAKE} -C ${LIBFT}

%.o: %.c	Makefile include/pipex.h
	${CC} ${CFLAGS} -o $@ -c $< ${HEADERS}

${NAME}: ${OBJS}	include/pipex.h
	${CC} ${CFLAGS} ${OBJS} ${LIBS} ${HEADERS} -o ${NAME}

clean:
	@rm -rf ${OBJS}
	@rm -rf ${LIBFT}/*.o

fclean:		clean
	@rm -rf ${NAME}
	@rm -rf ${LIBS}
	

re:		clean all


.PHONY:	 all, clean , fclean, re , libft , libmlx , norm
