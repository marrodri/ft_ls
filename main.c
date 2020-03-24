
#include "ft_ls.h"

// ft_ls flags[- l,R,a,r,t] <dir default = ".">
// TODO recreate the ls function 
// with 
// -l, more detailed output

//  -R, recursive output //DONE
//  -a, display hidden files, ._* files
//  -r, reverse the list order
//-t, sorts by modification time, from the most current
// modified object to the oldest modified object

// start with -R at the beggining of all the flags

// using ls with the -R flag
// display the files and directories of the current directory
// from the directory 1 found, use the ls function again
// to display files and directories of the directory 1
// 

void app_init(t_app *app)
{
	struct	winsize w;
	int		i;

	// get the window size for output
	i = 0;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	app->hi_len = 0;
	app->win_col = w.ws_col;
	app->cur_direct = ".";
	app->root_direct = ".";
	while (i < 5)
	{
		app->option_ch[i] = 0;
		i++;
	}
}

/*
* TODO LATER:
* FIX FT_PRINTF WHEN FREEING AND CLEAR ALL LEAKS AS POSIBLE
* IMPORTANT: go to var_len in ft_printf, to check how to free any leaks with str and ints and format

* BUGS FOUND:
* segfault when there is an empty folder
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
		// set argvs to app_tree if more than 1 argv name 
		// apart from the options argvs;
		app.cur_direct = argv[i];
		app.root_direct = argv[i];
	}
	ft_ls(&app, app.cur_direct);
	// system("leaks a.out");
	return (0);
}
