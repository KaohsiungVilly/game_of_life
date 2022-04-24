SRCS	= main.c init_vars.c get_next_line.c \
		game_of_life_utils.c get_next_line_utils.c \
		game_of_life_utils2.c game_of_life.c

OBJS	= ${SRCS:.c=.o}

NAME	= game_of_life

MINILIB	= minilibx_macos/libmlx.a

PATHMLIB	= minilibx_macos/

CC	= gcc

RM	= rm -f

CFLAGS	= -I. -Wall -Wextra -Werror -Imlx -g3 -fsanitize=address

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
				@make -C ${PATHMLIB}
				${CC} ${CFLAGS} ${MINILIB} ${OBJS} -framework OpenGL -framework AppKit -L. -o ${NAME}

all:		${NAME}

clean:
				@make clean -C ${PATHMLIB}
				${RM} ${OBJS}

fclean: 	clean
				@make clean
				${RM} ${NAME}

re: 		fclean all

.PHONY:		all clean fclean re