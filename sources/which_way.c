/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   which_way.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 12:01:41 by jormond-          #+#    #+#             */
/*   Updated: 2019/09/24 21:12:17 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		which_way(t_push **psa, t_ptrs **a, t_push **psb, t_ptrs **b)
{
	t_push		*tmp;

	tmp = (*psb);
	while (tmp)
	{
		if (APREVDIST < ANEXTDIST && BPREVDIST < BNEXTDIST)
			tmp->result = (APREVDIST < BPREVDIST ? APREVDIST : BPREVDIST);
		else if (APREVDIST >= ANEXTDIST && BPREVDIST >= BNEXTDIST)
			(*psb)->result = (ANEXTDIST < BNEXTDIST ? ANEXTDIST : BNEXTDIST);
		else if (APREVDIST < ANEXTDIST && BPREVDIST >= BNEXTDIST)
			(*psb)->result = APREVDIST + BNEXTDIST;
		else if (APREVDIST >= ANEXTDIST && BPREVDIST < BNEXTDIST)
			(*psb)->result = ANEXTDIST + BPREVDIST;
		tmp = tmp->next;
	}
	the_best_result(psa, a, psb, b);
}

void		the_best_result(t_push **psa, t_ptrs **a, t_push **psb, t_ptrs **b)
{
	t_push	*tmp;
	t_push	*best;
	int		turn;

	tmp = (*psb);
	best = tmp;
	turn = tmp->turn;
	while (tmp)
	{
		if (tmp->turn == turn)
			if (best->result > tmp->result)
				best = tmp;
		tmp = tmp->next;
	}
	distributor(&best, psa, psb);
}

void		distributor(t_push **best, t_push **psa, t_push **psb)
{
	if ((*best)->aprevdist < (*best)->anextdist
		&& (*best)->bprevdist < (*best)->bnextdist)
		command1(best, psa, psb);
	else if ((*best)->aprevdist >= (*best)->anextdist
		&& (*best)->bprevdist >= (*best)->bnextdist)
		command2(best, psa, psb);
	else if ((*best)->aprevdist < (*best)->anextdist
		&& (*best)->bprevdist >= (*best)->bnextdist)
		command3(best, psa, psb);
	else if ((*best)->aprevdist >= (*best)->anextdist
		&& (*best)->bprevdist < (*best)->bnextdist)
		command4(best, psa, psb);
}

void		sort_less_5_ints(t_push **psa, t_ptrs *a, t_push **psb)
{
	t_push		*tmp;
	t_push		*smallest;
	int			counter;

	counter = a->biggest_ord;
	while (a->biggest_ord != 3)
	{
		init_positions(psa, &a);
		where_is_smallest(psa, a, psb);
		a->biggest_ord--;
	}
	tmp = (*psa);
	smallest = (*psa);
	while (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->order < smallest->order)
			smallest = tmp;
	}
	a->biggest_ord = counter;
	sort_three_elem2(psa, a, psb, smallest);
	init_sec_and_last(psa, &a);
	if ((*psb))
		while ((*psb)->order != 0)
			write_order_pa(psb, psa);
}

void		where_is_smallest(t_push **psa, t_ptrs *a, t_push **psb)
{
	t_push	*tmp;
	t_push	*smallest;

	smallest = (*psa);
	tmp = (*psa);
	while (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->order < smallest->order)
			smallest = tmp;
	}
	init_positions(psa, &a);
	if (smallest->position != 1)
	{
		if ((a->biggest_ord / 2 + 1) >= smallest->position)
			while (smallest->position-- != 1)
				write_order_ra(psa);
		else
			while (smallest->position++ != a->biggest_ord + 1)
				write_order_rra(psa);
	}
	write_order_pb(psa, psb);
}
