
#include "ft_ls.h"

void print_in_tree(t_tree *tree)
{

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
	char *a = "hello";
	char *b = "test_output.txt";
	char *c = "libft";
	char *d = "ans_output.txt";
	char *e = "Main";
	char *f = "ft_ls.h";
	char *g = "main.c";
	char *h = "a.out";

	t_tree *tree;
	t_node *n1 = new_node(a);
	t_node *n2 = new_node(b);
	t_node *n3 = new_node(c);
	t_node *n4 = new_node(d);
	t_node *n5 = new_node(e);
	t_node *n6 = new_node(f);
	t_node *n7 = new_node(g);
	t_node *n8 = new_node(h);
	init_tree(&tree, n1);
	tree->root = addnode_tree(tree->root, n2);
	tree->root = addnode_tree(tree->root, n4);

	ft_printf("tree root is %s\n", tree->root->data);

	ft_printf("tree left is %s\n", tree->root->left->data);
	ft_printf("tree right is %s\n", tree->root->right->data);

}