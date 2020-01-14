/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 16:18:24 by marrodri          #+#    #+#             */
/*   Updated: 2019/12/02 16:18:26 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int		ft_atol(const char *str)
{
	long int sign;
	long int res;
	long int i;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' ||
			str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		str++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	res = res * sign;
	return (res);
}
