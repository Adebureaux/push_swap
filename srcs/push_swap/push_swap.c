/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 02:09:13 by adeburea          #+#    #+#             */
/*   Updated: 2021/06/24 18:41:11 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

int	find_pos(t_lst *lst, int cmp)
{
	t_lst	*copy;
	int		count;

	count = 0;
	copy = lst;
	while (copy && copy->nbr != cmp)
	{
		copy = copy->next;
		count++;
	}
	if (!copy)
		return (-1);
	return (count);
}

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

int	main(int ac, char **av)
{
	t_stack	stack;

	stack.a = NULL;
	stack.b = NULL;
	if (ac < 2)
		return (0);
	if (!is_nbr(av[1]))
		quit(&stack, EXIT_FAILURE);
	stack.a = lstnew(ft_atoi(av[1]));
	parse_arg(av, &stack);
	solver(&stack);
	free(stack.sorted);
	lstfree(&stack);
	return (0);
}
