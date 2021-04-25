# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/21 02:09:23 by adeburea          #+#    #+#              #
#    Updated: 2021/04/26 00:11:54 by adeburea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
.PHONY: all clean fclean re

SOLVER_PATH		=	srcs/push_swap
CHECKER_PATH	=	srcs/checker
NAME			=	push_swap
CHECK			=	checker
OBJ				=	objs
LIB				=	libft
LIBFT			=	$(addprefix $(LIB)/, libft.a)

$(NAME):
	make -C $(SOLVER_PATH)
	make -C $(CHECKER_PATH)

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f $(CHECK)

re: fclean all
