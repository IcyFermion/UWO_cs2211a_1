
#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

BStree bstree_ini(int size) {

	// dynamically allocate memory of type BStree_struct
	BStree bst = (BStree)malloc(sizeof(BStree_struct));

	// allocate memory for a Node array of size+1 for member tree_nodes
	bst->tree_nodes = (Node*)malloc(sizeof(Node) * (size + 1));

	// allocate memory for an unsigned int array of size+1 for member free_nodes
	bst->free_nodes = (unsigned int*)malloc(sizeof(unsigned int) * (size + 1));

	bst->size = size;

	// set entry free_nodes[i] to i
	int i;
	for (i = 0; i < (size + 1); i++)
	{
		bst->free_nodes[i] = (unsigned) i;
	}

	bst->top = 1;
	bst->root = 0;
	return bst;
}


void bstree_insert(BStree bst, Key* key, Data data) {

	Node n;
	n.key = key;
	n.data = data;
	new_node(bst, n, bst->top);

}

void new_node(BStree bst, Node node, int index) {
	if (index >= (*bst).size) {
		printf("Exceed the array bound\n");
		exit(-1);
	}
	else if (bst->free_nodes[index] != 0) {
		bst->tree_nodes[index] = node;
		bst->free_nodes[index] = 0;
	}
	else if (key_comp(bst->tree_nodes[index].key, node.key) == 0) {
		return;
	}
	else if (key_comp(bst->tree_nodes[index].key, node.key) > 0) {
		new_node(bst, node, index * 2);
	}
	else if (key_comp(bst->tree_nodes[index].key, node.key) < 0) {
		new_node(bst, node, index * 2 + 1);
	}

}


// Input: ’bst’: a binary search tree
// Effect: print all the nodes in bst using in order traversal
void bstree_traversal(BStree bst) {
	int position = bst->top;
	bstree_inorder(bst, position);

}

void bstree_inorder(BStree bst, int position) {

	if ((position) > bst->size)
	{
		printf("Exceed the array bound\n");
		return;
	}
	if (bst->free_nodes[position] != 0)
	{
		return;
	}
	// finds the smallest
	bstree_inorder(bst, position * 2);
	print_node(bst->tree_nodes[position]);
	bstree_inorder(bst, position * 2 + 1);
}


// Input: ’bst’: a binary search tree
// Effect: all dynamic memory used by bst are freed
void bstree_free(BStree bst) {
	free(bst->free_nodes);
	free(bst->tree_nodes);
	free(bst);
}