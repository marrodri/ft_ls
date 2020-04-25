/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 15:39:44 by marrodri          #+#    #+#             */
/*   Updated: 2020/03/04 15:39:46 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "libft/libft.h"
# include "libft/ft_printf.h"
# include <sys/types.h>
# include <dirent.h>
# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>
# include <sys/xattr.h>
# include <time.h>
# include <errno.h>
# include <sys/ioctl.h>
# include <stdio.h>
# define FLAG_SZ 5

typedef struct dirent	t_dirent;
typedef struct stat	t_stat;

/*
**	-l, more detailed output
**  -R, recursive output
**  -a, display hidden files, ._* files
**  -r, reverse the list order
**  -t, sorts by modification time, from the most current
*/

typedef struct	s_file_data
{
	char				*file_name;
	char				*detailed_file;
	char				*user_group_names;
	char				*file_path_name;
	char				*mod_date_output;
	char				*bits_size_output;
	char				acl[10];
	uid_t				user_id;
	gid_t				group_id;
	time_t				mod_time;
	nlink_t				links;
	off_t				file_size;
	int					is_directory;
	int					l_len_padding;
}				t_file_data;

typedef struct	s_tree_node
{

	void				*data;
	struct s_tree_node	*left;
	struct s_tree_node	*right;
}				t_tree_node;

typedef	struct	s_tree
{
	t_tree_node	*root;
	t_tree_node	*bottom_left;
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

typedef struct	s_dir_data
{
	char		*dir_path;
	t_dirent	*dir;
	int			time;
}				t_dir_data;

typedef struct	s_app
{
	int		option_ch[5];
	int		hi_len;
	int		win_col;
	int		win_lines;
	char	*cur_direct;
	char	*root_direct;
	int		long_column_padding;
}				t_app;

/*
** main functions-------------------------------------------------------
*/

int				ft_ls(t_app *app, char *cur_direct);
int				check_active_option_ls(t_app *app, int ac, char **av);
t_file_data		*init_file_data(char *file_name, char *cur_direct);
void			free_file_data(t_file_data **file_data);
void			add_data_to_tree(t_tree **ls_tree, t_file_data *file_data,
	int (*f)(t_file_data *file1, t_file_data *file2));
void			recursive_ls(t_app *app, t_tree *ls_tree, char *cur_direct);

/*
** list output----------------------------------------------------
*/

void			ls_output(t_app *app, t_tree *ls_tree, char *cur_direct);
void			print_content_tree(t_app *app, t_tree_node *curr,
		void *f(t_file_data *, t_app *));
void			print_parent_tree(t_tree_node *curr, void *f(void *));
void			*print_path(t_file_data *file_data, t_app *app);
void			*print_file_name(t_file_data *file_data, t_app *app);
void			*print_l_format(t_file_data *file_data, t_app *app);

/*
** checkers-------------------------------------------------------
*/

int				is_directory(const char *path);
int				is_regular_file(const char *file);

/*
** sorting functions------------------------------------------------
*/

char			**ft_sortwords(char **words, int (*f)(char *a, char *b));

/*
** binary tree comparisons-------------------------------------------
*/

int				alphanum_comp(t_file_data *file1, t_file_data *file2);
int				rev_alphanum_comp(t_file_data *file1, t_file_data *file2);
int				file_date_comp(t_file_data *file1, t_file_data *file2);
int				rev_file_date_comp(t_file_data *file1, t_file_data *file2);

/*
** Long format setup --------------------------------------------
*/

char			*append_directory(char *cur_direct, char *append_direct);
char			*str_char_replace(char *str, char find, char replace);
char			*file_name_l_format(t_stat *stat_file, char *file_name);
char			*filesize_to_string(off_t file_size);
char			*modified_time_to_string(time_t mod_time);
char			*user_and_group_to_string(nlink_t links, uid_t user_id, gid_t group_id);

/*
** Binary Tree-------------------------------------------------------
*/

void			init_tree(t_tree **tree, t_tree_node *node);
t_tree_node		*new_node(void *data);
t_tree_node		*addnode_tree(t_tree_node *curr, t_tree_node *node,
	int (*f)(t_file_data *file1, t_file_data *file2));
void			free_binary_tree(t_tree_node *root);
void			binary_tree_to_list(t_tree_node *root, t_list **alist);
void			print_list(t_list *list);
void			directories_to_list(t_tree_node *root, t_list **dir_list);
#endif
