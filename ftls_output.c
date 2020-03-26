

#include "ft_ls.h"

//bonus TODO: format the output to the window size
void	format_output()
{
	//how to do it
	//check if the whole list can be added to one line, if it does
	//then append each name by 2 spaces

	//if not then with then use the calculated length of the curr width line for making blocks 
	//	append each name with padding then a new newline, the file names are different
	
	//reference
	// int i = 0;
	// while (words[i])
	// {
	// 	char *str = "%-15s";
	// 	printf(str, words[i]);
	// 	i++;
	// }
}

void	ls_detailed_output(t_tree *file_tree)
{
	// TODO add the -l flag output function here
	(void)file_tree;
	ft_printf("detailed output here\n");
}

void	ls_output(t_app *app, t_tree *ls_tree, char *cur_direct)
{
	if(app->option_ch[0])
	{
		ft_printf("%s:\n", cur_direct);
	}
	if(ls_tree)
	{
		if(app->option_ch[2])
		{
			ls_detailed_output(ls_tree);
		}
		else
		{
			print_content_tree(ls_tree->root, print_string);
			//print_inorder_tree(file_tree->root);
		}
	}
	ft_printf("\n");
}
