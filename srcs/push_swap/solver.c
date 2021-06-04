/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 03:16:09 by adeburea          #+#    #+#             */
/*   Updated: 2021/06/04 17:04:24 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

void	solve_two(t_lst *lst, t_stack *stack)
{
	if (lst->nbr > lst->next->nbr && lst == stack->a)
		execute("sa", stack, 1);
	else if (lst->nbr < lst->next->nbr && lst == stack->b)
		execute("sb", stack, 1);
}

void	solve_three_a(t_stack *stack)
{
	if (stack->a->nbr > stack->a->next->nbr
		&& stack->a->next->nbr < stack->a->next->next->nbr
		&& stack->a->nbr < stack->a->next->next->nbr)
		execute("sa", stack, 1);
	else if (stack->a->nbr > stack->a->next->nbr
		&& stack->a->next->nbr > stack->a->next->next->nbr
		&& stack->a->nbr > stack->a->next->next->nbr)
		execute("sa", stack, 1);
	else if (stack->a->nbr < stack->a->next->nbr
		&& stack->a->next->nbr > stack->a->next->next->nbr
		&& stack->a->nbr < stack->a->next->next->nbr)
		execute("sa", stack, 1);
	if (stack->a->nbr > stack->a->next->nbr
		&& stack->a->next->nbr < stack->a->next->next->nbr
		&& stack->a->nbr > stack->a->next->next->nbr)
		execute("ra", stack, 1);
	else if (stack->a->nbr < stack->a->next->nbr
		&& stack->a->next->nbr > stack->a->next->next->nbr
		&& stack->a->nbr > stack->a->next->next->nbr)
		execute("rra", stack, 1);
}

void	solve_three_b(t_stack *stack)
{
	if (stack->b->nbr < stack->b->next->nbr
		&& stack->b->next->nbr < stack->b->next->next->nbr
		&& stack->b->nbr < stack->b->next->next->nbr)
		execute("sb", stack, 1);
	else if (stack->b->nbr < stack->b->next->nbr
		&& stack->b->next->nbr < stack->b->next->next->nbr
		&& stack->b->nbr < stack->b->next->next->nbr)
		execute("sb", stack, 1);
	else if (stack->b->nbr < stack->b->next->nbr
		&& stack->b->next->nbr < stack->b->next->next->nbr
		&& stack->b->nbr < stack->b->next->next->nbr)
		execute("sb", stack, 1);
	if (stack->b->nbr < stack->b->next->nbr
		&& stack->b->next->nbr < stack->b->next->next->nbr
		&& stack->b->nbr < stack->b->next->next->nbr)
		execute("rb", stack, 1);
	else if (stack->b->nbr < stack->b->next->nbr
		&& stack->b->next->nbr < stack->b->next->next->nbr
		&& stack->b->nbr < stack->b->next->next->nbr)
		execute("rrb", stack, 1);
}

void	solve_six(t_stack *stack, int size)
{
	int		i;

	find_median(stack, size);
	i = -1;
	while (++i < size)
	{
		if (stack->a->nbr >= stack->median)
			execute("pb", stack, 1);
	}
	if (lstsize(stack->a) == 2)
		solve_two(stack->a, stack);
	if (lstsize(stack->b) == 2)
		solve_two(stack->b, stack);
	if (lstsize(stack->a) == 3)
		solve_three_a(stack);
	if (lstsize(stack->b) == 3)
		solve_three_b(stack);
	i = -1;
	while (++i < size / 2)
		execute("pa", stack, 1);
	// while (!is_lst_sorted(stack->a))
	// 	execute("rra", stack, 1);
}

void	solver(t_stack *stack)
{
	int		size;

	if (is_lst_sorted(stack->a))
		return ;
	size = lstsize(stack->a);
	if (size < 2)
		quit(stack, EXIT);
	if (size == 2)
		solve_two(stack->a, stack);
	else if (size == 3)
		solve_three_a(stack);
	else if (size <= 10)
		solve_six(stack, size);
}
