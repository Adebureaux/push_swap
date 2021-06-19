/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_thousand.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 16:49:00 by adeburea          #+#    #+#             */
/*   Updated: 2021/06/19 11:58:18 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

void	scan_top(t_stack *stack, int size)
{
	t_lst	*lst;
	int		i;
	int		pos;
	int		cur;

	lst = stack->a;
	i = -1;
	pos = size;
	while (++i < 10)
	{
		cur = find_pos(stack->a, stack->sorted[i]);
		printf("nbr = %d\n", stack->sorted[i]);
		printf("cur_pos = %d\n", cur);
		if (cur < pos)
			pos = cur;
	}
}

void	solver_thousand(t_stack *stack, int size)
{
	scan_top(stack, size);
}
