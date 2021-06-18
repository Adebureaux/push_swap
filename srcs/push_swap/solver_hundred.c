/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_hundred.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 03:16:09 by adeburea          #+#    #+#             */
/*   Updated: 2021/06/18 16:47:22 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

void	choose_direction(t_stack *stack, t_lst *lst, int cmp)
{
	int		pos;

	pos = find_pos(lst, cmp);
	if (lst == stack->a)
	{
		if (pos > stack->a_size / 2)
			ft_strcpy(stack->direction, "rra");
		else
			ft_strcpy(stack->direction, "ra");
	}
	else
	{
		if (pos > stack->b_size / 2)
			ft_strcpy(stack->direction, "rrb");
		else
			ft_strcpy(stack->direction, "rb");
	}
}

void	median_split(t_stack *stack, int size)
{
	while (stack->cur < (size / 2))
	{
		if (stack->a->nbr <= stack->median)
		{
			execute("pb", stack, 1);
			stack->a_size--;
			stack->b_size++;
			stack->cur++;
		}
		else
		{
			while (stack->a->nbr > stack->median)
				execute("rra", stack, 1);
		}
	}
}

void	solver_b(t_stack *stack)
{
	int		j;

	j = 0;
	while (!is_lst_reverse_sorted(stack->b))
	{
		if (stack->b->nbr == stack->sorted[stack->b_size - 1])
		{
			execute("pa", stack, 1);
			stack->a_size++;
			stack->b_size--;
			j++;
		}
		else
		{
			choose_direction(stack, stack->b, stack->sorted[stack->b_size - 1]);
			while (stack->b->nbr != stack->sorted[stack->b_size - 1])
				execute(stack->direction, stack, 1);
		}
	}
	while (j--)
	{
		execute("pb", stack, 1);
		stack->a_size--;
		stack->b_size++;
	}
}

void	solver_a(t_stack *stack)
{
	while (!is_lst_sorted(stack->a))
	{
		if (stack->a->nbr == stack->sorted[stack->cur])
		{
			execute("pb", stack, 1);
			stack->a_size--;
			stack->b_size++;
			stack->cur++;
		}
		else
		{
			choose_direction(stack, stack->a, stack->sorted[stack->cur]);
			while (stack->a->nbr != stack->sorted[stack->cur])
				execute(stack->direction, stack, 1);
		}
	}
	while (stack->b)
	{
		execute("pa", stack, 1);
		stack->a_size++;
		stack->b_size--;
	}
}

void	solver_hundred(t_stack *stack, int size)
{
	stack->cur = 0;
	stack->a_size = size;
	stack->b_size = 0;
	if (size % 2)
		size++;
	median_split(stack, size);
	solver_b(stack);
	solver_a(stack);
}
