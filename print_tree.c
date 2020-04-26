/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 11:40:00 by marrodri          #+#    #+#             */
/*   Updated: 2019/05/15 11:40:04 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	*print_file_name(t_file_data *file_data, t_app *app)
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

void	*print_file_path(t_file_data *file_data, t_app *app)
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

void	col_padding(long pad, char *cur_str)
{
	int dif;

	dif = pad - ft_strlen(cur_str);
	while(dif)
	{
		ft_putchar(' ');
		dif--;
	}
}

void	*print_l_format(t_file_data *file_data, t_app *app)
{
	if (!file_data)
		ft_printf("DATA IS NULL!!\n");
	else
	{
		ft_printf("%d ", file_data->links);
		ft_printf("%s ", file_data->user_group_names);
		col_padding(app->long_column_padding, file_data->bits_size_output);
		ft_printf("%s ", file_data->bits_size_output);
		ft_printf("%s", file_data->mod_date_output);
		ft_printf("%s\n", file_data->file_name);
	}
	return (0);
}

void	print_content_tree(t_app *app, t_tree_node *curr,
	void *f(t_file_data *, t_app *))
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
