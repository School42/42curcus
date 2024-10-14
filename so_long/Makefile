NAME        = so_long
LIBFT       = ./libft

HEADERS 	=  -I ./includes -I ${LIBFT}

LIBS		= ${LIBFT}/libft.a 

SRCS_DIR	= src/

SRC 		= map_reader.c \
				map_reader_two.c \
				map_reader_three.c \
				flood_fill.c \
				flood_fill_two.c

SRCS    	= ${addprefix ${SRCS_DIR}, ${SRC}}

OBJS 		= ${SRCS:.c=.o}

CC			= cc
CFLAGS 		= -Wall -Werror -Wextra -g3 
# -fsanitize=address 


all:      libft ${NAME}



libft:
	@${MAKE} -C ${LIBFT}

%.o: %.c	Makefile include/so_long.h
	${CC} ${CFLAGS} -o $@ -c $< ${HEADERS}

${NAME}: ${OBJS}	include/so_long.h
	${CC} ${CFLAGS} ${OBJS} ${LIBS} ${HEADERS} -o ${NAME}

clean:
	@${MAKE} -C ${LIBFT} clean
	rm -f ${OBJS}

fclean:		clean
	rm -f ${NAME}
	@${MAKE} -C ${LIBFT} fclean
	

re:		clean all


.PHONY:	 all,clean , fclean, re , libft




# NAME	:= Game
# CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast
# LIBMLX	:= ./MLX42

# HEADERS	:= -I ./include -I $(LIBMLX)/include
# LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
# SRCS	:= test.c
# OBJS	:= ${SRCS:.c=.o}

# all: libmlx $(NAME)

# libmlx:
# 	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

# %.o: %.c
# 	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

# $(NAME): $(OBJS)
# 	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

# clean:
# 	@rm -rf $(OBJS)
# 	@rm -rf $(LIBMLX)/build

# fclean: clean
# 	@rm -rf $(NAME)

# re: clean all

# .PHONY: all, clean, fclean, re, libmlx