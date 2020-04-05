

#include "ft_ls.h"


//add the app for the human readable option
char *filesize_to_string(off_t file_size)
{
	long int bitsize;
	char *bitsize_str;

	bitsize = (long int)file_size;
	bitsize_str = ft_llitoa_base(bitsize, 10);
	ft_printf("%s\n", bitsize_str);
	return (bitsize_str);
}

char *user_and_group_to_string(uid_t user_id, gid_t group_id)
{
	char *user_and_group_str;
	struct group  *grp_cont;
	struct passwd *pw_cont;
	char *tmp;

	grp_cont = getgrgid(group_id); //the group who created the program
	pw_cont = getpwuid(user_id); //the user who's running the program

	user_and_group_str = pw_cont->pw_name;
	user_and_group_str = ft_strjoin(user_and_group_str, " ");
	tmp = user_and_group_str;
	user_and_group_str = ft_strjoin(user_and_group_str, grp_cont->gr_name);
	free(tmp);
	return (user_and_group_str);
}

char *modified_time_to_string(time_t mod_time)
{
	char *readable_mtime_str;

	readable_mtime_str = ctime(&mod_time);
	readable_mtime_str = str_char_replace(readable_mtime_str, '\n', ' ');
	return (readable_mtime_str);
}