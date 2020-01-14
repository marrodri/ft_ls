/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 14:17:20 by marrodri          #+#    #+#             */
/*   Updated: 2019/09/30 14:17:23 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_list_size(t_list *list)
{
	t_list	*tmp;
	int		i;

	i = 0;
	if (!list)
		return (0);
	tmp = list;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
