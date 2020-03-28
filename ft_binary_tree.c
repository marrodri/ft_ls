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
t_tree_node *addnode_tree(t_tree_node *curr, t_tree_node *node, 
	int (*f)(t_tree_node *file1, t_tree_node *file2))
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

t_tree_node *new_node(char *file, char *cur_direct)
{
	t_tree_node	*new_node;
	char		*file_path;
	struct stat	stat_file;
	
	new_node = malloc(sizeof(t_tree_node));
	file_path = append_directory(cur_direct, file);
	stat(file_path, &stat_file);
	new_node->data = file;
	new_node->file_size = stat_file.st_size;
	new_node->mod_time = stat_file.st_mtime;
	new_node->user_id = stat_file.st_uid;
	new_node->group_id = stat_file.st_gid;
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
