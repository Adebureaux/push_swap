/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 03:16:09 by adeburea          #+#    #+#             */
/*   Updated: 2021/06/01 16:04:56 by adeburea         ###   ########.fr       */
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
	while (stack->a->nbr < stack->b->nbr)
		execute("ra", stack, 1);
	execute("pa", stack, 1);
	while (!is_lst_sorted(stack->a))
		execute("ra", stack, 1);
}

void	quickswap(t_stack *stack, int a, int b)
{
	int		i;
	int		first;
	int		size;

	i = -1;
	size = lstsize(stack->a);
	first = stack->a->nbr;
	while (++i < a)
		execute("ra", stack, 1);
	execute("pb", stack, 1);
	while (++i < b)
		execute("ra", stack, 1);
	execute("pb", stack, 1);
	execute("sb", stack, 1);
	while (stack->a->nbr != first)
	{
		if (i - 1 == a)
			execute("pa", stack, 1);
		if (i == b)
			execute("pa", stack, 1);
		execute("rra", stack, 1);
		i--;
	}
}

void	quicksort(int *number, int first, int last)
{
	int i, j, pivot, temp;

	if (first < last)
	{
		pivot = first;
		i = first;
		j = last;
		while (i < j)
		{
			while (number[i] <= number[pivot] && i < last)
				i++;
			while (number[j] > number[pivot])
				j--;
			if (i < j)
			{
				printf("in loop : i = %d && j = %d\n", i, j);
				temp = number[i];
				number[i] = number[j];
				number[j] = temp;
			}
		}
		if (pivot != j)
		{
			printf("outloop : pivot = %d && j = %d\n", pivot, j);
			temp = number[pivot];
			number[pivot] = number[j];
			number[j] = temp;
		}
		quicksort(number, first, j - 1);
		quicksort(number, j + 1, last);
	}
}

void	solver(t_stack *stack)
{
	// // FIRST SOLUTION
	// int		size;
	//
	// size = lstsize(stack->a);
	// if (size < 2)
	// 	quit(stack, EXIT);
	// if (size == 2)
	// 	solve_two(stack->a, stack);
	// else if (size == 3)
	// 	solve_three(stack);
	// else
	// {
	// 	while (size-- > 3)
	// 		execute("pb", stack, 1);
	// 	solve_three(stack);
	// 	if (lstsize(stack->b) == 2)
	// 		solve_two(stack->b, stack);
	// 	while (!is_stack_sorted(stack, 0))
	// 		solve_more(stack);
	// }
	//lstprint(*stack);

	// TEMPORARY SOLUTION (QUICKSORT WITH INT ARRAY)
	// int size = lstsize(stack->a);
	// int *tab = put_in_tab(stack->a, size);
	// quicksort(tab, 0, size - 1);
	// int i = 0;
	// while (i < size)
	// 	printf("%d\n", tab[i++]);

	// // LAST CHANCE (QUICKSORT WITH LINKED LIST)
	lstprint(*stack);
	quickswap(stack, 1, 5);
	lstprint(*stack);
}
