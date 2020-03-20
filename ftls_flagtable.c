

#include "ft_ls.h"

static int	

static void check_options_in_argv()
{

}

static void check_options_in_one_argv(t_app *app, char *av)
{
	int i;

	i = 1;
	while(av[i])
	{
		if()
		{

		}
		i++;
	}
}

int check_active_option_ls(t_app *app, int ac, char **av)
{
	int i;

	i = 1;
	//there's many edge cases, try to fix them later
	if(ac == 3 && av[1][1] == '-')
	{
		check_options_in_one_argv(app, av[1]);
		return 2;
	}
	else
	{

	}
}
//TODO
//  add a hash table, that checks
// the flags on the args, and activate
// those flags by setting to 1, 
// if a flag is not recognized, stop the
// program by returning an error
//