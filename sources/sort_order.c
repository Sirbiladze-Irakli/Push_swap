/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_order.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 12:57:03 by jormond-          #+#    #+#             */
/*   Updated: 2019/09/25 12:16:52 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		sort_order(t_push **ps, int order)
{
	int		i;
	int		tmp[1000];

	i = -1;
	while ((*ps)->next != NULL)
	{
		tmp[++i] = (*ps)->data;
		(*ps) = (*ps)->next;
	}
	tmp[++i] = (*ps)->data;
	sort_arr(tmp, order - 1);
	while ((*ps)->order != 1)
		(*ps) = (*ps)->prev;
	reinit_order(tmp, ps, order);
	while ((*ps)->prev != NULL)
		(*ps) = (*ps)->prev;
}

void		sort_arr(int *tmp, int order)
{
	int		i;
	int		j;
	int		swap;

	i = 0;
	while (i < order - 1)
	{
		j = i + 1;
		while (j < order)
		{
			if (tmp[i] > tmp[j])
			{
				swap = tmp[i];
				tmp[i] = tmp[j];
				tmp[j] = swap;
			}
			j++;
		}
		i++;
	}
}

void		reinit_order(int *tmp, t_push **ps, int order)
{
	int			i;
	t_push		*ptr;

	i = -1;
	ptr = *ps;
	while (++i < order - 1)
	{
		while ((*ps))
		{
			if ((*ps)->data == tmp[i])
				(*ps)->order = i + 1;
			(*ps) = (*ps)->next;
		}
		(*ps) = ptr;
	}
	(*ps) = ptr;
}

void		biggest_and_middle(t_push **ps)
{
	t_push		*tmp;

	tmp = (*ps);
	while (tmp->next)
		tmp = tmp->next;
}
