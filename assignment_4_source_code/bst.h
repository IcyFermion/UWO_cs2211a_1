
#include "data.h"

typedef struct {
	Node* tree_nodes; unsigned int* free_nodes;
	int size; int top; int root;
} BStree_struct;
typedef BStree_struct* BStree;
BStree bstree_ini(int size);
void bstree_insert(BStree bst, Key* key, Data data);
void bstree_traversal(BStree bst);
void bstree_free(BStree bst);
void new_node(BStree bst, Node node, int index);
void bstree_inorder(BStree bst, int position);
