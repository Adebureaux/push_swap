/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 14:47:43 by adeburea          #+#    #+#             */
/*   Updated: 2021/06/24 18:21:05 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

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
	tab = (int *)malloc(sizeof(int) * size);
	while (lst)
	{
		tab[i++] = lst->nbr;
		lst = lst->next;
	}
	sorter(tab, size);
	stack->sorted = tab;
	stack->size = size;
	stack->a_size = size;
	stack->b_size = 0;
	if (size < 25)
		stack->chunk_size = 1;
	else
		stack->chunk_size = 18;
	if (size > 100)
		stack->chunk_size += size / 26;
}
