/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstsize.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 15:50:15 by adeburea          #+#    #+#             */
/*   Updated: 2021/06/24 16:56:07 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

int	lstsize(t_lst *lst)
{
	t_lst	*copy;
	int		count;

	copy = lst;
	count = 0;
	while (copy)
	{
		copy = copy->next;
		count++;
	}
	return (count);
}
