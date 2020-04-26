/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 15:39:44 by marrodri          #+#    #+#             */
/*   Updated: 2020/03/04 15:39:46 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	app_init(t_app *app)
{
	struct winsize	w;
	int				i;

	i = 0;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	app->hi_len = 0;
	app->win_col = w.ws_col;
	app->cur_direct = ".";
	app->root_direct = ".";
	app->long_column_padding = 0;
	while (i < 5)
	{
		app->option_ch[i] = 0;
		i++;
	}
}

void	setting_app_dir(t_app *app, char **argv, int i)
{
	if (i >= 0)
	{
		if (!argv[i])
		{
			app->cur_direct = ".";
			app->root_direct = ".";
		}
		else
		{
			app->cur_direct = argv[i];
			app->root_direct = argv[i];
		}
	}
}

int		main(int argc, char **argv)
{
	t_app	app;
	int		i;

	i = 1;
	app_init(&app);
	if (argc >= 2)
	{
		i = check_active_option_ls(&app, argc, argv);
		if (i == -1)
			return (0);
		setting_app_dir(&app, argv, i);
	}
	while (app.cur_direct && i != -1)
	{
		ft_ls(&app, app.cur_direct);
		if (argv[i])
			i++;
		app.cur_direct = argv[i];
	}
	return (0);
}
