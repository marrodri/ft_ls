
#include "ft_ls.h"

char	*append_directory(char *cur_direct, char *append_direct)
{
	char *new_dir;
	char *tmp;

	new_dir = ft_strjoin(cur_direct, "/");
	tmp = new_dir;
	new_dir = ft_strjoin(new_dir, append_direct);
	free(tmp);
	return (new_dir);
}

void	add_directory_to_list(t_list **dir_list, char *cur_direct, t_dirent *dir_entry)
{
	char *append_dir;
	t_list *new_node;
	
	append_dir = append_directory(cur_direct, dir_entry->d_name);
	if (is_directory(append_dir))
	{
		new_node = ft_lstnew(append_dir, 0);
		if (!*dir_list)
		{
			(*dir_list) = new_node;
		}
		else
		{
			ft_lstaddend(dir_list, new_node);
		}
	}
	else
		free(append_dir);
}

//debug here
//  iterate through the tree from the left to right
// through each node iterated, check the d_name if its a directory or not;
//	if it's a directory, add the name to the list, if not then free the name
// then iterate through the whole tree with the same steps  
void directories_to_list(t_tree_node *root, t_list **dir_list, char *cur_direct)
{
	if (!root->left && !root->right)
	{
		// printf("root cont is %s\n", root->data);
		//set_tree_node_to_list(root, alist);
		// print_list(*alist);
		add_directory_to_list(dir_list, cur_direct, root->data);
		return;
	}
	else if (root)
	{
		if (root->left)
		{
			directories_to_list(root->left, dir_list, cur_direct);
		}
		add_directory_to_list(dir_list, cur_direct, root->data);
		if (root->right)
		{
			directories_to_list(root->right, dir_list, cur_direct);
		}
	}
	return ;
}
