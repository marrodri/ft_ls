
#include "ft_ls.h"

//default comparison
int alphanum_comp(char *str1, char *str2, char *cur_direct)
{
	(void)cur_direct;
	return (ft_strcmp(str1, str2) > 0);
}

// r flag use this comp
int rev_alphanum_comp(char *str1, char *str2, char *cur_direct)
{
	(void)cur_direct;
	return (ft_strcmp(str1, str2) < 0);
}

// t flag use this comp
// add the current path to this function for the Rt flag
int	 file_date_comp(char *file_name1, char *file_name2, char *cur_direct)
{
	//stat, lstat
	//time, ctime

	char *file_path1;
	char *file_path2;
	struct stat s1;
	struct stat s2;
	file_path1 = append_directory(cur_direct, file_name1);
	file_path2 = append_directory(cur_direct, file_name2);
	//check how the stat, works
	stat(file_path1, &s1);
	stat(file_path2, &s2);

	free(file_path1);
	free(file_path2);
	if(s1.st_mtime - s2.st_mtime == 0)
	{
		return (alphanum_comp(file_name1, file_name2, cur_direct));
	}
	return ((s1.st_mtime - s2.st_mtime) < 0);
	//check what is the st_ctime and how it works
}

// when rt flags are used
int rev_file_date_comp(char *file_name1, char *file_name2, char *cur_direct)
{
	//stat, lstat
	//time, ctime

// 	char *file1;
// 	char *file2;
// 	struct stat s1;
// 	struct stat s2;

// 	file1 = dir1->d_name;
// 	file2 = dir2->d_name;

// 	//check how the stat, works
// 	stat(file1, &s1);
// 	stat(file2, &s2);
// 	// s1.st_ctime;

// 	//check what is the st_ctime and how it works
// 	return ((s1.st_mtime - s2.st_mtime) > 0);
}