/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstfree.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 19:57:10 by adeburea          #+#    #+#             */
/*   Updated: 2021/04/21 01:45:31 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

void	lstfree(t_stack *stack)
{
	t_lst	*tmp;

	while (stack->a)
	{
		tmp = stack->a;
		stack->a = stack->a->next;
		lstdelone(tmp);
	}
	while (stack->b)
	{
		tmp = stack->b;
		stack->b = stack->b->next;
		lstdelone(tmp);
	}
}
