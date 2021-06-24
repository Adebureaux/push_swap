/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 18:30:41 by adeburea          #+#    #+#             */
/*   Updated: 2021/06/24 12:06:13 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

void	parse_arg(char **av, t_stack *stack)
{
	int		i;
	t_lst	*tmp;

	i = 2;
	while (av[i])
	{
		if (!is_nbr(av[i]))
			quit(stack, EXIT_FAILURE);
		tmp = lstnew(ft_atoi(av[i]));
		lstadd_back(&stack->a, tmp);
		i++;
	}
	if (!is_in(stack))
		quit(stack, EXIT_FAILURE);
}

void	execute(char *buf, t_stack *stack, int print)
{
	if (!ft_strcmp(buf, "sa"))
		swap_a(stack, print);
	else if (!ft_strcmp(buf, "sb"))
		swap_b(stack, print);
	else if (!ft_strcmp(buf, "ss"))
		swap(stack, print);
	else if (!ft_strcmp(buf, "pa"))
		push_a(stack, print);
	else if (!ft_strcmp(buf, "pb"))
		push_b(stack, print);
	else if (!ft_strcmp(buf, "ra"))
		rotate_a(stack, print);
	else if (!ft_strcmp(buf, "rb"))
		rotate_b(stack, print);
	else if (!ft_strcmp(buf, "rr"))
		rotate(stack, print);
	else if (!ft_strcmp(buf, "rra"))
		reverse_rotate_a(stack, print);
	else if (!ft_strcmp(buf, "rrb"))
		reverse_rotate_b(stack, print);
	else if (!ft_strcmp(buf, "rrr"))
		reverse_rotate(stack, print);
	else if (print)
		quit(stack, EXIT_FAILURE);
	//lstprint(*stack);
}

void	quit(t_stack *stack, int status)
{
	if (status == EXIT_FAILURE)
		ft_putstr_fd("Error\n", 1);
	else if (status == EXIT_SUCCESS)
		ft_putstr_fd("OK\n", 1);
	else if (status == -1)
		ft_putstr_fd("KO\n", 1);
	if (stack)
		lstfree(stack);
	exit(status);
}
