/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 15:36:48 by adeburea          #+#    #+#             */
/*   Updated: 2021/04/20 19:23:04 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

int		parse_arg(int ac, char **av, t_stack *stack)
{
	int		i;
	t_lst	*tmp;

	i = 2;
	if (ac < 2)
		return (0);
	if (!isnbr(av[1]))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	stack->a = lstnew(ft_atoi(av[1]));
	stack->b = NULL;
	while (av[i])
	{
		if (!isnbr(av[i]))
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		tmp = lstnew(ft_atoi(av[i]));
		lstadd_back(&stack->a, tmp);
		i++;
	}
	return (1);
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
			if (!execute(buf, stack))
				return (0);
			i = -1;
		}
		i++;
	}
	return (1);
}

int		main(int ac, char **av)
{
	t_stack	stack;

	if (!parse_arg(ac, av, &stack))
		return (-1);
	lstprint(stack);
	read_stdin(&stack);
	return (0);
}
