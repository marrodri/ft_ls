
#include "ft_ls.h"

void	last_mod_file_comp(t_dirent *dir1, t_dirent *dir2)
{
	
}

void add_data_to_tree(t_tree **ls_tree, t_dirent *dir_entry,
	int (*f)(t_dirent *d1, t_dirent *d2))
{
	if (!*ls_tree)
	{
		init_tree(ls_tree, new_node(dir_entry));
	}
	else
	{
		addnode_tree((*ls_tree)->root, new_node(dir_entry), f);
	}
}

void	setting_tree_ls(t_app *app, t_tree **ls_tree, t_dirent *dir_entry)
{
	if (app->option_ch[3] == 1)
	{
		add_data_to_tree(ls_tree, dir_entry, rev_alphanum_comp);
	}
	else if (app->option_ch[4] && !app->option_ch[3])
	{
		ft_printf(" order by current modified date\n");
	}
	else if (app->option_ch[4] && app->option_ch[3])
	{
		ft_printf(" order by reverser current modified date\n");
	}
	else
	{
		add_data_to_tree(ls_tree, dir_entry, alphanum_comp);
	}
}

void	recursive_ls(t_app *app, t_tree *ls_tree, char *cur_direct)
{
	t_list *dir_list;

	dir_list = NULL;
	directories_to_list(ls_tree->root, &dir_list, cur_direct);
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

int		ft_ls(t_app *app, char *cur_direct)
{
	int			len;
	t_dirent	*dir_entry; //directory entry
	t_tree		*ls_tree;  //tree that holds directory entries, (file and directory data)
	// t_list		*dir_list; //list that holds directory names 
	DIR			*dir_stream; //directory stream

	len = 0;
	app->hi_len = 0;
	ls_tree = NULL;
	// dir_list = NULL;
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
		if ('.' != dir_entry->d_name[0] || app->option_ch[1])
			setting_tree_ls(app, &ls_tree, dir_entry);
	}
	ls_output(app, ls_tree);
	closedir(dir_stream);
	if (app->option_ch[0])
		recursive_ls(app, ls_tree, cur_direct);
	if(ls_tree)
		free_binary_tree(ls_tree->root);
	return (1);
}