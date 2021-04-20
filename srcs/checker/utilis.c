/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 18:29:25 by adeburea          #+#    #+#             */
/*   Updated: 2021/04/21 01:12:36 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

int		isin(t_lst *lst)
{
	int		*tab;
	int		size;
	int		i;
	int		j;

	size = lstsize(lst);
	tab = (int*)malloc(sizeof(int) * size);
	i = 0;
	while (lst)
	{
		tab[i++] = lst->nbr;
		lst = lst->next;
	}
	i = -1;
	while (++i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] == tab[j++])
				return (0);
		}
	}
	free(tab);
	return (1);
}

int		issorted(t_stack *stack)
{
	t_lst	*cmp;

	if (stack->b)
		quit(stack, -1);
	cmp = stack->a->next;
	while (stack->a->next)
	{
		if (stack->a->nbr > cmp->nbr)
			quit(stack, -1);
		stack->a = stack->a->next;
		cmp = cmp->next;
	}
	quit(stack, EXIT_SUCCESS);
	return (0);
}

int		isnbr(char *s)
{
	int		i;

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

void	quit(t_stack *stack, int status)
{
	if (status == EXIT_FAILURE)
		ft_putstr_fd("Error\n", 2);
	else if (status == EXIT_SUCCESS)
		ft_putstr_fd("OK\n", 2);
	else if (status == -1)
		ft_putstr_fd("KO\n", 2);
	if (stack)
		lstfree(stack);
	exit(status);
}
