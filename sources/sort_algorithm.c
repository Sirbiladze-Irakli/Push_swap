/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 13:37:36 by jormond-          #+#    #+#             */
/*   Updated: 2019/10/12 17:07:08 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		sort_algorithm(t_push **psa, t_push **psb)
{
	t_ptrs		*a;
	t_ptrs		*b;

	init_ptrs(psa, &a);
	if (is_it_sorted2(psa, a) == OK)
		return ;
	else
	{
		if (a->biggest_ord > 5)
		{
			push_stack_b(psa, a, psb);
			sort_stacks(psa, a, psb, &b);
			if (ATOP != 1)
				last_rotate(psa, a);
		}
		else
			sort_less_5_ints(psa, a, psb);
	}
}

int			is_it_sorted2(t_push **psa, t_ptrs *a)
{
	t_push		*tmp;

	tmp = (*psa);
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		if (tmp->order < tmp->prev->order)
			return (ERROR);
	}
	if (ATOP == 1 && ALAST == a->biggest_ord)
		return (OK);
	return (ERROR);
}

void		init_ptrs(t_push **psa, t_ptrs **a)
{
	t_push		*tmp;
	int			count;

	count = 1;
	if ((*psa) != NULL)
	{
		tmp = (*psa);
		(*a)->biggest_ord = 1;
		(*a)->last = (*psa);
		if ((*psa)->next != NULL)
		{
			(*a)->second = (*psa)->next;
			while (tmp != NULL)
			{
				tmp->position = count++;
				if (tmp->order > (*a)->biggest_ord)
					(*a)->biggest_ord = tmp->order;
				(*a)->last = tmp;
				tmp = tmp->next;
			}
		}
		(*a)->middle_ord = (*a)->biggest_ord / 2;
		(*a)->middle = (*a)->biggest_ord / 2;
	}
}

void		push_stack_b(t_push **psa, t_ptrs *a, t_push **psb)
{
	int			count;
	int			turnup;

	count = a->biggest_ord - 1;
	turnup = 1;
	while (count > 2)
	{
		if ((count - 1) == a->middle_ord)
		{
			turnup++;
			a->middle_ord = a->middle_ord / 2;
		}
		if (ATOP != 1 && ATOP != a->biggest_ord && ATOP != a->middle
			&& ATOP >= a->middle_ord)
		{
			(*psa)->turn = turnup;
			write_order_pb(psa, psb);
			count--;
		}
		if (ATOP == 1 || ATOP == a->biggest_ord || ATOP == a->middle
			|| ATOP < a->middle_ord)
			where_you_go(psa, a);
	}
	sort_three_elem(psa, a);
}

int			find_shortest_way(t_push **psa, t_ptrs *a)
{
	t_push		*tmp;

	tmp = (*psa);
	(*psa)->aprevdist = 2;
	(*psa)->anextdist = 1;
	while (tmp->order == a->biggest_ord && tmp->order == 1
		&& tmp->order < a->middle_ord && tmp->order == a->middle)
	{
		(*psa)->anextdist++;
		tmp = tmp->next;
	}
	tmp = a->last;
	while (tmp->order == a->biggest_ord && tmp->order == a->middle
		&& tmp->order == 1 && tmp->order < a->middle_ord)
	{
		(*psa)->aprevdist++;
		tmp = tmp->prev;
	}
	if ((*psa)->anextdist <= (*psa)->aprevdist)
		return (0);
	else
		return (1);
}
