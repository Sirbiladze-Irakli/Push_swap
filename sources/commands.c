/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 21:44:29 by jormond-          #+#    #+#             */
/*   Updated: 2019/09/25 18:06:35 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		command1(t_push **best, t_push **psa, t_push **psb)
{
	int		i;

	i = 0;
	if ((*best)->aprevdist <= (*best)->bprevdist)
	{
		while (i++ < (*best)->aprevdist)
			write_order_rrr(psa, psb);
		while (i++ < (*best)->result)
			write_order_rrb(psb);
	}
	else if ((*best)->aprevdist > (*best)->bprevdist)
	{
		while (i++ < (*best)->bprevdist)
			write_order_rrr(psa, psb);
		while (i++ < (*best)->result)
			write_order_rra(psa);
	}
}

void		command2(t_push **best, t_push **psa, t_push **psb)
{
	int		i;

	i = 0;
	if ((*best)->anextdist <= (*best)->bnextdist)
	{
		while (i++ < (*best)->anextdist)
			write_order_rr(psa, psb);
		while (i++ <= (*best)->result)
			write_order_rb(psb);
	}
	else if ((*best)->anextdist > (*best)->bnextdist)
	{
		while (i++ < (*best)->bnextdist)
			write_order_rr(psa, psb);
		while (i++ <= (*best)->result)
			write_order_ra(psa);
	}
}

void		command3(t_push **best, t_push **psa, t_push **psb)
{
	int		i;

	i = 0;
	while (i++ < (*best)->aprevdist)
		write_order_rra(psa);
	i = 0;
	while (i++ < (*best)->bnextdist)
		write_order_rb(psb);
}

void		command4(t_push **best, t_push **psa, t_push **psb)
{
	int		i;

	i = 0;
	while (i++ < (*best)->anextdist)
		write_order_ra(psa);
	i = 0;
	while (i++ < (*best)->bprevdist)
		write_order_rrb(psb);
}

void		init_positions(t_push **ps)
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
