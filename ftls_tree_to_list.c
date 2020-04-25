/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftls_tree_to_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 15:39:44 by marrodri          #+#    #+#             */
/*   Updated: 2020/03/04 15:39:46 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_list(t_list *list)
{
	ft_printf("list conts:\n");
	if (!list)
	{
		ft_printf("NULL\n");
		return ;
	}
	while (list)
	{
		ft_printf("%s\n", list->content);
		list = list->next;
	}
}

void	set_tree_node_to_list(t_tree_node *tnode, t_list **alist)
{
	t_list *new_node;

	new_node = ft_lstnew(tnode->data, 0);
	if (!*alist)
	{
		(*alist) = new_node;
	}
	else
	{
		ft_lstaddend(alist, new_node);
	}
}

/*
** NOTE THIS LEAKS IN PRINTF, FIND A WAY TO CLEAR ITS LEAKS
** 	printf("%12s\n", "hello world", 213);
*/

void	binary_tree_to_list(t_tree_node *root, t_list **alist)
{
	if (!root->left && !root->right)
	{
		set_tree_node_to_list(root, alist);
		return ;
	}
	else if (root)
	{
		if (root->left)
		{
			binary_tree_to_list(root->left, alist);
		}
		set_tree_node_to_list(root, alist);
		if (root->right)
		{
			binary_tree_to_list(root->right, alist);
		}
	}
	return ;
}
