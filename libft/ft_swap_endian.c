/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_endian.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 20:02:35 by marrodri          #+#    #+#             */
/*   Updated: 2019/09/08 20:02:36 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_uint32	swap_endian(t_uint32 num)
{
	return (((num & 0x000000ff) << 24u) |
			((num & 0x0000ff00) << 8u) |
			((num & 0x00ff0000) >> 8u) |
			((num & 0xff000000) >> 24u));
}
