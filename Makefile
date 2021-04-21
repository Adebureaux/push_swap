# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/21 02:09:23 by adeburea          #+#    #+#              #
#    Updated: 2021/04/21 03:09:43 by adeburea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
.PHONY: all clean fclean re

SOLVER_PATH		=	srcs/push_swap
CHECKER_PATH	=	srcs/checker
NAME			=	push_swap

$(NAME):
	make -C $(SOLVER_PATH)
	make -C $(CHECKER_PATH)

all: $(NAME)

clean:
	make clean -C $(CHECKER_PATH)

fclean:
	make fclean -C $(CHECKER_PATH)
	rm -f $(NAME)

re: fclean all
