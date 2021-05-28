# -*- My first Makefile, let's see how it goes... -*-

CC	= gcc
NAME	= libft.a
SRCS	=	ft_strlen.c ft_strlcpy.c ft_isalpha.c ft_isdigit.c ft_isalnum.c \
			ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_bzero.c \
			ft_calloc.c
#OBJS	= ft_strlen.o ft_strlcpy.o
CFLAGS	= -std=c99 -Wall -Wextra -Werror 
TFLG	= -lbsd		# test flags @todo remove for grading!!!

OBJS	= ${SRCS:.c=.o}

all:	$(NAME)

$(NAME) : $(OBJS)
	gcc $(CFLAG) -c $(SRCS)
	ar rcs ${NAME} ${OBJS}

# Old way of making, OBJS up uses CFLAGS and makes it voila
# ${CC} ${SRCS} ${FLAGS} ${TFLG} -o ${OBJS}

clean:
	rm -f *.o

fclean: clean
	rm -f ${NAME} test

re:	fclean all

# To Remove
test:
	gcc main.c ${NAME} $(TFLG) -o test -L -lft

.PHONY:	all clean fclean re
