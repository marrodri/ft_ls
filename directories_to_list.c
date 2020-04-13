
#include "ft_ls.h"
//DONE
void	add_directory_to_list(t_list **dir_list, t_file_data *file_data)
{
	t_list *new_node;

	if (!ft_strequ("..", file_data->file_name) && !ft_strequ(".", file_data->file_name))
	{
		if (is_directory(file_data->file_path_name))
		{
			new_node = ft_lstnew(file_data->file_path_name, 0);
			if (!*dir_list)
				(*dir_list) = new_node;
			else
				ft_lstaddend(dir_list, new_node);
		}
	}
}

void directories_to_list(t_tree_node *root, t_list **dir_list)
{
	if (!root)
		return ;
	if (!root->left && !root->right)
	{
		add_directory_to_list(dir_list, root->data);
		return;
	}
	else if (root)
	{
		if (root->left)
			directories_to_list(root->left, dir_list);
		add_directory_to_list(dir_list, root->data);
		if (root->right)
			directories_to_list(root->right, dir_list);
	}
	return ;
}
