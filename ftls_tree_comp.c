
#include "ft_ls.h"

//default comparison
int alphanum_comp(char *str1, char *str2)
{
	return (ft_strcmp(str1, str2) > 0);
}

// r flag use this comp
int rev_alphanum_comp(char *str1, char *str2)
{
	return (ft_strcmp(str1, str2) < 0);
}

// t flag use this comp
// add the current path to this function for the Rt flag
int	 file_date_comp(t_dirent *dir1, t_dirent *dir2)
{
	//stat, lstat
	//time, ctime

	char *file1;
	char *file2;
	struct stat s1;
	struct stat s2;

	file1 = dir1->d_name;
	file2 = dir2->d_name;

	//check how the stat, works
	stat(file1, &s1);
	stat(file2, &s2);
	// s1.st_ctime;

	//check what is the st_ctime and how it works
	return ((s1.st_mtime - s2.st_mtime) < 0);
}

// when rt flags are used
int rev_file_date_comp(t_dirent *dir1, t_dirent *dir2)
{
	//stat, lstat
	//time, ctime

	char *file1;
	char *file2;
	struct stat s1;
	struct stat s2;

	file1 = dir1->d_name;
	file2 = dir2->d_name;

	//check how the stat, works
	stat(file1, &s1);
	stat(file2, &s2);
	// s1.st_ctime;

	//check what is the st_ctime and how it works
	return ((s1.st_mtime - s2.st_mtime) > 0);
}