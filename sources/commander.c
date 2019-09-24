/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commander.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 17:45:29 by jormond-          #+#    #+#             */
/*   Updated: 2019/09/24 21:35:56 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		commander(char *line, t_push **psa, t_push **psb)
{
	if ((!(ft_strcmp(line, "sa"))))
		order_sa_sb(psa);
	else if (!(ft_strcmp(line, "sb")))
		order_sa_sb(psb);
	else if (!(ft_strcmp(line, "ss")))
		order_ss(psa, psb);
	else if (!(ft_strcmp(line, "pa")))
		order_pa_pb(psb, psa);
	else if (!(ft_strcmp(line, "pb")))
		order_pa_pb(psa, psb);
	else if (!(ft_strcmp(line, "ra")))
		order_ra_rb(psa);
	else if (!(ft_strcmp(line, "rb")))
		order_ra_rb(psb);
	else if (!(ft_strcmp(line, "rr")))
		order_rr(psa, psb);
	else if (!(ft_strcmp(line, "rra")))
		order_rra_rrb(psa);
	else if (!(ft_strcmp(line, "rrb")))
		order_rra_rrb(psb);
	else if (!(ft_strcmp(line, "rrr")))
		order_rrr(psa, psb);
	else
		error_output();
}

void		is_it_sorted(t_push *psa, t_push *psb)
{
	while (psa->prev != NULL)
		psa = psa->prev;
	while (psa->next != NULL)
	{
		psa = psa->next;
		if (psa->data < psa->prev->data)
			ko_output();
	}
	if (psb && psb->order != 0)
		ko_output();
	if (psa->data < psa->prev->data)
		ko_output();
	ok_output();
}

void		ok_output(void)
{
	write(1, "OK\n", 3);
	exit(0);
}

void		ko_output(void)
{
	write(1, "KO\n", 3);
	exit(0);
}

void		go_to_head(t_push **ps)
{
	while ((*ps) != NULL && (*ps)->prev != NULL)
		(*ps) = (*ps)->prev;
}
