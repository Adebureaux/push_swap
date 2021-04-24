/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 15:36:48 by adeburea          #+#    #+#             */
/*   Updated: 2021/04/24 18:38:10 by adeburea         ###   ########.fr       */
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
	if (!isnbr(av[1]))
		quit(&stack, EXIT_FAILURE);
	stack.a = lstnew(ft_atoi(av[1]));
	if (!parse_arg(av, &stack))
		quit(&stack, EXIT_FAILURE);
	read_stdin(&stack);
	issorted(&stack, 1);
}
