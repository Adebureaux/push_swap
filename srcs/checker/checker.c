/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 15:36:48 by adeburea          #+#    #+#             */
/*   Updated: 2021/04/20 18:18:34 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

int		main(void)
{
	t_lst	*a;
	t_lst	*b;
	t_lst	*tmp;
	t_stack	stack;

	a = lstnew(1);
	b = lstnew(0);
	tmp = lstnew(2);
	lstadd_front(&a, tmp);
	tmp = lstnew(1);
	lstadd_front(&a, tmp);
	tmp = lstnew(8);
	lstadd_front(&a, tmp);
	tmp = lstnew(9);
	lstadd_front(&a, tmp);
	tmp = lstnew(6);
	lstadd_front(&a, tmp);
	tmp = lstnew(4);
	lstadd_front(&b, tmp);
	stack.a = a;
	stack.b = b;
	lstprint(stack);
	swap(&stack);
	lstprint(stack);
	push_b(&stack);
	lstprint(stack);
	rotate(&stack);
	lstprint(stack);
	reverse_rotate(&stack);
	lstprint(stack);
	return (0);
}
