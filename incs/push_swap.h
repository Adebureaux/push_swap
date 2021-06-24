/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 15:16:40 by adeburea          #+#    #+#             */
/*   Updated: 2021/06/24 12:33:37 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define EXIT 99
# define CHUNK_SIZE 12
# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_lst
{
	int				nbr;
	struct s_lst	*next;
	struct s_lst	*prev;
}				t_lst;

typedef struct	s_stack
{
	t_lst			*a;
	t_lst			*b;
	int				*sorted;
	char			direction[4];
	int				a_size;
	int				b_size;
	int				size;
}				t_stack;

void	lstadd_back(t_lst **alst, t_lst *new);
void	lstadd_front(t_lst **alst, t_lst *new);
void	lstdelone(t_lst *lst);
void	lstfree(t_stack *stack);
void	lstprint(t_stack stack);
t_lst	*lstlast(t_lst *lst);
t_lst	*lstnew(int data);
int		lstsize(t_lst *lst);
void	swap_a(t_stack *stack, int print);
void	swap_b(t_stack *stack, int print);
void	swap(t_stack *stack, int print);
void	push_a(t_stack *stack, int print);
void	push_b(t_stack *stack, int print);
void	rotate_a(t_stack *stack, int print);
void	rotate_b(t_stack *stack, int print);
void	rotate(t_stack *stack, int print);
void	reverse_rotate_a(t_stack *stack, int print);
void	reverse_rotate_b(t_stack *stack, int print);
void	reverse_rotate(t_stack *stack, int print);

int		is_in(t_stack *stack);
int		is_nbr(char *s);
int		is_stack_sorted(t_stack *stack, int exit);
int		is_lst_sorted(t_lst *lst);
int		is_lst_reverse_sorted(t_lst *lst);

void	quit(t_stack *stack, int status);
void	execute(char *buf, t_stack *stack, int print);
void	parse_arg(char **av, t_stack *stack);

void	put_in_tab(t_stack *stack, t_lst *lst, int size);
int		find_pos(t_lst *lst, int cmp);
void	choose_direction(t_stack *stack, t_lst *lst, int cmp);

void	solver(t_stack *stack);
void	solver_plus(t_stack *stack, int size);

#endif
