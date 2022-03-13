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
 

CC		= gcc
NAME	= a.out
CFLAGS	= -Wall -Wextra -Werror -c
SRCS	= ft_printf.c ft_strlen.c ft_putchar_fd.c ft_putstr_fd.c main.c

OBJS	= ${SRCS:.c=.o}

all:	$(NAME)

$(NAME): $(OBJS)
	gcc ${OBJS} -o a.out
#	ar rcs ${NAME} ${OBJS}


so: fclean all
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS) $(BNSS)
	gcc -nostartfiles -shared -o libft.so $(OBJS) $(BBJS)

clean:
	rm -f $(OBJS) $(BBJS)

fclean: clean
	rm -f ${NAME}

re:	fclean all

.PHONY:	all clean fclean re
