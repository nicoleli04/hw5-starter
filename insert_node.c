#include <stdlib.h>
#include <string.h>
#include "node.h"

node *insert_node(node *front, char *id, char *purchased_item, double cost) {
	
	node* new_node = (node*) malloc(sizeof(node));

	if(new_node == NULL){
		return NULL;
	}

	new_node->id = (char*)malloc(strlen(id)+1);

	if(new_node->id == NULL){
		free(new_node);
		return NULL;
	}
	strcpy(new_node->id, id);
	new_node->purchased_item = (char*)malloc(strlen(purchased_item)+1);

	if(new_node->purchased_item == NULL){
		free(new_node->id);
		free(new_node);
		return NULL;
	}
	
	strcpy(new_node->purchased_item, purchased_item);
	new_node->cost = cost;

	new_node->next = front;

	// TODO: create a node, copy in the parameter fields
	// make sure that you do a deep copy
	
	// TODO: link the new node into the chain 

	// TODO: return the new head of the chain if the function succeeded
	
	return new_node; // TODO: replace this once you implement
}


