/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 18:29:25 by adeburea          #+#    #+#             */
/*   Updated: 2021/04/20 19:41:48 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

int		execute(char *buf, t_stack *stack)
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
	lstprint(*stack);
	return (1);
}

int		isnbr(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-')
	{
		if (!s[1])
			return (0);
		i++;
	}
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}
