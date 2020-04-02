
#include "ft_ls.h"

//default comparison
int alphanum_comp(t_tree_node *file1, t_tree_node *file2)
{
	// ft_printf("setting new file\n");
	return (ft_strcmp(file1->file_name, file2->file_name) > 0);
}

// r flag use this comp
int rev_alphanum_comp(t_tree_node *file1, t_tree_node *file2)
{
	return (ft_strcmp(file1->file_name, file2->file_name) < 0);
}

// t flag use this comp
// add the current path to this function for the Rt flag
int	 file_date_comp(t_tree_node *file1, t_tree_node *file2)
{
	//stat, lstat
	//time, ctime

	// char *file_path1;
	// char *file_path2;
	// struct stat s1;
	// struct stat s2;
	// file_path1 = append_directory(cur_direct, file_name1);
	// file_path2 = append_directory(cur_direct, file_name2);
	// //check how the stat, works
	// stat(file_path1, &s1);
	// stat(file_path2, &s2);

	// free(file_path1);
	// free(file_path2);
	// if(s1.st_ctime - s2.st_ctime == 0)
	// {
	// 	return (alphanum_comp(file_name1, file_name2, cur_direct));
	// }
	// file1->mod_time - file2->mod_time;
	// return ((s1.st_ctime - s2.st_ctime) <= 0);
	return ((file1->mod_time - file2->mod_time) <= 0);
	//check what is the st_ctime and how it works
}

// when rt flags are used
int rev_file_date_comp(t_tree_node *file1, t_tree_node *file2)
{
	// char *file_path1;
	// char *file_path2;
	// struct stat s1;
	// struct stat s2;
	// file_path1 = append_directory(cur_direct, file_name1);
	// file_path2 = append_directory(cur_direct, file_name2);
	// //check how the stat, works
	// stat(file_path1, &s1);
	// stat(file_path2, &s2);

	// free(file_path1);
	// free(file_path2);
	// if(s1.st_mtime - s2.st_mtime == 0)
	// {
	// 	return (alphanum_comp(file_name1, file_name2, cur_direct));
	// }
	return ((file1->mod_time - file2->mod_time) >= 0);
	// return ((s1.st_mtime - s2.st_mtime) >= 0);
	//check what is the st_ctime and how it works
}