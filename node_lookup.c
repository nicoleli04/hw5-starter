#include <string.h>
#include "node.h"

node *node_lookup(node *front, char *id) {

	while(front != NULL){
		if(strcmp(id, front->id) == 0){
			return front;
		}
		front = front->next;
	}
	// TODO: step through the chain pointed to by front
	// use function like strcmp to compare the id to the current node
	// if found return a pointer to the node, else return NULL


	return NULL; // TODO: fix this when you start implementation
}
