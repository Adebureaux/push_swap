/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 13:33:09 by adeburea          #+#    #+#             */
/*   Updated: 2021/06/24 12:33:35 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

void	push_a(t_stack *stack, int print)
{
	t_lst	*first;
	int		tmp;

	if (lstsize(stack->b))
	{
		first = stack->b;
		tmp = first->nbr;
		stack->b = stack->b->next;
		lstdelone(first);
		first = lstnew(tmp);
		lstadd_front(&stack->a, first);
		if (print)
			ft_putstr_fd("pa\n", 1);
	}
	stack->a_size++;
	stack->b_size--;
}

void	push_b(t_stack *stack, int print)
{
	t_lst	*first;
	int		tmp;

	if (lstsize(stack->a))
	{
		first = stack->a;
		tmp = first->nbr;
		stack->a = stack->a->next;
		lstdelone(first);
		first = lstnew(tmp);
		lstadd_front(&stack->b, first);
		if (print)
			ft_putstr_fd("pb\n", 1);
	}
	stack->a_size--;
	stack->b_size++;
}
