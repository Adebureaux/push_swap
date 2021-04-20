/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstprint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 15:53:02 by adeburea          #+#    #+#             */
/*   Updated: 2021/04/20 19:38:20 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

void	lstprint(t_stack stack)
{
	int	len;

	ft_putstr_fd("     Stack A           Stack B     \n\n", 1);
	while (stack.a || stack.b)
	{
		len = 1;
		if (stack.a)
		{
			len = ft_nbrlen_base(stack.a->nbr, 10);
			while (len++ < 9)
				ft_putchar_fd(' ', 1);
			ft_putnbr_fd(stack.a->nbr, 1);
			stack.a = stack.a->next;
		}
		while (len++ < 18)
			ft_putchar_fd(' ', 1);
		ft_putstr_fd("|       ", 1);
		if (stack.b)
		{
			ft_putnbr_fd(stack.b->nbr, 1);
			stack.b = stack.b->next;
		}
		ft_putchar_fd('\n', 1);
	}
	ft_putchar_fd('\n', 1);
}
