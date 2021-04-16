/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstadd_back.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 15:39:55 by adeburea          #+#    #+#             */
/*   Updated: 2021/04/16 15:43:35 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

void	lstadd_back(t_lst **alst, t_lst *new)
{
	t_lst *last;

	if ((*alst))
	{
		last = lstlast((*alst));
		last->next = new;
		new->next = NULL;
	}
	else
		(*alst) = new;
}
