/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstnew.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 15:47:06 by adeburea          #+#    #+#             */
/*   Updated: 2021/04/16 15:47:38 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

t_lst	*lstnew(int data)
{
	t_lst *lst;

	if (!(lst = malloc(sizeof(t_lst))))
		return (NULL);
	lst->nbr = data;
	lst->next = NULL;
	return (lst);
}
