/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 17:30:08 by jormond-          #+#    #+#             */
/*   Updated: 2019/09/24 20:55:52 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		main(int ac, char **av)
{
	int				i;
	static int		order;
	t_push			*psa;
	t_push			*psb;

	i = 1;
	if (ac > 1)
	{
		while (--ac)
			valid_and_push_arg(av[i++], &psa, &order);
		sort_order(&psa, order);
		sort_algorithm(&psa, &psb);
	}
	exit(0);
}
