/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analize_stack_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 18:49:40 by jormond-          #+#    #+#             */
/*   Updated: 2019/09/25 18:33:13 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		analize_stack_b(t_push **psb, t_ptrs **b, int turndown)
{
	t_push		*tmp;
	int			turn;
	int			i;

	i = 0;
	tmp = (*psb);
	turn = turndown;
	stack_len(psb, b);
	while (tmp)
	{
		if (tmp->turn == turn)
		{
			tmp->bnextdist = i;
			tmp->bprevdist = (*b)->biggest_ord - tmp->bnextdist;
		}
		tmp = tmp->next;
		i++;
	}
}

void		stack_len(t_push **ps, t_ptrs **p)
{
	t_push		*tmp;

	tmp = (*ps);
	(*p)->biggest_ord = 1;
	while ((*ps)->next)
	{
		(*ps) = (*ps)->next;
		(*p)->biggest_ord++;
	}
	(*ps) = tmp;
}
