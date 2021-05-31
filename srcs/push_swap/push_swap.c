/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 02:09:13 by adeburea          #+#    #+#             */
/*   Updated: 2021/05/30 17:18:15 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

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
	solver(&stack);
}
