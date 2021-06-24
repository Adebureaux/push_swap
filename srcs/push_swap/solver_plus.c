/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_plus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 16:49:00 by adeburea          #+#    #+#             */
/*   Updated: 2021/06/24 18:19:08 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

int	scan_top(t_stack *stack, t_lst *lst, int chunk)
{
	int		i;
	int		j;

	i = 0;
	while (lst)
	{
		j = (stack->chunk_size * chunk) - stack->chunk_size - 1;
		while (++j < (stack->chunk_size * chunk) && j < stack->size)
		{
			if (lst->nbr == stack->sorted[j])
				return (i);
		}
		lst = lst->next;
		i++;
	}
	return (-1);
}

int	scan_bot(t_stack *stack, t_lst *lst, int chunk)
{
	t_lst	*last;
	int		i;
	int		j;

	i = 1;
	last = lstlast(lst);
	while (last != lst)
	{
		j = (stack->chunk_size * chunk) - stack->chunk_size - 1;
		while (++j < (stack->chunk_size * chunk) && j < stack->size)
		{
			if (last->nbr == stack->sorted[j])
				return (i);
		}
		last = last->prev;
		i++;
	}
	return (-1);
}

void	scan(t_stack *stack, int i)
{
	int	j;
	int	top;
	int	bot;

	top = scan_top(stack, stack->a, i);
	bot = scan_bot(stack, stack->a, i);
	j = -1;
	if (top <= bot)
	{
		while (++j < top)
			execute("ra", stack, 1);
		execute("pb", stack, 1);
	}
	else
	{
		while (++j < bot)
			execute("rra", stack, 1);
		execute("pb", stack, 1);
	}
}

void	solver_plus(t_stack *stack, int size)
{
	int		i;

	i = 1;
	while (stack->a)
	{
		while (stack->b_size < stack->chunk_size * i && stack->a)
			scan(stack, i);
		i++;
	}
	i = size - 1;
	while (stack->b)
	{
		choose_direction(stack, stack->b, stack->sorted[i]);
		while (stack->b->nbr != stack->sorted[i])
			execute(stack->direction, stack, 1);
		execute("pa", stack, 1);
		i--;
	}
}
