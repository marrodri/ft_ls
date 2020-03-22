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

void print_inorder_str_tree(t_tree_node *curr)
{
	char *str;

	if(!curr)
	{
		ft_printf("NULL\n");
		return ;
	}
	str = curr->data;
	if (!curr->left && !curr->right)
	{
		ft_printf("%s\n", str);
		return ;
	}
	else if(curr)
	{
		if (curr->left)
		{
			print_inorder_tree(curr->left); 
		}
		str = curr->data;
		if(curr)
			ft_printf("%s\n", str);
		if(curr->right)
		{
			print_inorder_tree(curr->right); 
		}
	}
		return ;
}

void print_inorder_tree(t_tree_node *curr)
{
	t_dirent *dirent;

	if(!curr)
	{
		ft_printf("NULL\n");
		return ;
	}
	dirent = curr->data;
	if (!curr->left && !curr->right)
	{
		ft_printf("%s\n", dirent->d_name);
		return ;
	}
	else if(curr)
	{
		if (curr->left)
		{
			print_inorder_tree(curr->left); 
		}
		dirent = curr->data;
		if(curr)
			ft_printf("%s\n", dirent->d_name);
		if(curr->right)
		{
			print_inorder_tree(curr->right); 
		}
	}
		return ;
}

void free_binary_tree(t_tree_node *root)
{
	if (!(root)->left && !(root)->right)
	{
		// free((root)->data);
		free(root);
		root = NULL;
		return ;
	}
	else if(root)
	{
		if ((root)->left)
		{
			free_binary_tree(root->left); 
		}
		if ((root)->right)
		{
			free_binary_tree(root->right); 
		}
		// free((*root)->data);
		free(root);
		root = NULL;
	}
	return ;
}

//add comparison
// t_tree_node *addnode_tree(t_tree_node *curr, t_tree_node *node)
t_tree_node *addnode_tree(t_tree_node *curr, t_tree_node *node, int (*f)(t_dirent *d1, t_dirent *d2))
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

void init_tree(t_tree **tree, t_tree_node *node)
{
	(*tree) = malloc(sizeof(t_tree));
	(*tree)->root = node;
}

t_tree_node *new_node(void *data)
{
	t_tree_node *new_node;

	new_node = malloc(sizeof(t_tree_node));
	new_node->node_on_list = 0;
	new_node->use_free_on_data = 0;
	new_node->data = data;
	new_node->parent = NULL;
	new_node->left = NULL;
	new_node->right = NULL;
	return (new_node);
}

void print_list(t_list *list)
{
	ft_printf("list conts:\n");
	if(!list)
	{
		ft_printf("NULL\n");
		return ;
	}
	while(list)
	{
		ft_printf("%s\n", list->content);
		list = list->next;
	}

}

void set_tree_node_to_list(t_tree_node *tnode, t_list **alist)
{
	t_list *new_node;

	new_node = ft_lstnew(tnode->data, 0);
	// printf("new_node data is |%s|\n", new_node->content);
	// printf("tnode data is |%s|\n", tnode->data);
	if(!*alist)
	{
		// printf("current alist is null\n");
		(*alist) = new_node;
	}
	else
	{
		// printf("adding list to end\n");
		ft_lstaddend(alist, new_node);
	}
}


void binary_tree_to_list(t_tree_node *root, t_list **alist)
{
	if(!root->left && !root->right)
	{
		// printf("root cont is %s\n", root->data);
		set_tree_node_to_list(root, alist);
		// print_list(*alist);
		return;
	}
	else if(root)
	{
		if(root->left)
		{
			binary_tree_to_list(root->left, alist);
		}
		// printf("middle root cont is %s\n", root->data);
		set_tree_node_to_list(root, alist);
		// print_list(*alist);
		if(root->right)
		{
			binary_tree_to_list(root->right, alist);
		}
	}
	return ;
}

// NOTE THIS LEAKS IN PRINTF, FIND A WAY TO CLEAR ITS LEAKS
// 	printf("%12s\n", "hello world", 213);

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