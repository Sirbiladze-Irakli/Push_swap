/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 15:46:54 by jormond-          #+#    #+#             */
/*   Updated: 2019/08/27 21:28:59 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void		ft_join_free(char **content, char *buf)
{
	char	*tmp;

	tmp = *content;
	tmp = ft_strjoin(*content, buf);
	free(*content);
	*content = tmp;
}
