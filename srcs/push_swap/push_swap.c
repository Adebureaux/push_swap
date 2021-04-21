/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 02:09:13 by adeburea          #+#    #+#             */
/*   Updated: 2021/04/21 03:54:39 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

int		parse_arg(char **av, t_stack *stack)
{
	int		i;
	t_lst	*tmp;

	i = 2;
	while (av[i])
	{
		if (!isnbr(av[i]))
			quit(stack, EXIT_FAILURE);
		tmp = lstnew(ft_atoi(av[i]));
		lstadd_back(&stack->a, tmp);
		i++;
	}
	if (!isin(stack->a))
		return (0);
	return (1);
}

void	solver(t_stack *stack)
{

	solve_three(stack);
}

int		main(int ac, char **av)
{
	t_stack	stack;

	stack.a = NULL;
	stack.b = NULL;
	if (ac < 2)
		return (0);
	if (!isnbr(av[1]))
		quit(&stack, EXIT_FAILURE);
	stack.a = lstnew(ft_atoi(av[1]));
	if (!parse_arg(av, &stack))
		quit(&stack, EXIT_FAILURE);
	solver(&stack);
}
