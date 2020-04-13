
#include "ft_ls.h"

//move here the append directory
char	*append_directory(char *cur_direct, char *append_direct)
{
	char *new_dir;
	char *tmp;

	new_dir = ft_strjoin(cur_direct, "/");
	tmp = new_dir;
	new_dir = ft_strjoin(new_dir, append_direct);
	free(tmp);
	return (new_dir);
}

char	*str_char_replace(char *str, char find, char replace)
{
	int i;

	i = 0;
	while(str[i])
	{
		if(str[i] == find)
			str[i] = replace;
		i++;
	}
	return str;
}


//TODO file name manipulation for the l format
//BONUS: later do the ACL extensions