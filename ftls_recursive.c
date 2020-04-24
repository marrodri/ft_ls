/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftls_recursive.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 13:26:30 by marrodri          #+#    #+#             */
/*   Updated: 2020/01/16 13:26:32 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	recursive_ls(t_app *app, t_tree *ls_tree, char *cur_direct)
{
	t_list *dir_list;
	t_list *hold;

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
		while (dir_list)
		{
			hold = dir_list;
			dir_list = dir_list->next;
			free(hold);
		}
	}
}
