

#include "ft_ls.h"

void *print_file_name(t_file_data *file_data, t_app *app)
{
	char *str;

	(void)app;
	str = file_data->file_name;
	if (!str)
		ft_printf("NULL\n");
	else
		ft_printf("%s\n", str);
	return (0);
}

void *print_file_path(t_file_data *file_data, t_app *app)
{
	char *str;
	
	(void)app;
	str = file_data->file_path_name;
	if (!str)
		ft_printf("NULL\n");
	else
		ft_printf("%s\n", str);
	return (0);

}

void *print_l_format(t_file_data *file_data, t_app *app)
{
	char *str;

	str = file_data->detailed_file;
	if (!str)
		ft_printf("DATA IS NULL!!\n");
	else
	{
		//setup the padding for the middle column
		ft_printf("%s\n", str);
	}
	return (0);
}

//use this instead of print_inorder_tree
void print_content_tree(t_app *app, t_tree_node *curr, void *f(t_file_data *, t_app *))
{
	if (!curr)
		return ;
	if (!curr->left && !curr->right)
	{
		f(curr->data, app);
		return ;
	}
	else if (curr)
	{
		if (curr->left)
			print_content_tree(app, curr->left, f); 
		f(curr->data, app);
		if (curr->right)
			print_content_tree(app, curr->right, f); 
	}
	return ;
}
