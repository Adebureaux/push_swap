/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 03:16:09 by adeburea          #+#    #+#             */
/*   Updated: 2021/04/25 00:56:16 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

void	solve_two(t_stack *stack)
{
	if (stack->a->nbr > stack->a->next->nbr)
		execute("sa", stack, 1);
}

void	solve_three(t_stack *stack, int size)
{
	t_lst	*f;
	t_lst	*m;
	t_lst	*l;

	if (size < 2 || size > 3)
		return ;
	else if (size == 2)
		solve_two(stack);
	else
	{
		f = stack->a;
		m = stack->a->next;
		l = stack->a->next->next;
		if (f->nbr > m->nbr && m->nbr < l->nbr && f->nbr < l->nbr)
			execute("sa", stack, 1);
		else if (f->nbr > m->nbr && m->nbr > l->nbr && f->nbr > l->nbr)
			execute("sa", stack, 1);
		else if (f->nbr < m->nbr && m->nbr > l->nbr && f->nbr < l->nbr)
			execute("sa", stack, 1);
		if (f->nbr > m->nbr && m->nbr < l->nbr && f->nbr > l->nbr)
			execute("ra", stack, 1);
		else if (f->nbr < m->nbr && m->nbr > l->nbr && f->nbr > l->nbr)
			execute("rra", stack, 1);
	}
}

void	solve_three(t_stack *stack, int size)
{
	
}

void	solver(t_stack *stack)
{
	int		size;

	size = lstsize(stack->a);
	if (size == 2 || size == 3)
		solve_three(stack, size);
	else if (size < 5)
		solve_five(stack, size);
	quit(stack, EXIT);
}
