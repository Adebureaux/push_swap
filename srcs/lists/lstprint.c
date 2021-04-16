/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstprint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 15:53:02 by adeburea          #+#    #+#             */
/*   Updated: 2021/04/16 17:48:25 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

void	lstprint(t_lst *lst)
{
	while (lst)
	{
		ft_putnbr_fd(lst->nbr, 1);
		ft_putchar_fd('\n', 1);
		lst = lst->next;
	}
}
