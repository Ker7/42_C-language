# ***************************************************************************** #
#                                                                               #
#                                                         :::      ::::::::     #
#    Makefile                                           :+:      :+:    :+:     #
#                                                     +:+ +:+         +:+       #
#    By: kmottus <kmottus@student.42wolfsburg.de    +#+  +:+       +#+          #
#                                                 +#+#+#+#+#+   +#+             #
#    Created: 2022/03/08 14:48:00 by kmottus           #+#    #+#               #
#    Updated: 2022/06/13 16:56:00 by kmottus          ###   ########.fr         #
#                                                                               #
# ***************************************************************************** #
 

### Declarations
NAME	= get_next_line.a
SRC_F	= get_next_line.c get_next_line_utils.c

CC		= gcc
LIBC	= ar rc
RM		= rm -fr
CFLAGS	= -Wall -Wextra -Werror

OBJS	= $(SRC_F:.c=.o)
OBJT	= $(./dev/, main:.c=.o)	
INC_L	= ./

### Actions
.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I$(INC_L)

$(NAME):	$(OBJS)
	$(LIBC) $(NAME) $(OBJS)

all:	$(NAME)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME) a.out

re:	fclean all

bonus:	fclean
	echo '>>> NO BONUS PART <<<'

.PHONY:	all clean fclean re
