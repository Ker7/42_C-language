# ***************************************************************************** #
#                                                                               #
#                                                         :::      ::::::::     #
#    Makefile                                           :+:      :+:    :+:     #
#                                                     +:+ +:+         +:+       #
#    By: kmottus <kmottus@student.42wolfsburg.de    +#+  +:+       +#+          #
#                                                 +#+#+#+#+#+   +#+             #
#    Created: 2021/05/27 21:30:00 by kmottus           #+#    #+#               #
#    Updated: 2021/12/02 10:55:00 by kmottus          ###   ########.fr         #
#                                                                               #
# ***************************************************************************** #
 

CC		= gcc
NAME	= libft.a
CFLAGS	= -Wall -Wextra -Werror -c
SRCS	=	ft_strlen.c ft_strlcpy.c ft_isalpha.c ft_isdigit.c ft_isalnum.c \
			ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_bzero.c \
			ft_calloc.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
			ft_strnstr.c ft_memset.c ft_memcpy.c ft_atoi.c ft_strdup.c \
			ft_strncmp.c ft_strchr.c ft_strrchr.c ft_memmove.c ft_putnbr_fd.c \
			ft_memchr.c ft_memcmp.c ft_strlcat.c ft_strjoin.c ft_substr.c \
			ft_strtrim.c ft_split.c	ft_itoa.c ft_strmapi.c ft_striteri.c \

BNSS	=	ft_lstnew.c ft_lstsize.c ft_lstlast.c ft_lstiter.c ft_lstclear.c \
			ft_lstadd_front.c ft_lstadd_back.c ft_lstdelone.c \

OBJS	= ${SRCS:.c=.o}

BBJS	= ${BNSS:.c=.o}

all:	$(NAME)

$(NAME): $(OBJS)
	ar rcs ${NAME} ${OBJS}

bonus: $(BBJS)
	ar rc $(NAME) $(BBJS)

so: fclean all
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS) $(BNSS)
	gcc -nostartfiles -shared -o libft.so $(OBJS) $(BBJS)

clean:
	rm -f $(OBJS) $(BBJS)

fclean: clean
	rm -f ${NAME}

re:	fclean all

.PHONY:	all clean fclean re
