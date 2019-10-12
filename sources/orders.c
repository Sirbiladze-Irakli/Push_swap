/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orders.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 18:14:48 by jormond-          #+#    #+#             */
/*   Updated: 2019/09/25 12:20:06 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		order_sa_sb(t_push **ps)
{
	t_push		*psn;
	t_push		*next;

	if ((*ps) != NULL && (*ps)->next != NULL && (*ps)->order != 0
			&& (*ps)->next->order != 0)
	{
		psn = (*ps)->next;
		sa_sb_swap(ps, psn, &next);
		go_to_head(ps);
	}
}

void		sa_sb_swap(t_push **ps, t_push *psn, t_push **next)
{
	if (psn->next != NULL)
	{
		(*next) = psn->next;
		psn->prev = NULL;
		psn->next = (*ps);
		(*ps)->prev = psn;
		(*ps)->next = (*next);
		(*next)->prev = (*ps);
	}
	else
	{
		psn->prev = NULL;
		psn->next = (*ps);
		(*ps)->prev = psn;
		(*ps)->next = NULL;
	}
}

void		order_ss(t_push **psa, t_push **psb)
{
	order_sa_sb(psa);
	order_sa_sb(psb);
}

void		order_pa_pb(t_push **psa, t_push **psb)
{
	t_push		*nexta;

	if ((*psa) == NULL || (*psa)->order == 0)
		return ;
	else
	{
		if ((*psa)->next != NULL)
			pa_pb_with_next(psa, psb, &nexta);
		else
		{
			if ((*psb) != NULL)
			{
				(*psa)->next = (*psb);
				(*psb)->prev = (*psa);
			}
			else
				(*psa)->next = NULL;
			(*psb) = (*psa);
			(*psa) = create_zero();
		}
	}
}

void		pa_pb_with_next(t_push **psa, t_push **psb, t_push **nexta)
{
	(*nexta) = (*psa)->next;
	if ((*psb) != NULL && (*psb)->order != 0)
	{
		(*psa)->next = (*psb);
		(*psb)->prev = (*psa);
	}
	else
		(*psa)->next = NULL;
	(*nexta)->prev = NULL;
	(*psb) = (*psa);
	(*psa) = (*nexta);
}
