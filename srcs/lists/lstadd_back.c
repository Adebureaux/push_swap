/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstadd_back.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 15:39:55 by adeburea          #+#    #+#             */
/*   Updated: 2021/06/23 16:05:18 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

void	lstadd_back(t_lst **alst, t_lst *new)
{
	t_lst *last = *alst;

	new->next = NULL;
	if (!*alst)
	{
		new->prev = NULL;
		*alst = new;
		return ;
	}
	while (last->next)
		last = last->next;
	last->next = new;
	new->prev = last;
}
