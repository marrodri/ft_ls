
#include "ft_ls.h"

void add_data_to_tree(t_tree **ls_tree, t_dirent *dir_entry, int (*f)(t_dirent *d1, t_dirent *d2))
{
	if(!*ls_tree)
	{
		init_tree(ls_tree, new_node(dir_entry));
	}
	else
	{
		addnode_tree((*ls_tree)->root, new_node(dir_entry), f);
	}
}

char	*append_directory(char *cur_direct, char *append_direct)
{
	char *new_dir;
	char *tmp;

	new_dir = ft_strjoin(cur_direct, "/");
	tmp = new_dir;
	new_dir = ft_strjoin(new_dir, append_direct);
	free(tmp);
	return new_dir;
}

void add_direct_to_tree(t_tree **dir_tree, char *cur_direct, t_dirent *dir_entry,
	int (*f)(t_dirent *d1, t_dirent *d2))
{
	char *append_dir;

	// printf("cur_direct is |%s|\n", append_dir);
	//if(!ft_strequ(dir_entry->d_name, ".."))
	//{
		append_dir = append_directory(cur_direct, dir_entry->d_name);
		if (is_directory(append_dir))
		{
			// printf("data is directory, setting to dir_tree\n");
			if (!*dir_tree)
				init_tree(dir_tree, new_node(append_dir));
			else
			{
				//note, it compares dirents, not strings with the f funct
				addnode_tree((*dir_tree)->root, new_node(append_dir), f);
			}
		}
		else
			free(append_dir);
	//}
}

t_list *directories_to_list(t_tree **ls_tree, char *cur_direct, t_list *dir_list,
	int (*f)(t_dirent *d1, t_dirent *d2))
{
	char *append_dir;
	t_list *new_dir_list;
	t_dirent *dir_entry;

	// TODO:
		//return 
	// printf("cur_direct is |%s|\n", append_dir);


		append_dir = append_directory(cur_direct, dir_entry->d_name);
		// if (is_directory(append_dir))
		// {
		// 	// printf("data is directory, setting to dir_tree\n");
		// 	if (!*dir_tree)
		// 		init_tree(dir_tree, new_node(append_dir));
		// 	else
		// 	{
		// 		//note, it compares dirents, not strings with the f funct
		// 		addnode_tree((*dir_tree)->root, new_node(append_dir), f);
		// 	}
		// }
		// else
			free(append_dir);
}

void	last_mod_file_comp(t_dirent *dir1, t_dirent *dir2)
{
	
}

void	setting_tree_ls(t_app *app, t_tree **ls_tree, t_dirent *dir_entry)
{
	if(app->option_ch[3] == 1)
	{
		add_data_to_tree(ls_tree, dir_entry, rev_alphanum_comp);
	}
	else if(app->option_ch[4] && !app->option_ch[3])
	{
		ft_printf(" order by current modified date\n");
	}
	else if(app->option_ch[4] && app->option_ch[3])
	{
		ft_printf(" order by reverser current modified date\n");
	}
	else
	{
		add_data_to_tree(ls_tree, dir_entry, alphanum_comp);
	}
}

int		ft_ls(t_app *app, char *cur_direct)
{
	int len;
	t_dirent	*dir_entry; //directory entry
	t_tree		*ls_tree;  //tree that holds directory entries, (file data)
	// t_tree		*dir_tree; //REMOVE THIS
	t_list		*dir_list; //list that holds directory names 
	DIR			*dir_stream; //directory stream

	len = 0;
	app->hi_len = 0;
	ls_tree = NULL;
	//dir_tree = NULL;
	dir_list = NULL;
	/*
	** opendir: open directory descriptor 
	** (simliar to file descriptor, instead with directories)
	** returns a directory stream
	*/
	dir_stream = opendir(cur_direct);
	if (dir_stream == NULL)
	{
		// IMPORTANT: go to var_len in printf, to check how to free any leaks with str and ints and format
		printf("error\n");
        printf("ft_ls: %s: %s\n", cur_direct, strerror(errno));
		return (0);
	}
	//if the folder is empty it exits right away, leaving the tree, still null
	while ((dir_entry = readdir(dir_stream)) != NULL)
	{
		//case, enter all dots when the a option is added
		if ('.' != dir_entry->d_name[0] || app->option_ch[1])
		{
			setting_tree_ls(app, &ls_tree, dir_entry);
			//if the recursive is active, use the directory entry to check
			//add a condition that the .. file is not checked
			// if (app->option_ch[0] == 1)
			// {
			// 	// if (app->option_ch[3] == 1)
			// 	// {
			// 	// 	add_direct_to_tree(&dir_tree, cur_direct, dir_entry, rev_alphanum_str_comp);
			// 	// }
			// 	// else
			// 	// {
			// 	// 	add_direct_to_tree(&dir_tree, cur_direct, dir_entry, alphanum_comp);
			// 	// }
			// }
		}
	}
	if(ls_tree)
	{
		ls_output(app, ls_tree);
		ft_printf("\n");
	}
	closedir(dir_stream);
	// print_list(dir_list);
	if (app->option_ch[0])
	{
		
		binary_tree_to_list(ls_tree->root, &dir_list);
		add_direct_to_list(ls_tree);
	 	// print_list(dir_list);
		t_list *hold = dir_list;
		while(dir_list)
		{
			ft_printf("%s:\n", dir_list->content);
			ft_ls(app,dir_list->content);
			dir_list = dir_list->next;
		}
		// free_binary_tree(dir_tree->root);
		//free list
		// while(hold)
		// {

		// }
	}
	if(ls_tree)
		free_binary_tree(ls_tree->root);

	/*
	** NOTE: everything is not leaking at this point so every memory is still
	** reachable
	*/

	return (1);
}