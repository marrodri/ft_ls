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

typedef struct	s_node
{
	char		*data;
	struct s_node	*left;
	struct s_node	*right;
}				t_node;

typedef	struct	s_tree
{
	struct s_node *root;
}				t_tree;

typedef struct	s_app
{
	int flag_ch[5];
	int hi_len;
	int win_col;
	int win_lines;
}		t_app;

char **ft_sortwords(char **words, int (*f)(char *a, char *b));
int	is_rsorted(char *a, char *b);
int	is_regular_file(const char *file);
#endif