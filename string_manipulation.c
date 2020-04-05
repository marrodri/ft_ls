
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
char	*file_name_l_format(t_stat *stat_file, char *file_name)
{
	//get the username, group name, and
	struct group	*grp_cont;
	struct passwd	*pw_cont;
	long int 		data_size;
	char			*l_formatted;
	char			*mod_date;
	char			*tmp;

	mod_date = ctime(&stat_file->st_mtime);
	mod_date = str_char_replace(mod_date, '\n', ' ');
	data_size = (long int)stat_file->st_size;
	grp_cont = getgrgid(stat_file->st_gid); //the group who created the program
	pw_cont = getpwuid(stat_file->st_uid); //the user who's running the program
	l_formatted = ft_llitoa_base(data_size, 10);
	tmp = l_formatted;
	l_formatted = ft_strjoin(l_formatted, " ");
	free(tmp);
	tmp = l_formatted;
	l_formatted = ft_strjoin(l_formatted, mod_date);
	free(tmp);
	tmp = l_formatted;
	l_formatted = ft_strjoin(l_formatted, file_name);
	free(tmp);
	return (l_formatted);
}