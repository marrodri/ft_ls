
#include "ft_ls.h"

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

void add_data_to_tree(t_tree **ls_tree, struct dirent *dir_entry)
{
	if(!*ls_tree)
		init_tree(ls_tree, new_node(dir_entry->d_name));
	else
	{
		addnode_tree((*ls_tree)->root, new_node(dir_entry->d_name));
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

int		is_directory(const char *path)
{
	struct stat		stat_buf;
	lstat(path, &stat_buf);
	return S_ISDIR(stat_buf.st_mode);
}


void add_direct_to_tree(t_tree **dir_tree, char *cur_direct, struct dirent *dir_entry)
{
	char *append_dir;

	append_dir = append_directory(cur_direct, dir_entry->d_name);
	ft_printf("cur_direct is |%s|\n", append_dir);
	if (is_directory(append_dir))
	{
		ft_printf("data is directory, setting to dir_tree\n");
		if (!*dir_tree)
			init_tree(dir_tree, new_node(append_dir));
		else
		{
			addnode_tree((*dir_tree)->root, new_node(append_dir));
		}
	}
	else
		free(append_dir);
}



int		ft_ls(t_app *app, DIR *dir_stream, char *cur_direct)
{
	int len;
	struct dirent   *dir_entry; //directory entry
	t_tree *ls_tree;
	t_tree *dir_tree;
	char *append_direct;

	len = 0;
	app->hi_len = 0;
	ls_tree = NULL;
	dir_tree = NULL;
	while ((dir_entry = readdir(dir_stream)) != NULL)
	{
		// move this to output list
		if ('.' != dir_entry->d_name[0])
		{
			if ((app)->hi_len < (len = ft_strlen(dir_entry->d_name)))
			{
				(app)->hi_len = len;
			}
			add_data_to_tree(&ls_tree, dir_entry);
			if (app->recursive)
				add_direct_to_tree(&dir_tree, cur_direct, dir_entry);
		}
	}
	print_inorder_tree(ls_tree->root);
	closedir(dir_stream);
	// words = ft_sortwords(words, is_rsorted);
	// ls_output(app, words);
	if(app->recursive)
	{
		// while()
		// {
		ft_printf("\n FOLDERS ARE:\n");
		if(dir_tree)
			print_inorder_tree(dir_tree->root);
		// }
	}
	return (0);
}