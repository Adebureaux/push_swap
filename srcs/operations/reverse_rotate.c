/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 17:17:51 by adeburea          #+#    #+#             */
/*   Updated: 2021/04/20 19:14:16 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

void	reverse_rotate_a(t_stack *stack, int print)
{
	t_lst	*before_last;
	t_lst	*last;
	int		tmp;

	tmp = lstsize(stack->a);
	if (tmp)
	{
		before_last = stack->a;
		while (tmp-- > 2)
			before_last = before_last->next;
		last = before_last->next;
		before_last->next = NULL;
		tmp = last->nbr;
		lstdelone(last);
		last = lstnew(tmp);
		lstadd_front(&stack->a, last);
		if (print)
			ft_putstr_fd("rra\n", 1);
	}
}

void	reverse_rotate_b(t_stack *stack, int print)
{
	t_lst	*before_last;
	t_lst	*last;
	int		tmp;

	tmp = lstsize(stack->b);
	if (tmp)
	{
		before_last = stack->b;
		while (tmp-- > 2)
			before_last = before_last->next;
		last = before_last->next;
		before_last->next = NULL;
		tmp = last->nbr;
		lstdelone(last);
		last = lstnew(tmp);
		lstadd_front(&stack->b, last);
		if (print)
			ft_putstr_fd("rrb\n", 1);
	}
}

void	reverse_rotate(t_stack *stack, int print)
{
	reverse_rotate_a(stack, 0);
	reverse_rotate_b(stack, 0);
	if (print && stack->a && stack->b)
		ft_putstr_fd("rrr\n", 1);
}
