/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 12:48:40 by jormond-          #+#    #+#             */
/*   Updated: 2019/09/25 21:41:26 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		gnl_executor(t_push **psa, t_push **psb, char *line, char *av)
{
	commander(line, psa, psb);
	if (!(ft_strcmp(av, "-v")))
	{
		vizualization(*psa, psb);
		write(1, "\norder: ", 8);
		cyan();
		write(1, line, ft_strlen(line));
		write(1, "\n", 1);
		reset();
	}
	free(line);
}

int			main(int ac, char **av)
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
		order = 0;
		while (get_next_line(0, &line) > 0)
		{
			gnl_executor(&psa, &psb, line, av[1]);
			order++;
		}
		if (!(ft_strcmp(av[1], "-v")))
			end_of_vizualization(order);
		is_it_sorted(psa, psb);
	}
	exit(0);
}
