/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstadd_front.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 15:38:59 by adeburea          #+#    #+#             */
/*   Updated: 2021/04/16 15:43:28 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

void	lstadd_front(t_lst **alst, t_lst *new)
{
	t_lst *tmp;

	tmp = (*alst);
	(*alst) = new;
	new->next = tmp;
}
