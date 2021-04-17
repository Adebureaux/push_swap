# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/14 14:21:20 by adeburea          #+#    #+#              #
#    Updated: 2021/04/17 13:25:04 by adeburea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
.PHONY: all clean fclean re

CC		=	gcc
NAME	=	checker
FLAGS	=	-Wall -Wextra -Werror
LIB		=	../../libft
INC		=	../../incs
OBJ		=	../../objs
LST		=	../lists
OP		=	../operations
LIBFT	=	$(addprefix $(LIB)/, libft.a)
INCS	=	$(addprefix $(INC)/, push_swap.h)
OBJS	=	$(addprefix $(OBJ)/, $(SRCS:.c=.o))
SRCS 	=	lstadd_back.c \
			lstadd_front.c \
			lstdelone.c \
			lstprint.c \
			lstlast.c \
			lstnew.c \
			lstsize.c \
			swap_a.c \
			checker.c

all: $(OBJ) $(NAME)

$(OBJ):
	mkdir -p $(OBJ)

$(LIBFT):
	make -C $(LIB)

$(NAME): $(OBJS) $(OBJ) $(LIBFT)
	$(CC) $(FLAGS) -I$(INC) -o $(NAME) $(OBJS) $(LIBFT)

$(OBJ)/%.o: $(LST)/%.c
	$(CC) $(FLAGS) -I$(INC) -c $< -o $@

$(OBJ)/%.o: $(OP)/%.c
	$(CC) $(FLAGS) -I$(INC) -c $< -o $@

$(OBJ)/%.o: ./%.c
	$(CC) $(FLAGS) -I$(INC) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	make clean -C $(LIB)
	rm -f $(NAME)

re: fclean all
