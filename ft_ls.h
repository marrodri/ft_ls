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

typedef struct	s_tree_node
{
	char				*data;
	struct s_tree_node	*left;
	struct s_tree_node	*right;
}				t_tree_node;

typedef	struct	s_tree
{
	struct s_tree_node	*root;
}				t_tree;

typedef struct	s_app
{
	int flag_ch[5];
	int hi_len;
	int win_col; //columns
	int win_lines; //rows
	char *cur_direct;
	// t_tree *directories;
}		t_app;


/*
** main functions-------------------------------------------------------
*/



/*
** checkers-------------------------------------------------------
*/

int			is_rsorted(char *a, char *b);
int			is_regular_file(const char *file);

/*
** sorting functions------------------------------------------------
*/

char		**ft_sortwords(char **words, int (*f)(char *a, char *b));

/*
** Binary Tree-------------------------------------------------------
*/

void		init_tree(t_tree **tree, t_tree_node *node);
t_tree_node *new_node(char *file_name);
t_tree_node *addnode_tree(t_tree_node *curr, t_tree_node *node);
void		print_inorder_tree(t_tree_node *curr);
#endif