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
	if(!curr)
	{
		ft_printf("NULL\n");
		return ;
	}
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

//int ascii_order(){return (ft_strcmp(curr->data, node->data) > 0)}

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

t_tree_node *new_node(void *data)
{
	t_tree_node *new_node;

	new_node = malloc(sizeof(t_tree_node));
	new_node->data = data;
	new_node->left = NULL;
	new_node->right = NULL;
	return (new_node);
}

// NOTE THIS LEAKS IN PRINTF, FIND A WAY TO CLEAR ITS LEAKS
// 	ft_printf("%12s\n", "hello world", 213);

// int main()
// {
// 	char *a = "output.txt";
// 	char *b = "test_output.txt";
// 	char *c = "libft";
// 	char *d = "ans_output.txt";
// 	char *e = "Main";
// 	char *f = "ft_ls.h";
// 	char *g = "main.c";
// 	char *h = "a.out";

// 	t_tree *tree;
// 	t_tree_node *n1 = new_node(a);
// 	t_tree_node *n2 = new_node(b);
// 	t_tree_node *n3 = new_node(c);
// 	t_tree_node *n4 = new_node(d);
// 	t_tree_node *n5 = new_node(e);
// 	t_tree_node *n6 = new_node(f);
// 	t_tree_node *n7 = new_node(g);
// 	t_tree_node *n8 = new_node(h);
// 	init_tree(&tree, n1);
// 	tree->root = addnode_tree(tree->root, n2);
// 	tree->root = addnode_tree(tree->root, n3);
// 	tree->root = addnode_tree(tree->root, n4);
// 	tree->root = addnode_tree(tree->root, n5);
// 	tree->root = addnode_tree(tree->root, n6);
// 	tree->root = addnode_tree(tree->root, n7);
// 	tree->root = addnode_tree(tree->root, n8);

	
// 	print_inorder_tree(tree->root);
// 	return 0;
// }