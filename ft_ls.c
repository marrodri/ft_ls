/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 13:26:30 by marrodri          #+#    #+#             */
/*   Updated: 2020/01/16 13:26:32 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** ALMOST
*/

void	setting_tree_ls(t_app *app, t_tree **ls_tree,
	char *cur_direct, t_dirent *dir_entry)
{
	char		*file_name;
	t_file_data	*file_data;

	file_name = ft_strdup(dir_entry->d_name);
	file_data = init_file_data(file_name, cur_direct);
	if (app->long_column_padding < file_data->l_len_padding)
		app->long_column_padding = file_data->l_len_padding;
	if (app->option_ch[3] == 1 && !app->option_ch[4])
		add_data_to_tree(ls_tree, file_data, rev_alphanum_comp);
	else if (app->option_ch[4] && !app->option_ch[3])
		add_data_to_tree(ls_tree, file_data, file_date_comp);
	else if (app->option_ch[4] && app->option_ch[3])
		add_data_to_tree(ls_tree, file_data, rev_file_date_comp);
	else
		add_data_to_tree(ls_tree, file_data, alphanum_comp);
}

void	set_ls_data(t_app *app, int *len, t_tree **ls_tree)
{
	len = 0;
	app->hi_len = 0;
	app->long_column_padding = 0;
	*ls_tree = NULL;
}

void	free_ls_tree(t_tree **ls_tree)
{
	if (*ls_tree)
	{
		free_binary_tree((*ls_tree)->root);
		free(*ls_tree);
		*ls_tree = NULL;
	}
}

int		ft_ls(t_app *app, char *cur_direct)
{
	int			len;
	t_dirent	*dir_entry;
	t_tree		*ls_tree;
	DIR			*dir_stream;

	set_ls_data(app, &len, &ls_tree);
	dir_stream = opendir(cur_direct);
	if (dir_stream == NULL)
	{
		ft_printf("Illegal Option. ./ft_ls: %s: %s\n",
			cur_direct, strerror(errno));
		return (0);
	}
	while ((dir_entry = readdir(dir_stream)) != NULL)
	{
		if ('.' != dir_entry->d_name[0] || app->option_ch[1])
			setting_tree_ls(app, &ls_tree, cur_direct, dir_entry);
	}
	ls_output(app, ls_tree, cur_direct);
	closedir(dir_stream);
	if (app->option_ch[0])
		recursive_ls(app, ls_tree, cur_direct);
	free_ls_tree(&ls_tree);
	return (1);
}
