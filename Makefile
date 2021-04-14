# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/14 14:21:20 by adeburea          #+#    #+#              #
#    Updated: 2021/04/14 16:14:17 by adeburea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME	= push_swap
CHECK	= checker
CC		= gcc
FLAGS	= -Wall -Wextra -Werror
INC		= incs
OBJ		= objs
MAIN	= srcs/main.c
SRC_OP	= srcs/operations
LIBFT	= libft
INCS	= $(addprefix $(INC)/, push_swap.h)
OBJS	= $(addprefix $(OBJ)/, $(SRCS:.c=.o))
SRCS	= swap_a.c

all: $(NAME)

$(NAME): $(MAIN) $(OBJS) $(INCS)
	$(CC) $(FLAGS) -I.$(INC) -o $(NAME) $(MAIN) $(OBJS) $(LIBFT)/libft.a

$(OBJ)/%.o: $(SRC_OP)/%.c $(INCS)
	mkdir -p $(OBJ)
	make all -C $(LIBFT)
	$(CC) $(FLAGS) -I.$(INC) -c $< -o $@

clean:
	rm -f main.o
	rm -rf $(OBJ)

fclean: clean
	make -C $(LIBFT) fclean
	rm -f $(NAME)

re: fclean all
