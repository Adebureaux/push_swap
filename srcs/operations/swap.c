/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 15:23:53 by adeburea          #+#    #+#             */
/*   Updated: 2021/04/25 18:27:03 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

void	swap_a(t_stack *stack, int print)
{
	t_lst	*first;
	int		tmp;

	if (lstsize(stack->a) > 1)
	{
		first = stack->a;
		stack->a = stack->a->next;
		tmp = stack->a->nbr;
		stack->a->nbr = first->nbr;
		lstdelone(first);
		first = lstnew(tmp);
		lstadd_front(&stack->a, first);
		if (print)
			ft_putstr_fd("sa\n", 1);
	}
}

void	swap_b(t_stack *stack, int print)
{
	t_lst	*first;
	int		tmp;

	if (lstsize(stack->b) > 1)
	{
		first = stack->b;
		stack->b = stack->b->next;
		tmp = stack->b->nbr;
		stack->b->nbr = first->nbr;
		lstdelone(first);
		first = lstnew(tmp);
		lstadd_front(&stack->b, first);
		if (print)
			ft_putstr_fd("sb\n", 1);
	}
}

void	swap(t_stack *stack, int print)
{
	swap_a(stack, 0);
	swap_b(stack, 0);
	if (print && stack->a && stack->b)
		ft_putstr_fd("ss\n", 1);
}
