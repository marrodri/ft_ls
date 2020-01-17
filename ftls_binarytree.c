
#include "ft_ls.h"

void print_inorder_tree(t_node *curr)
{
	if(!curr->left && !curr->right)
	{
		ft_printf("%s\n", curr->data);
		return ;
	}
	else
	{
		if(curr->left)
		{
			print_inorder_tree(curr->left); 
		}
		// print for middle node;
		ft_printf("%s\n", curr->data);
		if(curr->right)
		{
			print_inorder_tree(curr->right); 
		}
		return ;
	}
}

t_node *addnode_tree(t_node *curr, t_node *node)
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

void init_tree(t_tree **tree, t_node *node)
{
	(*tree) = malloc(sizeof(t_tree));
	(*tree)->root = node;

}

t_node *new_node(char *file_name)
{
	t_node *new_node;

	new_node = malloc(sizeof(t_node));
	new_node->data = file_name;
	new_node->left = NULL;
	new_node->right = NULL;
	return (new_node);
}

int main()
{
	// char *a = "output.txt";
	// char *b = "test_output.txt";
	// char *c = "libft";
	// char *d = "ans_output.txt";
	// char *e = "Main";
	// char *f = "ft_ls.h";
	// char *g = "main.c";
	// char *h = "a.out";

	ft_printf("%12s\n", "hello world", 213);
	// t_tree *tree;
	// t_node *n1 = new_node(a);
	// t_node *n2 = new_node(b);
	// t_node *n3 = new_node(c);
	// t_node *n4 = new_node(d);
	// t_node *n5 = new_node(e);
	// t_node *n6 = new_node(f);
	// t_node *n7 = new_node(g);
	// t_node *n8 = new_node(h);
	// init_tree(&tree, n1);
	// tree->root = addnode_tree(tree->root, n2);
	// tree->root = addnode_tree(tree->root, n3);
	// tree->root = addnode_tree(tree->root, n4);
	// tree->root = addnode_tree(tree->root, n5);
	// tree->root = addnode_tree(tree->root, n6);
	// tree->root = addnode_tree(tree->root, n7);
	// tree->root = addnode_tree(tree->root, n8);

	
	// print_inorder_tree(tree->root);
	// // system("leaks a.out");
	return 0;
}