/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_orders1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 21:05:32 by jormond-          #+#    #+#             */
/*   Updated: 2019/09/24 21:16:01 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		write_order_ra(t_push **psa)
{
	order_ra_rb(psa);
	write(1, "ra\n", 3);
}

void		write_order_pb(t_push **psa, t_push **psb)
{
	order_pa_pb(psa, psb);
	write(1, "pb\n", 3);
}

void		write_order_rra(t_push **psa)
{
	order_rra_rrb(psa);
	write(1, "rra\n", 4);
}

void		write_order_sa(t_push **psa)
{
	order_sa_sb(psa);
	write(1, "sa\n", 3);
}
