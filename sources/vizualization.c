/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vizualization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 19:17:33 by jormond-          #+#    #+#             */
/*   Updated: 2019/09/24 21:20:33 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		gnl_executor(t_push **psa, t_push **psb, char *line, char *av)
{
	commander(line, psa, psb);
	free(line);
	if (!(ft_strcmp(av, "-v")))
		vizualization(*psa, *psb);
}

void		vizualization(t_push *psa, t_push *psb)
{
	t_push		*a;
	t_push		*b;

	a = psa;
	b = psb;
	printf(" A \t B \n");
	while (a || b)
	{
		if (a && b)
		{
			printf("[%d]\t[%d]\n", a->order, b->order);
			a = a->next;
			b = b->next;
		}
		else if (!a && b)
		{
			printf("[0]\t[%d]\n", b->order);
			b = b->next;
		}
		else if (a && !b)
		{
			printf("[%d]\t[0]\n", a->order);
			a = a->next;
		}
	}
}
