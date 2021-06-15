/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_plus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 03:16:09 by adeburea          #+#    #+#             */
/*   Updated: 2021/06/15 13:45:37 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

void	median_split(t_stack *stack, int size)
{
	int		i;
	int		median;

	i = 0;
	median = stack->median;
	if (size % 2)
		median--;
	while (i < (size / 2))
	{
		if (stack->a->nbr <= median)
		{
			execute("pb", stack, 1);
			i++;
		}
		else
			execute("ra", stack, 1);
		// CHECK RA OR RRA
	}
}

void	solver_b(t_stack *stack)
{
	int		i;
	int		j;

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
	// while (j--)
	// 	execute("pb", stack, 1);
}

void	solver_plus(t_stack *stack, int size)
{
	// int		i;
	// int		j;

	median_split(stack, size);
	//solver_b(stack);
	// i = lstsize(stack->a) + 1;
	// while (!is_lst_sorted(stack->a))
	// {
	// 	if (stack->a->nbr == stack->sorted[i])
	// 	{
	// 		execute("pb", stack, 1);
	// 		i++;
	// 	}
	// 	else
	// 		execute("ra", stack, 1);
	// }
	// while (stack->b)
	// 	execute("pa", stack, 1);
}
