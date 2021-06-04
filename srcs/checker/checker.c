/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 15:36:48 by adeburea          #+#    #+#             */
/*   Updated: 2021/06/03 18:52:38 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

int		read_stdin(t_stack *stack)
{
	int		i;
	int		rd;
	char	buf[100];

	i = 0;
	rd = 1;
	ft_bzero(buf, 100);
	while (rd == 1)
	{
		rd = read(0, &buf[i], 1);
		if (buf[i] == '\n')
		{
			buf[i] = '\0';
			execute(buf, stack, 0);
			ft_bzero(buf, 100);
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
	if (!is_nbr(av[1]))
		quit(&stack, EXIT_FAILURE);
	stack.a = lstnew(ft_atoi(av[1]));
	parse_arg(av, &stack);
	read_stdin(&stack);
	is_stack_sorted(&stack, 1);
}
