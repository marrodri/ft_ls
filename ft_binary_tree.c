/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binarytree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 15:39:44 by marrodri          #+#    #+#             */
/*   Updated: 2020/03/04 15:39:46 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void print_inorder_tree(t_tree_node *curr)
{
	if (!curr->left && !curr->right)
	{
		ft_printf("%s\n", curr->data);
		return ;
	}
	else
	{
		if (curr->left)
		{
			print_inorder_tree(curr->left); 
		}
		ft_printf("%s\n", curr->data);
		if(curr->right)
		{
			print_inorder_tree(curr->right); 
		}
		return ;
	}
}

t_tree_node *addnode_tree(t_tree_node *curr, t_tree_node *node)
{
	if(curr == NULL)
	{
		return (node);
	}
	else
	{
		if(ft_strcmp(curr->data, node->data) > 0)
		{
			curr->left = addnode_tree(curr->left, node);
		}
		else
		{
			curr->right = addnode_tree(curr->right, node);
		}
		return (curr);
	}
}

void init_tree(t_tree **tree, t_tree_node *node)
{
	(*tree) = malloc(sizeof(t_tree));
	(*tree)->root = node;
}

t_tree_node *new_node(char *file_name)
{
	t_tree_node *new_node;

	new_node = malloc(sizeof(t_tree_node));
	new_node->data = file_name;
	new_node->left = NULL;
	new_node->right = NULL;
	return (new_node);
}

// NOTE THIS LEAKS IN PRINTF, FIND A WAY TO CLEAR ITS LEAKS
// 	ft_printf("%12s\n", "hello world", 213);
