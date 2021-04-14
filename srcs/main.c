/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 15:36:48 by adeburea          #+#    #+#             */
/*   Updated: 2021/04/14 16:11:26 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int		main(int ac, char **av)
{
	(void)ac;
	(void)av;
	t_list	*lst;
	t_data	nbr;

	nbr.a = 9;
	nbr.b = 55;
	lst = ft_lstnew(&nbr);
	printf("Hello World\n");
	printf("lst = %d\n", lst->nbr.a);
	return (0);
}
