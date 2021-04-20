/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 13:36:40 by adeburea          #+#    #+#             */
/*   Updated: 2021/04/20 17:16:31 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

void	rotate_a(t_stack *stack, int print)
{
	t_lst	*last;
	int		tmp;

	if (lstsize(stack->a))
	{
		last = stack->a;
		tmp = last->nbr;
		stack->a = stack->a->next;
		lstdelone(last);
		last = lstnew(tmp);
		lstadd_back(&stack->a, last);
		if (print)
			ft_putstr_fd("ra\n", 1);
	}
}

void	rotate_b(t_stack *stack, int print)
{
	t_lst	*last;
	int		tmp;

	if (lstsize(stack->b))
	{
		last = stack->b;
		tmp = last->nbr;
		stack->b = stack->b->next;
		lstdelone(last);
		last = lstnew(tmp);
		lstadd_back(&stack->b, last);
		if (print)
			ft_putstr_fd("rb\n", 1);
	}
}

void	rotate(t_stack *stack)
{
	rotate_a(stack, 0);
	rotate_b(stack, 0);
	if (stack->a && stack->b)
		ft_putstr_fd("rr\n", 1);
}
