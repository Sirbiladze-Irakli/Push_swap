/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 13:02:24 by jormond-          #+#    #+#             */
/*   Updated: 2019/09/24 21:24:44 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		check_num(char *av, int *i, t_push **ps, int *order)
{
	int				j;
	int				data;
	char			buf[11];

	j = 0;
	while (ft_strchr("-0123456789", av[(*i)]) && j < 13)
		buf[j++] = av[(*i)++];
	buf[j] = '\0';
	add_node(ps, order, buf);
	data = (*ps)->data;
	while ((*ps)->prev != NULL)
	{
		(*ps) = (*ps)->prev;
		if ((*ps)->data == data)
			error_output();
	}
	(*order) += 1;
	(*i)--;
}

int			valid_arg(char *av, t_push **ps, int *order)
{
	int		i;

	i = -1;
	while (av[++i])
	{
		if (!ft_strchr(" -0123456789", av[i]))
			return (ERROR);
		if (av[i] == '-' && !ft_strchr("123456789", av[i + 1]))
			return (ERROR);
		if (ft_strchr("-0123456789", av[i]))
			check_num(av, &i, ps, order);
	}
	return (OK);
}

void		valid_and_push_arg(char *av, t_push **ps, int *order)
{
	if (!strcmp(av, ""))
		error_output();
	if (valid_arg(av, ps, order) == ERROR)
		error_output();
}

void		error_output(void)
{
	write(1, "Error\n", 6);
	exit(0);
}
