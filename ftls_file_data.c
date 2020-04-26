/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftls_file_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 13:26:30 by marrodri          #+#    #+#             */
/*   Updated: 2020/01/16 13:26:32 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void free_file_data(t_file_data **file_data)
{
	// ft_printf("(\nFREEING FILE DATAS!!!\n");
	// ft_printf("freeing user_group_names|%s|\n",(*file_data)->user_group_names);
	if((*file_data)->user_group_names)
	{

		free((*file_data)->user_group_names);
		(*file_data)->user_group_names = NULL;
	}

	// ft_printf("freeing mod_date_output|%s|\n",(*file_data)->mod_date_output);
	if((*file_data)->mod_date_output)
	{
		free((*file_data)->mod_date_output);
		(*file_data)->mod_date_output = NULL;
	}
	// ft_printf("freeing file_path_name|%s|\n",(*file_data)->file_path_name);
	if((*file_data)->file_path_name)
	{
		free((*file_data)->file_path_name);
		(*file_data)->file_path_name = NULL;
	}
	// ft_printf("freeing bits_size_output|%s|\n",(*file_data)->bits_size_output);
	if((*file_data)->bits_size_output)
	{
		free((*file_data)->bits_size_output);
		(*file_data)->bits_size_output = NULL;
	}
	// ft_printf("freeing file_name|%s|\n",(*file_data)->file_name);
	if((*file_data)->file_name)
	{
		free((*file_data)->file_name);
		(*file_data)->file_name = NULL;
	}
	// ft_printf("==========================!!!\n");

}

/*
**CREATE THE LINK DISPLAY
*/

t_file_data		*init_file_data(char *file_name, char *cur_direct)
{
	char		*file_path;
	t_stat		stat_file;
	t_file_data *new_fd;
	char		*bit_size_str;

	new_fd = malloc(sizeof(t_file_data));
	file_path = append_directory(cur_direct, file_name);
	lstat(file_path, &stat_file);
	new_fd->mod_time = (size_t)stat_file.st_mtime;
	new_fd->file_name = file_name;
	new_fd->file_path_name = file_path;
	new_fd->links = stat_file.st_nlink;
	bit_size_str = filesize_to_string(stat_file.st_size);
	new_fd->user_group_names =
		user_and_group_to_string(stat_file.st_uid, stat_file.st_gid);
	new_fd->l_len_padding = ft_strlen(bit_size_str);
	new_fd->bits_size_output = bit_size_str;
	new_fd->file_size = stat_file.st_size;
	new_fd->user_id = stat_file.st_uid;
	new_fd->group_id = stat_file.st_gid;
	new_fd->mod_date_output = modified_time_to_string(new_fd->mod_time);
	return (new_fd);
}

void			add_data_to_tree(t_tree **ls_tree, t_file_data *file_data,
	int (*f)(t_file_data *file1, t_file_data *file2))
{
	if (!*ls_tree)
		init_tree(ls_tree, new_node(file_data));
	else
		addnode_tree((*ls_tree)->root, new_node(file_data), f);
}
