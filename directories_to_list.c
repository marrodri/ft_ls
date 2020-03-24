

#include "ft_ls.h"

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

void	add_directory_to_list(t_list **dir_list, char *cur_direct, t_dirent *dir_entry)
{
	char *append_dir;
	t_list *new_node;
	
	append_dir = append_directory(cur_direct, dir_entry->d_name);
	if (is_directory(append_dir))
	{
		// ft_printf("append_dir is ");
		new_node = ft_lstnew(append_dir, 0);
		if (!*dir_list)
		{
			// 	init_tree(dir_tree, new_node(append_dir));
			(*dir_list) = new_node;
		}
		else
		{
			// 	addnode_tree((*dir_tree)->root, new_node(append_dir), f);
			ft_lstaddend(dir_list, new_node);
		}
	}
	else
		free(append_dir);
}

void directories_to_list(t_tree_node *root, t_list **dir_list, char *cur_direct)
{
	// t_list *new_dir_list;
	// t_dirent *dir_entry;

	// TODO:
	//  iterate through the tree from the left to right
	// through each node iterated, check the d_name if its a directory or not;
	//	if it's a directory, add the name to the list, if not then free the name
	// then iterate through the whole tree with the same steps  

	if (!root->left && !root->right)
	{
		// printf("root cont is %s\n", root->data);
		//set_tree_node_to_list(root, alist);
		// print_list(*alist);
		add_directory_to_list(dir_list, cur_direct, root->data);
		return;
	}
	else if(root)
	{
		if(root->left)
		{
			directories_to_list(root->left, dir_list, cur_direct);
		}
		// printf("middle root cont is %s\n", root->data);
		// set_tree_node_to_list(root, alist);
		add_directory_to_list(dir_list, cur_direct, root->data);
		// print_list(*alist);
		if(root->right)
		{
			directories_to_list(root->right, dir_list, cur_direct);
		}
	}
	return ;

	// printf("cur_direct is |%s|\n", append_dir);
}


// void add_direct_to_tree(t_tree **dir_tree, char *cur_direct, t_dirent *dir_entry,
// 	int (*f)(t_dirent *d1, t_dirent *d2))
// {
// 	char *append_dir;

// 	// printf("cur_direct is |%s|\n", append_dir);
// 	//if(!ft_strequ(dir_entry->d_name, ".."))
// 	//{
// 	append_dir = append_directory(cur_direct, dir_entry->d_name);
// 	if (is_directory(append_dir))
// 	{
// 		// printf("data is directory, setting to dir_tree\n");
// 		if (!*dir_tree)
// 			init_tree(dir_tree, new_node(append_dir));
// 		else
// 		{
// 			//note, it compares dirents, not strings with the f funct
// 			addnode_tree((*dir_tree)->root, new_node(append_dir), f);
// 		}
// 	}
// 	else
// 		free(append_dir);
// 	//}
// }