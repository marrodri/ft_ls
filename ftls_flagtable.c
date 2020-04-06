

#include "ft_ls.h"

//run this function if there is one argument with many options
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

//change to int that returns the pos that is not a flag
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
			// ft_printf("pos is %d\n", pos);
			// ft_printf("app->option_ch[%d] is %d\n", pos, app->option_ch[pos]);
		}
		i++;
	}
}

int check_active_option_ls(t_app *app, int ac, char **av)
{
	int i;

	i = 1;
	//there's many edge cases, try to fix them later
	if(av[1][0] == '-')
	{
		check_options_in_one_argv(app, av[1]);
		return (2);
	}
	else
	{
		return (1);
	}
}

//TODO
//  add a hash table, that checks
// the flags on the args, and activate
// those flags by setting to 1, 
// if a flag is not recognized, stop the
// program by returning an error
//