/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 03:16:09 by adeburea          #+#    #+#             */
/*   Updated: 2021/04/26 15:50:52 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

int		find_pos(t_lst *lst, int cmp)
{
	t_lst	*copy;
	int		count;
	int		size;

	count = 0;
	size = lstsize(lst);
	copy = lst;
	while (copy && copy->nbr < cmp)
	{
		copy = copy->next;
		count++;
	}
	if (count == size)
		return (-1);
	return (count);
}

void	solve_two(t_lst *lst, t_stack *stack)
{
	if (lst->nbr > lst->next->nbr && lst == stack->a)
		execute("sa", stack, 1);
	else if (lst->nbr > lst->next->nbr && lst == stack->b)
		execute("sb", stack, 1);
}

void	solve_three(t_stack *stack)
{
	if (FIRST > MID && MID < LAST && FIRST < LAST)
		execute("sa", stack, 1);
	else if (FIRST > MID && MID > LAST && FIRST > LAST)
		execute("sa", stack, 1);
	else if (FIRST < MID && MID > LAST && FIRST < LAST)
		execute("sa", stack, 1);
	if (FIRST > MID && MID < LAST && FIRST > LAST)
		execute("ra", stack, 1);
	else if (FIRST < MID && MID > LAST && FIRST > LAST)
		execute("rra", stack, 1);
}

void	solve_more(t_stack *stack)
{
	int		pos;

	pos = find_pos(stack->a, stack->b->nbr);
	if (!pos || pos == -1)
	{
		execute("pa", stack, 1);
		if (pos == -1)
			execute("ra", stack, 1);
		return ;
	}
	while (FIRST < stack->b->nbr)
		execute("ra", stack, 1);
	execute("pa", stack, 1);
	while (!is_lst_sorted(stack->a))
		execute("ra", stack, 1);
}

void	solver(t_stack *stack)
{
	int		size;

	size = lstsize(stack->a);
	if (size < 2)
		quit(stack, EXIT);
	if (size == 2)
		solve_two(stack->a, stack);
	else if (size == 3)
		solve_three(stack);
	else
	{
		while (size-- > 3)
			execute("pb", stack, 1);
		solve_three(stack);
		if (lstsize(stack->b) == 2)
			solve_two(stack->b, stack);
		while (!is_stack_sorted(stack, 0))
			solve_more(stack);
	}
}
