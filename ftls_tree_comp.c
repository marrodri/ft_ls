
#include "ft_ls.h"

//default comparison
int alphanum_comp(t_dirent *d1, t_dirent *d2)
{
	return (ft_strcmp(d1->d_name, d2->d_name) > 0);
}

// r flag use this comp
int rev_alphanum_comp(t_dirent *d1, t_dirent *d2)
{
	return (ft_strcmp(d1->d_name, d2->d_name) < 0);
}

// -Rr flag

// int rev_alphanum_str_comp(char *str1, char *str2)
// {
// 	return (ft_strcmp(str1, str2) < 0);
// }

// t flag use this comp
int file_date_comp(t_dirent *d1, t_dirent *d2)
{
	return 0;
}

// when rt flags are used
int rev_file_date_comp()
{
	return 0;
}