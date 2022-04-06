# ***************************************************************************** #
#                                                                               #
#                                                         :::      ::::::::     #
#    Makefile                                           :+:      :+:    :+:     #
#                                                     +:+ +:+         +:+       #
#    By: kmottus <kmottus@student.42wolfsburg.de    +#+  +:+       +#+          #
#                                                 +#+#+#+#+#+   +#+             #
#    Created: 2022/03/08 14:48:00 by kmottus           #+#    #+#               #
#    Updated: 2022/03/08 14:48:00 by kmottus          ###   ########.fr         #
#                                                                               #
# ***************************************************************************** #
 

NAME	= a.out
CC		= gcc
HEADER	= ./ft_printf.h
CFLAGS	= -Wall -Wextra -Werror
SRCS	= ft_printf.c \
		main.c
RM		= rm -fr
LIBFT	= ./libft/libft.a
OBJS	= ${SRCS:.c=.o}

all:	$(NAME)
$(NAME): $(OBJS)
	@${MAKE} -C ./libft
	${CC} ${OBJS} ${LIBFT} ${CFLAGS} -o ${NAME}

clean:
	@${MAKE} -C./libft fclean
	${RM} $(OBJS) $(BBJS)

fclean: clean
	${RM} ${NAME}

re:	fclean all

.PHONY:	all clean fclean re
