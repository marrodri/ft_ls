
#include "ft_ls.h"

// ft_ls flags[- l,R,a,r,t] <dir default = ".">
// TODO recreate the ls function 
// with 
// -l, more detailed output
//  -R, recursive output
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



// int flag_check_ls(char **av)
// {

// }

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

void	ls_output(t_app *app, char **words)
{
	int i = 0;
	while (words[i])
	{
		char *str = "%-15s";
		ft_printf(str, words[i]);
		i++;
	}
}

int		ft_ls(t_app *app, struct dirent *dir_entry, DIR *dir_stream)
{
	char *str;
	int len;
	int check;
	char **words;
	t_tree binary_tree;

	check = 0;
	len = 0;
	str = ft_strnew(1);
	while ((dir_entry = readdir(dir_stream)) != NULL)
	{
		//move this to output list
		if ('.' != dir_entry->d_name[0])
		{
			if ((app)->hi_len < (len = ft_strlen(dir_entry->d_name)))
			{
				(app)->hi_len = len;
				ft_printf("new len is %d\n", len);
			}
			str = ft_strjoin(dir_entry->d_name, str);
			str = ft_strjoin(" ", str);
		}
	}
	words = ft_strsplit(str, ' ');
	words = ft_sortwords(words, is_rsorted);
	ls_output(app, words);
	return (0);
}

void app_init(t_app *app)
{
	struct winsize w;
	// get the window size for output
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	app->hi_len = 0;
	app->win_col = w.ws_col;
	app->cur_direct = ".";
}

int main(int argc, char **argv)
{
	/*
	** Pointer for directory entry
	*/
	struct dirent   *dir_entry; //directory entry
	DIR             *dir_stream; //directory stream
	t_app           app;


	int R_flag = 0;
	app_init(&app);
	if (argc >= 2)
	{
		if(!ft_strcmp(argv[1],"-R"))
		{
			R_flag = 1;
			ft_printf("RECURSIVE ACTIVATED\n");
			app.cur_direct = argv[2];
		}
		else
		{
			app.cur_direct = argv[1];
		}
	}

	/*
	** open directory descriptor 
	** (simliar to file descriptor, instead with directories)
	*/

	dir_stream = opendir(app.cur_direct);
	if (dir_stream == NULL)
	{
		// IMPORTANT: go to var_len in ft_printf, to check how to free any leaks with str and ints and format
		ft_printf("error\n");
        ft_printf("ft_ls: %s: %s\n", app.cur_direct, strerror(errno));
		return (0);
	}
	ft_ls(&app ,dir_entry, dir_stream);
	return (0);
}
