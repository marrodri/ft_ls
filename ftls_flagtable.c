/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftls_flagtable.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 13:26:30 by marrodri          #+#    #+#             */
/*   Updated: 2020/01/16 13:26:32 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	illegal_option_error(char op)
{
	ft_printf("./ft_ls: invalid option -- '%c'\n", op);
}

static int	option_checker(char *opt, int *n)
{
	int			i;
	const char	options[5] = {'R', 'a', 'l', 'r', 't'};

	i = 0;
	while (i < 5)
	{
		if (options[i] == opt[*n])
		{
			return (i);
		}
		i++;
	}
	if(i == 5)
	{
		i == -1;
	}
	return (i);
}

static int	check_options_in_one_argv(t_app *app, char **av, int ac)
{
	int i;
	int pos;
	int n;

	n = 1;
	pos = 0;
	i = 1;
	while (i < ac && pos != -1)
	{
		if (av[i][0] != '-')
			break;
		n = 1;
		while (av[i][n] && pos != -1)
		{
			if ((pos = option_checker(av[i], &n)) >= 0)
			{
				if (pos != -1)
					app->option_ch[pos] = 1;
			}
			n += 1;
		}
		i++;
	}
	if(pos == -1)
	{
		illegal_option_error(av[i][n]);
		i = -1;
	}
	return (i);
}

int			check_active_option_ls(t_app *app, int ac, char **av)
{
	// int i;

	// i = 1;
	if (av[1][0] == '-')
	{
		return (check_options_in_one_argv(app, av, ac));
	}
	else
	{
		return (1);
	}
}
