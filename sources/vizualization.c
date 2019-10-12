/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vizualization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 19:17:33 by jormond-          #+#    #+#             */
/*   Updated: 2019/09/25 21:40:49 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		vizualization(t_push *psa, t_push **psb)
{
	t_push		*a;
	t_push		*b;

	a = psa;
	b = (*psb);
	usleep(100000);
	system("clear");
	cyan();
	write(1, "\n A \t B \n", 9);
	reset();
	while (a || b)
	{
		if (a || !b)
			only_a(&a);
		else if (!a && b && b->order != 0)
			only_b(&b);
		else if (b->order == 0)
			break ;
	}
}

void		only_a(t_push **a)
{
	green();
	write(1, "[", 1);
	reset();
	ft_putnbr((*a)->order);
	green();
	write(1, "]\t", 2);
	red();
	write(1, "[ ]\n", 4);
	reset();
	(*a) = (*a)->next;
}

void		only_b(t_push **b)
{
	red();
	write(1, "[ ]\t", 4);
	green();
	write(1, "[", 1);
	reset();
	ft_putnbr((*b)->order);
	green();
	write(1, "]\n", 2);
	reset();
	(*b) = (*b)->next;
}

void		end_of_vizualization(int order)
{
	write(1, "num of orders: ", 15);
	cyan();
	ft_putnbr(order);
	write(1, "\n", 1);
}
