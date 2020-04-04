
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


//TODO file name manipulation for the l format
//BONUS: later do the ACL extensions

char 	*format_mtime(time_t mod_time)
{
	struct tm *data_time;
	char *time_format;
	// data_time = time(&mod_time);
	char *tmp;

	time_format = ft_itoa(data_time->tm_mon);
	tmp = time_format;
	time_format = ft_strjoin(time_format, " ");
	free(tmp);
	tmp = time_format;
	time_format = ft_strjoin(time_format, ft_itoa(data_time->tm_mday));
	
	free(tmp);
	tmp = time_format;
	time_format = ft_strjoin(time_format, " ");
	
	free(tmp);
	tmp = time_format;
	time_format = ft_strjoin(time_format, ft_itoa(data_time->tm_hour));

	free(tmp);
	tmp = time_format;
	time_format = ft_strjoin(time_format, ":");
	
	free(tmp);
	tmp = time_format;
	time_format = ft_strjoin(time_format, ft_itoa(data_time->tm_min));
	free(tmp);

	
	// data_time->tm_min;
	return time_format;
}

char	*file_name_long_format(t_stat *stat_file, char *file_name)
{
	//get the username, group name, and
	struct group	*grp_cont;
	struct passwd	*pw_cont;
	long int 		data_size;
	char			*l_formatted;
	char			*mod_date;
	char			*tmp;

	mod_date = ctime((long int)stat_file->st_mtime);
	data_size = (long int)stat_file->st_size;
	grp_cont = getgrgid(stat_file->st_gid);
	pw_cont = getpwuid(stat_file->st_uid);
	// ft_printf("===FILE DATA=======\n");
	// ft_printf("user: %s\n", pw_cont->pw_name);
	// ft_printf("group: %s\n", grp_cont->gr_name);
	// ft_printf("size: %ld\n", data_size);
	// ft_printf("time: %s\n", "mod_date");
	// ft_printf("file_name: %s\n", file_name);
	// ft_printf("=============\n\n");

	l_formatted = ft_llitoa_base(data_size, 10);
	tmp = l_formatted;
	l_formatted = ft_strjoin(l_formatted, " ");
	free(tmp);
	tmp = l_formatted;
	l_formatted = ft_strjoin(l_formatted, mod_date);
	free(tmp);
	tmp = l_formatted;
	l_formatted = ft_strjoin(l_formatted, " ");
	free(tmp);
	tmp = l_formatted;
	l_formatted = ft_strjoin(l_formatted, file_name);
	free(tmp);
	return (l_formatted);
}