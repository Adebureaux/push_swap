# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/14 14:21:20 by adeburea          #+#    #+#              #
#    Updated: 2021/06/19 12:11:10 by adeburea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
.PHONY: all clean fclean re

CC		=	gcc
NAME	=	../../checker
FLAGS	=	-Wall -Wextra -Werror
LIB		=	../../libft
INC		=	../../incs
OBJ		=	../../objs
LST		=	../lists
OP		=	../operations
UT		=	../utilis
LIBFT	=	$(addprefix $(LIB)/, libft.a)
INCS	=	$(addprefix $(INC)/, push_swap.h)
OBJS	=	$(addprefix $(OBJ)/, $(SRCS:.c=.o))
SRCS 	=	lstadd_back.c \
			lstadd_front.c \
			lstdelone.c \
			lstfree.c \
			lstprint.c \
			lstlast.c \
			lstnew.c \
			lstsize.c \
			swap.c \
			push.c \
			rotate.c \
			reverse_rotate.c \
			arg.c \
			is.c \
			tab.c \
			checker.c

$(NAME): $(LIBFT) $(OBJ) $(OBJS)
	$(CC) $(FLAGS) -I$(INC) -o $(NAME) $(OBJS) $(LIBFT)

$(OBJ):
	@mkdir -p $(OBJ)

$(LIBFT):
	@make -C $(LIB)

$(OBJ)/%.o: $(LST)/%.c
	$(CC) $(FLAGS) -I$(INC) -c $< -o $@

$(OBJ)/%.o: $(OP)/%.c
	$(CC) $(FLAGS) -I$(INC) -c $< -o $@

$(OBJ)/%.o: $(UT)/%.c
	$(CC) $(FLAGS) -I$(INC) -c $< -o $@

$(OBJ)/%.o: ./%.c
	$(CC) $(FLAGS) -I$(INC) -c $< -o $@

all: $(NAME)

clean:
	make clean -C $(LIB)
	rm -rf $(OBJ)

fclean: clean
	rm -f $(LIBFT)
	rm -f $(NAME)

re: fclean all
