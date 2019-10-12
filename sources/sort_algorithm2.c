/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 10:48:35 by jormond-          #+#    #+#             */
/*   Updated: 2019/10/12 17:14:33 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		sort_stacks(t_push **psa, t_ptrs *a, t_push **psb, t_ptrs **b)
{
	int			turndown;

	turndown = (*psb)->turn;
	// turndown = 100000000;
	while (turndown > 0)
	{
		init_sec_and_last(psa, &a);
		init_sec_and_last(psb, b);
		if ((*psb)->order > ALAST && (*psb)->order < ATOP)
		{
			write_order_pa(psb, psa);
			turndown = (*psb)->turn;
		}
		if ((*psb)->order == 0)
			break ;
		analize_stack_b(psb, b, turndown);			// fix time to work!
		analize_stack_a(psa, &a, psb);			// fix time to work!
		which_way(psa, psb, turndown);			// fix time to work!
	}
}

void		init_sec_and_last(t_push **psa, t_ptrs **a)
{
	(*a)->second = (*psa)->next;
	order_rra_rrb(psa);
	(*a)->last = (*psa);
	order_ra_rb(psa);
}

void		where_you_go(t_push **psa, t_ptrs *a)
{
	if (!find_shortest_way(psa, a))
		while ((*psa)->anextdist-- > 0)
			write_order_ra(psa);
	else
		while ((*psa)->aprevdist-- > 0)
			write_order_rra(psa);
}

void		sort_three_elem(t_push **psa, t_ptrs *a)
{
	init_sec_and_last(psa, &a);
	if (ATOP > ASEC && ASEC > ALAST)
		write_order_sa(psa);
	else if (ATOP < ASEC && ASEC > ALAST && ATOP < ALAST)
		write_order_sa(psa);
	else if (ATOP > ASEC && ATOP < ALAST)
		write_order_sa(psa);
	else
		return ;
}

void		last_rotate(t_push **psa, t_ptrs *a)
{
	t_push		*tmp;
	int			dist;

	tmp = (*psa);
	dist = 0;
	while (tmp->order != 1)
	{
		tmp = tmp->next;
		dist++;
	}
	tmp->anextdist = dist;
	tmp->aprevdist = a->biggest_ord - tmp->anextdist + 1;
	if (tmp->anextdist <= tmp->aprevdist)
		while (tmp->anextdist--)
			write_order_ra(psa);
	else
		while (tmp->aprevdist--)
			write_order_rra(psa);
}
