
#include "ft_ls.h"
//ALMOST
void app_init(t_app *app)
{
	struct 	winsize w;
	int		i;

	// get the window size for output
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

void 	setting_app_dir(t_app *app, char **argv, int i)
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

/*
* TODO LATER:
		// IMPORTANT: go to var_len in printf, to check how to free any leaks with str and ints and format
* FIX FT_PRINTF WHEN FREEING AND CLEAR ALL LEAKS AS POSIBLE
* IMPORTANT: go to var_len in ft_printf, to check how to free any leaks with str and ints and format
*
* BONUS:
*	implement the h flag for human read
*	implement for the c time
*	implement for the d flag
*	also try the column format
*	ACL and extended attributes for the l flag
*/

int main(int argc, char **argv)
{
	t_app           app;
	int 			i;

	i = 1;
	app_init(&app);
	if (argc >= 2)
	{ 
		i = check_active_option_ls(&app, argc, argv);
		setting_app_dir(&app, argv, i);
	}
	while (app.cur_direct)
	{
		ft_ls(&app, app.cur_direct);
		if (argv[i])
		{
			i++;
		}
		app.cur_direct = argv[i];
	}
	return (0);
}
