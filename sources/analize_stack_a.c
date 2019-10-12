/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analize_stack_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 18:49:37 by jormond-          #+#    #+#             */
/*   Updated: 2019/09/25 18:33:10 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		analize_stack_a(t_push **psa, t_ptrs **a, t_push **psb)
{
	t_push		*tmpb;
	t_push		*tmpa;
	int			turn;

	turn = (*psb)->turn;
	tmpb = (*psb);
	tmpa = (*psa);
	stack_len(psa, a);
	init_sec_and_last(psa, a);
	while (tmpb)
	{
		tmpb->anextdist = 0;
		tmpb->aprevdist = 0;
		if (tmpb->turn == turn)
			analize_stack_a1(psa, a, &tmpb, tmpa);
		tmpb = tmpb->next;
	}
}

void		analize_stack_a1(t_push **psa, t_ptrs **a,
				t_push **tmpb, t_push *tmpa)
{
	while (!((*a)->last->order < (*tmpb)->order && ATOP > (*tmpb)->order))
	{
		order_ra_rb(psa);
		init_sec_and_last(psa, a);
		(*tmpb)->anextdist++;
	}
	if ((*a)->last->order < (*tmpb)->order && ATOP > (*tmpb)->order)
	{
		(*tmpb)->aprevdist = (*a)->biggest_ord - (*tmpb)->anextdist;
		while (tmpa != (*psa))
			order_rra_rrb(psa);
		init_sec_and_last(psa, a);
	}
}

void		sort_three_elem2(t_push **psa, t_ptrs *a, t_push *smallest)
{
	init_sec_and_last(psa, &a);
	if (ATOP > ASEC && ASEC > ALAST)
		write_order_sa(psa);
	else if (ATOP < ASEC && ASEC > ALAST && ATOP < ALAST)
		write_order_sa(psa);
	else if (ATOP > ASEC && ATOP < ALAST)
		write_order_sa(psa);
	while (ATOP != smallest->order)
	{
		init_sec_and_last(psa, &a);
		write_order_rra(psa);
	}
}
