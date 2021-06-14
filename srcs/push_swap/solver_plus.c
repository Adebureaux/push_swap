/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_plus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 03:16:09 by adeburea          #+#    #+#             */
/*   Updated: 2021/06/14 17:16:32 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

void	solver_plus(t_stack *stack, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i++ < size / 2)
	{
		if (stack->a->nbr <= stack->median)
			execute("pb", stack, 1);
		else
			execute("rra", stack, 1);
	}
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
	}
	while (j--)
		execute("pb", stack, 1);
	i = lstsize(stack->a) + 1;
	while (!is_lst_sorted(stack->a))
	{
		if (stack->a->nbr == stack->sorted[i])
		{
			execute("pb", stack, 1);
			i++;
		}
		else
			execute("rra", stack, 1);
	}
	while (stack->b)
		execute("pa", stack, 1);
}
