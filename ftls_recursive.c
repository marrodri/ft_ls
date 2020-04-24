
#include "ft_ls.h"
//DONE

//move here free list
void	recursive_ls(t_app *app, t_tree *ls_tree, char *cur_direct)
{
	t_list *dir_list;
	t_list *hold;
	// t_list *tmp;
	if (ls_tree)
	{
		dir_list = NULL;
		directories_to_list(ls_tree->root, &dir_list);
		hold = dir_list;
		while (dir_list)
		{
			ft_ls(app, dir_list->content);
			dir_list = dir_list->next;
		}
		dir_list = hold;
		//free list
		while(dir_list)
		{
			hold = dir_list;
			dir_list = dir_list->next;
			free(hold);
		}
	}
}