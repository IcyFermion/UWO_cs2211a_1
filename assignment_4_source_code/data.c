
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"


Key* key_construct(char* in_name, int in_id) {

	//dynamically allocate memory to hold a Key
	Key* k;
	k = (Key*)malloc(sizeof(Key));
	k->id = in_id;


	//dynamically allocate memory for the Key’s name
	k->name = (char*)malloc(sizeof(char) * (strlen(in_name) + 1));
	strcpy(k -> name, in_name);

	return k;
}


int key_comp(Key* key1, Key* key2) {

	// if key1->name == key2->name, then compare key1->id with key2->id
	if (strcmp(key1->name, key2->name) == 0)
	{
		if (key1->id > key2->id) {
			return 1;
		}
		else if (key1->id == key2->id) {
			return  0;
		}
		else return -1;
	}
	else return strcmp(key1->name, key2->name);
}


void print_key(Key* key) {
	printf("(%-10s%10d)", key->name, key->id);
}


void print_node(Node node) {
	print_key(node.key);
	printf("%10d\n", node.data);
}

