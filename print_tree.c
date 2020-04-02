

#include "ft_ls.h"

void *print_dirent(void *addr_dirent)
{
	t_dirent *dir_entry;

	dir_entry = addr_dirent;
	ft_printf("!!dir: ");
	if (!dir_entry)
	{
		ft_printf("NULL\n");
		return (0);
	}
	ft_printf("|%s|\n", (char*)dir_entry->d_name);
	return (0);
}

void *print_string(t_tree_node *file_data)
{
	char *str;

	str = file_data->file_name;
	if (!str)
	{
		ft_printf("NULL\n");
		return (0);
	}
	ft_printf("%s\n", str);
	return (0);
}

//use this instead of print_inorder_tree
void print_content_tree(t_tree_node *curr, void *f(t_tree_node *))
{
	if (!curr)
	{
		return ;
	}
	if (!curr->left && !curr->right)
	{
		f(curr);
		return ;
	}
	else if (curr)
	{
		if (curr->left)
		{
			print_content_tree(curr->left, f); 
		}
		f(curr);
		if (curr->right)
		{
			print_content_tree(curr->right, f); 
		}
	}
	return ;
}
