/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 18:29:25 by adeburea          #+#    #+#             */
/*   Updated: 2021/04/21 02:48:17 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

void	put_in_tab(int *tab, t_lst *lst)
{
	int		i;

	i = 0;
	while (lst)
	{
		tab[i++] = lst->nbr;
		lst = lst->next;
	}
}

int		isin(t_lst *lst)
{
	int		*tab;
	int		size;
	int		i;
	int		j;

	size = lstsize(lst);
	tab = (int*)malloc(sizeof(int) * size);
	put_in_tab(tab, lst);
	i = -1;
	while (++i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] == tab[j++])
			{
				free(tab);
				return (0);
			}
		}
	}
	free(tab);
	return (1);
}

void	issorted(t_stack *stack)
{
	t_lst	*cur;
	t_lst	*cmp;

	if (stack->b)
		quit(stack, -1);
	cur = stack->a;
	cmp = stack->a->next;
	while (cur->next)
	{
		if (cur->nbr > cmp->nbr)
			quit(stack, -1);
		cur = cur->next;
		cmp = cmp->next;
	}
	quit(stack, EXIT_SUCCESS);
}

int		isnbr(char *s)
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
