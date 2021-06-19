/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 14:47:43 by adeburea          #+#    #+#             */
/*   Updated: 2021/06/19 12:18:10 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

int	find_pos(t_lst *lst, int cmp)
{
	t_lst	*copy;
	int		count;

	count = 0;
	copy = lst;
	while (copy && copy->nbr != cmp)
	{
		copy = copy->next;
		count++;
	}
	if (!copy)
		return (-1);
	return (count);
}

void	swaper(int *p, int *q)
{
	int		t;

	t = *p;
	*p = *q;
	*q = t;
}

void	sorter(int *a, int n)
{
	int		i;
	int		j;

	i = -1;
	while (++i < n - 1)
	{
		j = -1;
		while (++j < n - i - 1)
		{
			if (a[j] > a[j + 1])
				swaper(&a[j], &a[j + 1]);
		}
	}
}

void	put_in_tab(t_stack *stack, t_lst *lst, int size)
{
	int		*tab;
	int		i;

	i = 0;
	tab = (int*)malloc(sizeof(int) * size);
	while (lst)
	{
		tab[i++] = lst->nbr;
		lst = lst->next;
	}
	sorter(tab, size);
	stack->median = tab[(size + 1) / 2 - 1];
	stack->sorted = tab;
}
