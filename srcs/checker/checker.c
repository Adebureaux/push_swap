/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 15:36:48 by adeburea          #+#    #+#             */
/*   Updated: 2021/04/16 17:47:03 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

int		main(void)
{
	t_lst	*lst;

	lst = lstnew(100);
	t_lst	*lst2;
	lst2 = lstnew(125);
	lstadd_front(&lst, lst2);
	printf("Hello World\n");
	printf("lst = %d\n", lst->nbr);
	printf("%d\n", lstsize(lst));
	lstprint(lst);
	return (0);
}
