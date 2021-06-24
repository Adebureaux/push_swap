/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstadd_front.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 15:38:59 by adeburea          #+#    #+#             */
/*   Updated: 2021/06/23 16:06:17 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

void	lstadd_front(t_lst **alst, t_lst *new)
{
	new->next = (*alst);
	new->prev = NULL;
	if (*alst)
		(*alst)->prev = new;
	(*alst) = new;
}
