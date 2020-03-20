
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





// int main(int ac, char **av)
// {
//     /*
//     ** window/terminal size structure. 
//     ** The winsize is accessed from the kernel
//     */

//     struct winsize w;

//     /*
//     ** 
//     */
//     ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

//     ft_printf("lines %d\n", w.ws_row);
//     ft_printf("columns %d\n", w.ws_col);
//     return 0;
// }

void app_init(t_app *app)
{
	struct	winsize w;
	int		i;

	// get the window size for output
	i = 0;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	app->hi_len = 0;
	app->recursive = 0;
	app->reverse = 0;
	app->win_col = w.ws_col;
	app->cur_direct = ".";
	app->root_direct = ".";
	while (i < 5)
	{
		app->flag_ch[i] = 0;
		i++;
	}
}

/*
* TODO LATER:
* FIX FT_PRINTF WHEN FREEING AND CLEAR ALL LEAKS AS POSIBLE
*/

int main(int argc, char **argv)
{
	/*
	** Pointer for directory entry
	*/
	t_app           app;

	app_init(&app);
	if (argc >= 2)
	{

		// move this to 
		if(!ft_strcmp(argv[1],"-R"))
		{
			app.recursive = 1;
			app.cur_direct = argv[2];
			app.root_direct = argv[2];
		}
		else if(!ft_strcmp(argv[1], "-r"))
		{
			app.reverse = 1;
			app.cur_direct = argv[2];
			app.root_direct = argv[2];
		}
		else
		{
			app.root_direct = argv[1];
			app.cur_direct = argv[1];
		}
	}

	/*
	** open directory descriptor 
	** (simliar to file descriptor, instead with directories)
	*/

	// dir_stream = opendir(app.cur_direct);
	// if (dir_stream == NULL)
	// {
	// 	// IMPORTANT: go to var_len in ft_printf, to check how to free any leaks with str and ints and format
	// 	ft_printf("error\n");
    //     ft_printf("ft_ls: %s: %s\n", app.cur_direct, strerror(errno));
	// 	return (0);
	// }
	ft_ls(&app, app.cur_direct);
	// system("leaks a.out");
	return (0);
}
