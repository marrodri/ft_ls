
#include "ft_ls.h"

t_file_data *init_file_data(char *file_name, char *cur_direct)
{
	char		*file_path;
	t_stat		stat_file;
	t_file_data *new_fd;
	char		*bit_size_str;

	new_fd = malloc(sizeof(t_file_data));
	file_path = append_directory(cur_direct, file_name);
	stat(file_path, &stat_file);
	new_fd->file_name = file_name;
	new_fd->file_path_name = file_path;
	bit_size_str = filesize_to_string(stat_file.st_size);
	new_fd->user_group_names = user_and_group_to_string(stat_file.st_uid, stat_file.st_gid);
	new_fd->mod_date_output = modified_time_to_string(stat_file.st_mtime);
	new_fd->l_len_padding = ft_strlen(bit_size_str);
	new_fd->bits_size_output = bit_size_str;
	new_fd->file_size = stat_file.st_size;
	new_fd->mod_time = stat_file.st_mtime;
	new_fd->user_id = stat_file.st_uid;
	new_fd->group_id = stat_file.st_gid;
	return (new_fd);
}


void add_data_to_tree(t_tree **ls_tree, t_file_data *file_data,
	int (*f)(t_file_data *file1, t_file_data *file2))
{
	if (!*ls_tree)
		init_tree(ls_tree, new_node(file_data));
	else
		addnode_tree((*ls_tree)->root, new_node(file_data), f);
}

void	setting_tree_ls(t_app *app, t_tree **ls_tree, char *cur_direct, t_dirent *dir_entry)
{
	//rev_alphanum
	char		*file_name;
	t_file_data	*file_data;
	
	file_name = ft_strdup(dir_entry->d_name);
	file_data = init_file_data(file_name, cur_direct);
	if(app->long_column_padding < file_data->l_len_padding)
	{
		app->long_column_padding = file_data->l_len_padding;
	}
	if (app->option_ch[3] == 1 && !app->option_ch[4])
	{
		add_data_to_tree(ls_tree, file_data, rev_alphanum_comp);
	}
	else if (app->option_ch[4] && !app->option_ch[3])
	{
		//NOTE: ASK FOR HELP WHEN COMMING BACK
		add_data_to_tree(ls_tree, file_data, file_date_comp);
	}
	else if (app->option_ch[4] && app->option_ch[3])
	{
		//NOTE: ASK FOR HELP WHEN COMMING BACK
		add_data_to_tree(ls_tree, file_data, rev_file_date_comp);
	}	
	else
		add_data_to_tree(ls_tree, file_data, alphanum_comp);
}

//CHECKPOINT: DEBUG THE RECURSIVE WITH r
void	recursive_ls(t_app *app, t_tree *ls_tree, char *cur_direct)
{
	t_list *dir_list;
	if(ls_tree)
	{

		dir_list = NULL;
		// print_content_tree(ls_tree->root, print_path);
		directories_to_list(ls_tree->root, &dir_list);
		t_list *hold = dir_list;
		// print_list(dir_list);
		while(dir_list)
		{
			ft_ls(app, dir_list->content);
			dir_list = dir_list->next;
		}
		//free list
		// while(hold)
		// {

		// }
	}
}

int		ft_ls(t_app *app, char *cur_direct)
{
	int			len;
	t_dirent	*dir_entry; //directory entry
	t_tree		*ls_tree;  //tree that holds directory entries, (file and directory data)
	DIR			*dir_stream; //directory stream

	len = 0;
	app->hi_len = 0;
	app->long_column_padding = 0;
	ls_tree = NULL;
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
			setting_tree_ls(app, &ls_tree, cur_direct, dir_entry);
	}
	ls_output(app, ls_tree, cur_direct);
	closedir(dir_stream);
	if (app->option_ch[0])
		recursive_ls(app, ls_tree, cur_direct);
	if(ls_tree)
		free_binary_tree(ls_tree->root);
	return (1);
}