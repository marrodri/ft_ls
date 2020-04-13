
#include "ft_ls.h"
//DONE
static int	option_checker(char opt)
{
	int i;
	const char options[5] = {'R','a','l','r','t'};

	i = 0;
	while(options[i])
	{
		if (options[i] == opt)
		{	
			return (i);
		}
		i++;
	}
	return (-1);
}

static void check_options_in_one_argv(t_app *app, char *av)
{
	int i;
	int pos;

	pos = -1;
	i = 1;
	while (av[i])
	{
		if ((pos = option_checker(av[i])) >= 0)
		{
			app->option_ch[pos] = 1;
		}
		i++;
	}
}

int check_active_option_ls(t_app *app, int ac, char **av)
{
	int i;

	i = 1;
	if (av[1][0] == '-')
	{
		check_options_in_one_argv(app, av[1]);
		return (2);
	}
	else
	{
		return (1);
	}
}
