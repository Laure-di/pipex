NAME	=		pipex

SRCS_DIR	=	srcs/

SRCS_FILES	=	pipex.c \
				fd_write.c \
				libft.c \
				ft_split.c \
				libft_2.c \
				parsing.c \
				exit.c

OBJS	=	${addprefix ${SRCS_DIR}, ${SRCS_FILES:.c=.o}}

HEAD	=	-I include

CC	= clang

CFLAGS	= -Wall -Werror -Wextra -g3

.o:.c
		${CC} ${CFLAGS} ${HEAD} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
					${CC} ${CFLAGS} ${HEAD} ${OBJS} -o ${NAME}

all:		${NAME}

clean:
			rm -rf ${OBJS}

fclean: clean
			rm -rf ${NAME}

re: fclean all
