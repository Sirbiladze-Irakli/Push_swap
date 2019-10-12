/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulate_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 15:29:26 by jormond-          #+#    #+#             */
/*   Updated: 2019/09/25 17:46:07 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void			struct_init(t_push **ps, int *order, char *buf)
{
	(*order) = 1;
	if (!((*ps) = (t_push *)malloc(sizeof(t_push))))
		error_output();
	(*ps)->order = *order;
	(*ps)->next = NULL;
	(*ps)->prev = NULL;
	(*ps)->data = ft_atoi(buf);
	(*ps)->turn = 0;
	(*ps)->aprevdist = 0;
	(*ps)->anextdist = 0;
	(*ps)->bprevdist = 0;
	(*ps)->bnextdist = 0;
	(*ps)->position = 0;
	if ((*ps)->data != ft_atol(buf))
		error_output();
}

void			add_node(t_push **ps, int *order, char *buf)
{
	if ((*ps) == NULL)
		struct_init(ps, order, buf);
	else
	{
		while ((*ps))
		{
			if ((*ps)->next == NULL)
			{
				(*ps)->next = ps_lstnew(ps, (*order), buf);
				(*ps) = (*ps)->next;
				break ;
			}
			(*ps) = (*ps)->next;
		}
	}
}

t_push			*ps_lstnew(t_push **ps, int order, char *buf)
{
	t_push		*tmp;

	if (!(tmp = (t_push *)malloc(sizeof(t_push))))
		error_output();
	tmp->order = order;
	tmp->data = ft_atoi(buf);
	if (tmp->data != ft_atol(buf))
		error_output();
	tmp->next = NULL;
	tmp->prev = (*ps);
	tmp->turn = 0;
	tmp->aprevdist = 0;
	tmp->anextdist = 0;
	tmp->bprevdist = 0;
	tmp->bnextdist = 0;
	tmp->position = 0;
	return (tmp);
}

t_push			*create_zero(void)
{
	t_push		*tmp;

	if (!(tmp = (t_push *)malloc(sizeof(t_push))))
		error_output();
	tmp->order = 0;
	tmp->turn = 0;
	tmp->aprevdist = 0;
	tmp->anextdist = 0;
	tmp->bprevdist = 0;
	tmp->bnextdist = 0;
	tmp->next = NULL;
	tmp->prev = NULL;
	return (tmp);
}
