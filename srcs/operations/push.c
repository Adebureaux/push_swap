/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 13:33:09 by adeburea          #+#    #+#             */
/*   Updated: 2021/04/20 13:34:50 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

void	push_a(t_stack *stack)
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
		ft_putstr_fd("pa\n", 1);
	}
}

void	push_b(t_stack *stack)
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
		ft_putstr_fd("pb\n", 1);
	}
}
