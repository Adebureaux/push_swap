/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 03:16:09 by adeburea          #+#    #+#             */
/*   Updated: 2021/06/18 16:38:29 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

void	solve_two(t_stack *stack, t_lst *lst)
{
	if (lst->nbr > lst->next->nbr && lst == stack->a)
		execute("sa", stack, 1);
	else if (lst->nbr < lst->next->nbr && lst == stack->b)
		execute("sb", stack, 1);
}

void	solve_three(t_stack *stack)
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

void	solve_five(t_stack *stack, int size)
{
	int		i;

	i = 0;
	while (i < size - 3)
	{
		if (stack->a->nbr == stack->sorted[0]
			|| (stack->a->nbr == stack->sorted[1] && size == 5))
		{
			execute("pb", stack, 1);
			i++;
		}
		else
			execute("ra", stack, 1);
	}
	solve_three(stack);
	if (size == 5)
		solve_two(stack, stack->b);
	while (stack->b)
		execute("pa", stack, 1);
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
		solve_two(stack, stack->a);
	else if (size == 3)
		solve_three(stack);
	else if (size <= 5)
		solve_five(stack, size);
	else
		solver_hundred(stack, size);
}
