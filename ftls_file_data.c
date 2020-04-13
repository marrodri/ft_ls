
#include "ft_ls.h"
//DONE
t_file_data *init_file_data(char *file_name, char *cur_direct)
{
	char		*file_path;
	t_stat		stat_file;
	t_file_data *new_fd;
	char		*bit_size_str;
	time_t	new_mtime;

	new_fd = malloc(sizeof(t_file_data));
	file_path = append_directory(cur_direct, file_name);
	stat(file_path, &stat_file);
	new_mtime = stat_file.st_mtime;
	new_fd->file_name = file_name;
	new_fd->file_path_name = file_path;
	bit_size_str = filesize_to_string(stat_file.st_size);
	new_fd->user_group_names = user_and_group_to_string(stat_file.st_uid, stat_file.st_gid);
	new_fd->mod_date_output = modified_time_to_string(stat_file.st_mtime);
	new_fd->l_len_padding = ft_strlen(bit_size_str);
	new_fd->bits_size_output = bit_size_str;
	new_fd->file_size = stat_file.st_size;
	new_fd->mod_time = new_mtime;
	new_fd->user_id = stat_file.st_uid;
	new_fd->group_id = stat_file.st_gid;
	return (new_fd);
}

void add_data_to_tree(t_tree **ls_tree, t_file_data *file_data,
	int (*f)(t_file_data *file1, t_file_data *file2))
{
	if (!*ls_tree)
		init_tree(ls_tree, new_node(file_data));
	else
		addnode_tree((*ls_tree)->root, new_node(file_data), f);
}