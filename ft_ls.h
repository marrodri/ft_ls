#ifndef FT_LS
# define FT_LS
# include "libft/libft.h"
# include "libft/ft_printf.h"
# include <sys/types.h>
# include <dirent.h> // opendir, readdir, closedir
# include <sys/stat.h> //stat, lstat
# include <pwd.h> //getpwuid
# include <grp.h> //getgrgid
# include <sys/xattr.h> //listxattr, getxattr
# include <time.h> //time, ctime
# include <errno.h> //perror, strerror
# include <sys/ioctl.h> //BONUS for properling spacing the ft_ls as possible as the original ls output
# define FLAG_SZ 5
// from unistd.h readlink

// exit()
typedef struct s_app
{
	/*
	** {"-l","-R","-a","-r","-t"}
	*/

	int flag_ch[5];
	int hi_len;
}		t_app;

char **ft_sortwords(char **words, int (*f)(char *a, char *b));
int	is_rsorted(char *a, char *b);

#endif