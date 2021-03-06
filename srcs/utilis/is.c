/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 18:29:25 by adeburea          #+#    #+#             */
/*   Updated: 2021/06/24 18:36:42 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

int	is_in(t_stack *stack)
{
	int		size;
	int		i;
	int		j;

	i = -1;
	size = lstsize(stack->a);
	put_in_tab(stack, stack->a, size);
	while (++i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (stack->sorted[i] == stack->sorted[j++])
				return (0);
		}
	}
	return (1);
}

int	is_nbr(char *s)
{
	int		i;
	int		flag;

	i = 0;
	flag = 0;
	if (s[i] == '-')
	{
		if (!s[1])
			return (0);
		i++;
		flag = 1;
	}
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		else if (!flag && i >= 9 && (s[i - 1] > '4' || s[i] > '7'))
			return (0);
		else if (flag && i >= 10 && (s[i - 1] > '4' || s[i] > '8'))
			return (0);
		else if ((!flag && i >= 10) || (flag && i >= 11))
			return (0);
		i++;
	}
	return (1);
}

int	is_stack_sorted(t_stack *stack, int exit)
{
	t_lst	*cur;
	t_lst	*cmp;

	if (stack->b)
	{
		if (exit)
			quit(stack, -1);
		return (0);
	}
	cur = stack->a;
	cmp = stack->a->next;
	while (cur->next)
	{
		if (cur->nbr > cmp->nbr)
		{
			if (exit)
				quit(stack, -1);
			return (0);
		}
		cur = cur->next;
		cmp = cmp->next;
	}
	if (exit)
		quit(stack, EXIT_SUCCESS);
	return (1);
}

int	is_lst_sorted(t_lst *lst)
{
	t_lst	*cur;
	t_lst	*cmp;

	cur = lst;
	cmp = lst->next;
	while (cur->next)
	{
		if (cur->nbr > cmp->nbr)
			return (0);
		cur = cur->next;
		cmp = cmp->next;
	}
	return (1);
}

int	is_lst_reverse_sorted(t_lst *lst)
{
	t_lst	*cur;
	t_lst	*cmp;

	cur = lst;
	cmp = lst->next;
	while (cur->next)
	{
		if (cur->nbr < cmp->nbr)
			return (0);
		cur = cur->next;
		cmp = cmp->next;
	}
	return (1);
}
