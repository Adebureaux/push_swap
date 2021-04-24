/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 03:16:09 by adeburea          #+#    #+#             */
/*   Updated: 2021/04/24 18:35:54 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

// void	solve_two(t_stack *stack)
// {
// 	if (stack->a->nbr >)
// }

void	solve_three(t_stack *stack)
{
	t_lst	*f;
	t_lst	*m;
	t_lst	*l;

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

void	solver(t_stack *stack)
{
	solve_three(stack);
	quit(stack, EXIT_SUCCESS);
}
