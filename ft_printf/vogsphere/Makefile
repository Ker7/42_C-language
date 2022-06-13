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
NAME	= libftprintf.a
LIBFT	= libft.a
LIBFTFN	= libft
SRC_F	= ft_printf.c ft_prf_conv_cspdi.c ft_prf_conv_uxxc.c ft_utils.c

CC		= gcc
LIBC	= ar rc
RM		= rm -fr
CFLAGS	= -Wall -Wextra -Werror
SRC_L	= src
INC_L	= inc
OBJ_L	= obj

OBJS	= $(addprefix $(SRC_L)/,$(SRC_F:.c=.o))
OBJT	= $(./dev/, main:.c=.o)	

### Actions
.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I$(INC_L)

$(NAME):	$(OBJS)
	@$(MAKE) -C $(LIBFTFN)/
	@cp $(LIBFTFN)/$(LIBFT) ./$(NAME)
	$(LIBC) $(NAME) $(OBJS)

all:	$(NAME)

clean:
	@rm -f $(OBJS)
	@rm -rf $(OBJ_L)
	@make clean -C $(LIBFTFN)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C ./$(LIBFTFN)/

re:	fclean all

bonus:	fclean
	echo '>>> NO BONUS PART <<<'

.PHONY:	all clean fclean re
