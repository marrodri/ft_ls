

#include "ft_ls.h"

// void *print_dirent(void *addr_dirent)
// {
// 	t_dirent *dir_entry;

// 	dir_entry = addr_dirent;
// 	ft_printf("!!dir: ");
// 	if (!dir_entry)
// 	{
// 		ft_printf("NULL\n");
// 		return (0);
// 	}
// 	ft_printf("|%s|\n", (char*)dir_entry->d_name);
// 	return (0);
// }

void *print_string(t_file_data *file_data)
{
	char *str;

	str = file_data->file_name;
	if (!str)
		ft_printf("NULL\n");
	else
		ft_printf("%s\n", str);
	return (0);
}

void *print_path(t_file_data *file_data)
{
	char *str;

	str = file_data->file_path;
	if (!str)
		ft_printf("NULL\n");
	else
		ft_printf("%s\n", str);
	return (0);

}

void *print_l_format(t_file_data *file_data)
{
	char *str;

	str = file_data->detailed_file;
	if (!str)
		ft_printf("DATA IS NULL!!\n");
	else
		ft_printf("%s\n", str);
	return (0);
}

//use this instead of print_inorder_tree
void print_content_tree(t_tree_node *curr, void *f(t_file_data *))
{
	if (!curr)
		return ;
	if (!curr->left && !curr->right)
	{
		f(curr->data);
		return ;
	}
	else if (curr)
	{
		if (curr->left)
			print_content_tree(curr->left, f); 
		f(curr->data);
		if (curr->right)
			print_content_tree(curr->right, f); 
	}
	return ;
}
