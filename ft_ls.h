#ifndef FT_LS
# define FT_LS
# include "libft/libft.h"
# include "libft/ft_printf.h"
# include <sys/types.h>
# include <dirent.h> // opendir, readdir, closedir
# include <sys/stat.h> //stat, lstat
# include <pwd.h> //getpwuid //for ls prob
# include <grp.h> //getgrgid //for ls prob
# include <sys/xattr.h> //listxattr, getxattr  ..bonus probably
# include <time.h> //time, ctime
# include <errno.h> //perror, strerror
# include <sys/ioctl.h> //BONUS for properling spacing the ft_ls as possible as the original ls output
# include <stdio.h>

# define FLAG_SZ 5
// from unistd.h readlink

typedef struct dirent t_dirent;


//	-l, more detailed output
//  -R, recursive output, ALMOST DONE, there's segfault when using recursive on the desktop
//  -a, display hidden files, ._* files
//  -r, reverse the list order
//  -t, sorts by modification time, from the most current

typedef struct s_file_data
{
	char				*file_name;
	char				*detailed_file;
	char				*file_path;
	uid_t				user_id; //getpwuid
	gid_t				group_id; //getgrgid
	time_t				mod_time;
	off_t				file_size;
	int					is_directory;
}				t_file_data;

typedef struct	s_tree_node
{

	void				*data;
	// char				*file_name;
	// char				*detailed_flie;
	// char				*file_path;
	// uid_t				user_id; //getpwuid
	// gid_t				group_id; //getgrgid
	// time_t				mod_time;
	// off_t				file_size;
	// int					is_directory;
	struct s_tree_node	*left;
	struct s_tree_node	*right;
}				t_tree_node;

typedef	struct	s_tree
{
	t_tree_node	*root;
	t_tree_node	*bottom_left; //use it for traversing the tree for searching directories
	t_tree_node *bottom_right;
}				t_tree;

/*
** flag_ch
** 0 = R flag DONE
** 1 = a flag DONE
** 2 = l flag output, use this for ls_output
** 3 = r flag reverse  ascii order
** 4 = t flag date mod order
** 3 and 4 = rt reverse date mod order
*/ 

typedef struct s_dir_data
{
	char	*dir_path;
	t_dirent *dir;
	int		time;
}				t_dir_data;

typedef struct	s_app
{
	int		option_ch[5];
	int		hi_len;
	int		win_col; //columns
	int		win_lines; //rows
	char	*cur_direct;
	char	*root_direct;
}				t_app;


/*
** main functions-------------------------------------------------------
*/

int		ft_ls(t_app *app, char *cur_direct);
int		check_active_option_ls(t_app *app, int ac, char **av);

/*
** list output----------------------------------------------------
*/

// void	ls_output(t_app *app, t_tree *file_tree);
void	ls_output(t_app *app, t_tree *ls_tree, char *cur_direct);
void	print_content_tree(t_tree_node *curr, void *f(t_file_data *));
void	print_parent_tree(t_tree_node *curr, void *f(void *));
void *print_string(t_file_data *file_data);
void	*print_dirent(void *addr_dirent);
void *print_l_format(t_file_data *file_data);
/*
** checkers-------------------------------------------------------
*/

int			is_directory(const char *path);
int			is_regular_file(const char *file);

/*
** sorting functions------------------------------------------------
*/
//it may be useless in the end
char		**ft_sortwords(char **words, int (*f)(char *a, char *b));

/*
** binary tree comparisons-------------------------------------------
*/

// int alphanum_comp(t_tree_node *file1, t_tree_node *file2);
// int rev_alphanum_comp(t_tree_node *file1, t_tree_node *file2);
// int	 file_date_comp(t_tree_node *file1, t_tree_node *file2);
// int rev_file_date_comp(t_tree_node *file1, t_tree_node *file2);
char	*append_directory(char *cur_direct, char *append_direct);

int alphanum_comp(t_file_data *file1, t_file_data *file2);
int rev_alphanum_comp(t_file_data *file1, t_file_data *file2);
int	 file_date_comp(t_file_data *file1, t_file_data *file2);
int rev_file_date_comp(t_file_data *file1, t_file_data *file2);


/*
** Binary Tree-------------------------------------------------------
*/

void		init_tree(t_tree **tree, t_tree_node *node);
t_tree_node *new_node(void *data);
// t_tree_node *addnode_tree(t_tree_node *curr, t_tree_node *node, 
// 	char *cur_direct, int (*f)(char *str1, char *str2, char *cur_direct));

t_tree_node *addnode_tree(t_tree_node *curr, t_tree_node *node, 
	int (*f)(t_file_data *file1, t_file_data *file2));

void		free_binary_tree(t_tree_node *root);
void		binary_tree_to_list(t_tree_node *root, t_list **alist);
void		print_list(t_list *list);
void 		directories_to_list(t_tree_node *root, t_list **dir_list);


void *print_path(t_file_data *file_data);
#endif