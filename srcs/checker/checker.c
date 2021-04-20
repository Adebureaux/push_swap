/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 15:36:48 by adeburea          #+#    #+#             */
/*   Updated: 2021/04/21 01:14:16 by adeburea         ###   ########.fr       */
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

void	execute(char *buf, t_stack *stack)
{
	if (!ft_strcmp(buf, "sa"))
		swap_a(stack, 0);
	else if (!ft_strcmp(buf, "sb"))
		swap_b(stack, 0);
	else if (!ft_strcmp(buf, "ss"))
		swap(stack, 0);
	else if (!ft_strcmp(buf, "pa"))
		push_a(stack, 0);
	else if (!ft_strcmp(buf, "pb"))
		push_b(stack, 0);
	else if (!ft_strcmp(buf, "ra"))
		rotate_a(stack, 0);
	else if (!ft_strcmp(buf, "rb"))
		rotate_b(stack, 0);
	else if (!ft_strcmp(buf, "rr"))
		rotate(stack, 0);
	else if (!ft_strcmp(buf, "rra"))
		reverse_rotate_a(stack, 0);
	else if (!ft_strcmp(buf, "rrb"))
		reverse_rotate_b(stack, 0);
	else if (!ft_strcmp(buf, "rrr"))
		reverse_rotate(stack, 0);
	else
		quit(stack, EXIT_FAILURE);
	lstprint(*stack);
}

int		read_stdin(t_stack *stack)
{
	int		i;
	int		rd;
	char	buf[100];

	i = 0;
	rd = 1;
	while (rd == 1 && i < 100)
	{
		rd = read(1, &buf[i], 1);
		if (buf[i] == '\n')
		{
			buf[i] = '\0';
			execute(buf, stack);
			i = -1;
		}
		i++;
	}
	return (1);
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
	lstprint(stack);
	read_stdin(&stack);
	issorted(&stack);
}
