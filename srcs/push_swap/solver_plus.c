/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_plus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 03:16:09 by adeburea          #+#    #+#             */
/*   Updated: 2021/06/17 14:52:47 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

void	median_split(t_stack *stack, int size)
{
	stack->cur = 0;
	if (size % 2)
		size++;
	while (stack->cur < (size / 2))
	{
		if (stack->a->nbr <= stack->median)
		{
			execute("pb", stack, 1);
			stack->cur++;
		}
		else
			execute("rra", stack, 1);
		// CHECK RA OR RRA
	}
}

void	solver_b(t_stack *stack, int size)
{
	int		i;
	int		j;

	(void)size;
	i = lstsize(stack->b) - 1;
	j = 0;
	while (!is_lst_reverse_sorted(stack->b))
	{
		if (stack->b->nbr == stack->sorted[i])
		{
			execute("pa", stack, 1);
			i--;
			j++;
		}
		else
			execute("rrb", stack, 1);
			// CHECK RB OR RRB
	}
	while (j--)
		execute("pb", stack, 1);
}

void	solver_a(t_stack *stack, int size)
{
	(void)size;
	while (!is_lst_sorted(stack->a))
	{
		if (stack->a->nbr == stack->sorted[stack->cur])
		{
			execute("pb", stack, 1);
			stack->cur++;
		}
		else
			execute("rra", stack, 1);
			// CHECK RA OR RRA
	}
	while (stack->b)
		execute("pa", stack, 1);
}

void	solver_plus(t_stack *stack, int size)
{
	median_split(stack, size);
	solver_b(stack, size);
	solver_a(stack, size);
}
