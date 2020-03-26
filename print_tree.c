

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

void *print_string(void *addr_str)
{
	char *str;

	str = addr_str;
	if (!str)
	{
		ft_printf("NULL\n");
		return (0);
	}
	ft_printf("%s\n", str);
	return (0);
}


void print_parent_tree(t_tree_node *curr, void *f(void *))
{
	if (!curr)
	{
		return ;
	}
	if (!curr->left && !curr->right)
	{
		f(curr->parent);
		return ;
	}
	else if (curr)
	{
		if (curr->left)
		{
			print_parent_tree(curr->left, f); 
		}
		if (curr)
			f(curr->parent);
		if (curr->right)
		{
			print_parent_tree(curr->right, f); 
		}
	}
	return ;
}

//use this instead of print_inorder_tree
void print_content_tree(t_tree_node *curr, void *f(void *))
{
	if (!curr)
	{
		return ;
	}
	if (!curr->left && !curr->right)
	{
		f(curr->data);
		return ;
	}
	else if (curr)
	{
		if (curr->left)
		{
			print_content_tree(curr->left, f); 
		}
		f(curr->data);
		if (curr->right)
		{
			print_content_tree(curr->right, f); 
		}
	}
	return ;
}
