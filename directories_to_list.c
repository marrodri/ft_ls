
#include "ft_ls.h"

// char	*append_directory(char *cur_direct, char *append_direct)
// {
// 	char *new_dir;
// 	char *tmp;

// 	new_dir = ft_strjoin(cur_direct, "/");
// 	tmp = new_dir;
// 	new_dir = ft_strjoin(new_dir, append_direct);
// 	free(tmp);
// 	return (new_dir);
// }

void	add_directory_to_list(t_list **dir_list, t_file_data *file_data)
{
	// char *append_dir;
	t_list *new_node;
	
	// ft_printf("dir_entry |%s|\n", file_name);
	// append_dir = append_directory(cur_direct, file_name);
	if(!ft_strequ("..", file_data->file_name) && !ft_strequ(".", file_data->file_name))
	{
		if (is_directory(file_data->file_path))
		{
			new_node = ft_lstnew(file_data->file_path, 0);
			if (!*dir_list)
			{
				(*dir_list) = new_node;
			}
			else
			{
				ft_lstaddend(dir_list, new_node);
			}
		}
	}
	// else
	// 	free(append_dir);
}

//debug here
//  iterate through the tree from the left to right
// through each node iterated, check the d_name if its a directory or not;
//	if it's a directory, add the name to the list, if not then free the name
// then iterate through the whole tree with the same steps  
void directories_to_list(t_tree_node *root, t_list **dir_list)
{
	if(!root)
		return ;
	if (!root->left && !root->right)
	{
		// printf("root cont is %s\n", root->data);
		//set_tree_node_to_list(root, alist);
		// print_list(*alist);
		add_directory_to_list(dir_list, root->data);
		return;
	}
	else if (root)
	{
		if (root->left)
		{
			directories_to_list(root->left, dir_list);
		}
		add_directory_to_list(dir_list, root->data);
		if (root->right)
		{
			directories_to_list(root->right, dir_list);
		}
	}
	return ;
}
