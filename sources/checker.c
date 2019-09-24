/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 12:48:40 by jormond-          #+#    #+#             */
/*   Updated: 2019/09/24 21:36:29 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		main(int ac, char **av)
{
	int				i;
	char			*line;
	static int		order;
	t_push			*psa;
	t_push			*psb;

	i = 1;
	if (ac > 1)
	{
		if (!(ft_strcmp(av[1], "-v")))
			i++;
		while (i < ac)
			valid_and_push_arg(av[i++], &psa, &order);
		sort_order(&psa, order);
		if (!(ft_strcmp(av[1], "-v")))
			vizualization(psa, psb);
		while (get_next_line(0, &line) > 0)
			gnl_executor(&psa, &psb, line, av[1]);
		is_it_sorted(psa, psb);
	}
	exit(0);
}
