/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 03:16:09 by adeburea          #+#    #+#             */
/*   Updated: 2021/04/22 15:04:49 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

void	solve_three(t_stack *stack)
{
	int		*tab;
	int		size;

	size = lstsize(stack->a);
	tab = (int*)malloc(sizeof(int) * size);
	put_in_tab(tab, stack->a);
	if (tab[0] > tab[1] && tab[1] < tab[2] && tab[0] < tab[2])
		ft_putstr_fd("sa\n", 1);
	else if (tab[0] > tab[1] && tab[1] > tab[2] && tab[0] > tab[2])
		ft_putstr_fd("sa\n", 1);
	else if (tab[0] < tab[1] && tab[1] > tab[2] && tab[0] < tab[2])
		ft_putstr_fd("sa\n", 1);
	if (tab[0] > tab[1] && tab[1] < tab[2] && tab[0] > tab[2])
		ft_putstr_fd("ra\n", 1);
	else if (tab[0] < tab[1] && tab[1] > tab[2] && tab[0] > tab[2])
		ft_putstr_fd("rra\n", 1);
	free(tab);
}