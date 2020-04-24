/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 19:00:07 by marrodri          #+#    #+#             */
/*   Updated: 2019/04/27 19:00:08 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdio.h"

/*
** check leaks here, move all printf files
*/

int		var_len(char *str, int *i, va_list args)
{
	int		sum;
	char	*tstr;
	t_flags	*st_flag;
	int		free_fflag;
	int		free_tstr;

	sum = 0;
	free_fflag = 0;
	free_tstr = 0;
	if ((st_flag = malloc(sizeof(t_flags))) == NULL)
		return (0);
	set_fflags(str, &(*i), &st_flag, &free_fflag);
	tstr = (set_form(str[*i], args, st_flag, &free_tstr));
	if (tstr != NULL)
	{
		if (tstr[0] == '\0' && str[*i] == 'c')
			sum++;
		tstr = format_str(tstr, str[*i], st_flag, &free_tstr);
		ft_putstr(tstr);
		sum = sum + (ft_strlen(tstr));
	}
	free(st_flag);
	if (free_tstr == 1)
		free(tstr);
	return (sum);
}

int		print_len(char *str, va_list args)
{
	int		sum;
	int		i;

	sum = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			sum = sum + var_len(str, &i, args);
			i++;
		}
		if (str[i] != '%' && str[i])
		{
			ft_putchar(str[i]);
			i++;
			sum++;
		}
	}
	return (sum);
}

int		ft_printf(char *str, ...)
{
	int		sum;
	va_list	args;

	va_start(args, str);
	sum = print_len(str, args);
	va_end(args);
	return (sum);
}
