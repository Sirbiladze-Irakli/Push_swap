/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 21:44:29 by jormond-          #+#    #+#             */
/*   Updated: 2019/09/24 21:32:56 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		command1(t_push **best, t_push **psa, t_push **psb)
{
	if ((*best)->aprevdist <= (*best)->bprevdist)
	{
		while ((*best)->aprevdist-- != 0)
		{
			write_order_rrr(psa, psb);
			(*best)->bprevdist--;
		}
		while ((*best)->bprevdist-- != 0)
			write_order_rrb(psb);
	}
	else if ((*best)->aprevdist > (*best)->bprevdist)
	{
		while ((*best)->bprevdist-- != 0)
		{
			write_order_rrr(psa, psb);
			(*best)->aprevdist--;
		}
		while ((*best)->aprevdist-- != 0)
			write_order_rra(psa);
	}
}

void		command2(t_push **best, t_push **psa, t_push **psb)
{
	if ((*best)->anextdist <= (*best)->bnextdist)
	{
		while ((*best)->anextdist-- != 0)
		{
			write_order_rr(psa, psb);
			(*best)->bnextdist--;
		}
		while ((*best)->bnextdist-- != 0)
			write_order_rb(psb);
	}
	else if ((*best)->anextdist > (*best)->bnextdist)
	{
		while ((*best)->bnextdist-- != 0)
		{
			write_order_rr(psa, psb);
			(*best)->anextdist--;
		}
		while ((*best)->anextdist-- != 0)
			write_order_ra(psa);
	}
}

void		command3(t_push **best, t_push **psa, t_push **psb)
{
	while ((*best)->aprevdist-- != 0)
		write_order_rra(psa);
	while ((*best)->bnextdist-- != 0)
		write_order_rb(psb);
}

void		command4(t_push **best, t_push **psa, t_push **psb)
{
	while ((*best)->anextdist-- != 0)
		write_order_ra(psa);
	while ((*best)->bprevdist-- != 0)
		write_order_rrb(psb);
}

void		init_positions(t_push **ps, t_ptrs **p)
{
	t_push		*tmp;
	int			pos;

	tmp = (*ps);
	pos = 1;
	if (tmp->next != NULL)
	{
		while (tmp)
		{
			tmp->position = pos++;
			order_ra_rb(&tmp);
			if (tmp == (*ps))
				break ;
		}
	}
	else
		tmp->position = 1;
}
