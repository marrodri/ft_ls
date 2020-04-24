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

/*
** at the end of the binary tree, free, the file_data node content
** then free the file_data struct and lastly free the node
** free((*root)->data);
*/

void		free_binary_tree(t_tree_node *root)
{
	t_file_data *backup;

	if (!(root)->left && !(root)->right)
	{
		backup = root->data;
		free_file_data(&backup);
		free(root->data);
		free(root);
		root = NULL;
		return ;
	}
	else if (root)
	{
		if ((root)->left)
		{
			free_binary_tree(root->left);
		}
		if ((root)->right)
		{
			free_binary_tree(root->right);
		}
		backup = root->data;
		free_file_data(&backup);
		free(root->data);
		free(root);
		root = NULL;
	}
	return ;
}

t_tree_node	*addnode_tree(t_tree_node *curr, t_tree_node *node,
	int (*f)(t_file_data *file1, t_file_data *file2))
{
	if (curr == NULL)
	{
		return (node);
	}
	else
	{
		if (f(curr->data, node->data))
		{
			curr->left = addnode_tree(curr->left, node, f);
		}
		else
		{
			curr->right = addnode_tree(curr->right, node, f);
		}
		return (curr);
	}
}

void		init_tree(t_tree **tree, t_tree_node *node)
{
	(*tree) = malloc(sizeof(t_tree));
	(*tree)->root = node;
}

t_tree_node	*new_node(void *data)
{
	t_tree_node	*new_node;

	new_node = malloc(sizeof(t_tree_node));
	new_node->data = data;
	new_node->left = NULL;
	new_node->right = NULL;
	return (new_node);
}
