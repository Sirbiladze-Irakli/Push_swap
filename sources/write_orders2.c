/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_orders2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 21:05:39 by jormond-          #+#    #+#             */
/*   Updated: 2019/09/24 21:22:02 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		write_order_rb(t_push **psb)
{
	order_ra_rb(psb);
	write(1, "rb\n", 3);
}

void		write_order_pa(t_push **psb, t_push **psa)
{
	order_pa_pb(psb, psa);
	write(1, "pa\n", 3);
}

void		write_order_rrb(t_push **psb)
{
	order_rra_rrb(psb);
	write(1, "rrb\n", 4);
}

void		write_order_sb(t_push **psb)
{
	order_sa_sb(psb);
	write(1, "sb\n", 3);
}
