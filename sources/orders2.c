/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orders2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 11:20:03 by jormond-          #+#    #+#             */
/*   Updated: 2019/09/24 21:31:46 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		order_ra_rb(t_push **psa)
{
	t_push		*last;
	t_push		*fnext;

	if ((*psa) == NULL || (*psa)->next == NULL)
		return ;
	else
	{
		fnext = (*psa)->next;
		last = (*psa);
		while (last->next != NULL)
			last = last->next;
		fnext->prev = NULL;
		last->next = (*psa);
		(*psa)->next = NULL;
		(*psa)->prev = last;
		(*psa) = fnext;
	}
}

void		order_rr(t_push **psa, t_push **psb)
{
	order_ra_rb(psa);
	order_ra_rb(psb);
}

void		order_rra_rrb(t_push **psa)
{
	t_push		*last;
	t_push		*plast;

	if ((*psa) == NULL || (*psa)->next == NULL)
		return ;
	else
	{
		last = (*psa);
		while (last->next != NULL)
			last = last->next;
		plast = last->prev;
		plast->next = NULL;
		last->prev = NULL;
		(*psa)->prev = last;
		last->next = (*psa);
		(*psa) = last;
	}
}

void		order_rrr(t_push **psa, t_push **psb)
{
	order_rra_rrb(psa);
	order_rra_rrb(psb);
}
