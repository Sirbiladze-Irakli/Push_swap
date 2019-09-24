/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_orders3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 21:05:41 by jormond-          #+#    #+#             */
/*   Updated: 2019/09/24 21:22:11 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		write_order_ss(t_push **psa, t_push **psb)
{
	order_ss(psa, psb);
	write(1, "ss\n", 3);
}

void		write_order_rr(t_push **psa, t_push **psb)
{
	order_rr(psa, psb);
	write(1, "rr\n", 3);
}

void		write_order_rrr(t_push **psa, t_push **psb)
{
	order_rrr(psa, psb);
	write(1, "rrr\n", 4);
}
