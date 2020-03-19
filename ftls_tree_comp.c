
#include "ft_ls.h"

//default comparison
int alphanum_comp(char *cur_str, char *node_str)
{
	return (ft_strcmp(cur_str, node_str) > 0);
}

// r flag use this comp
int rev_alphanum_comp(char *cur_str, char *node_str)
{
	return (ft_strcmp(cur_str, node_str) < 0);
}

// t flag use this comp
int file_date_comp()
{
	return 0;
}

// when rt flags are used
int rev_file_date_comp()
{
	return 0;
}