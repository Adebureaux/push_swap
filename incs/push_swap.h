/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 15:16:40 by adeburea          #+#    #+#             */
/*   Updated: 2021/04/16 17:45:01 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_lst
{
	int				nbr;
	struct s_lst	*next;
}				t_lst;

typedef struct	s_stack
{
	t_lst			*a;
	t_lst			*b;
}				t_stack;

void	lstadd_back(t_lst **alst, t_lst *new);
void	lstadd_front(t_lst **alst, t_lst *new);
void	lstdelone(t_lst *lst);
void	lstprint(t_lst *lst);
t_lst	*lstlast(t_lst *lst);
t_lst	*lstnew(int data);
int		lstsize(t_lst *lst);

#endif
