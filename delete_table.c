#include <stdlib.h>
#include "node.h"

void delete_table(node **htable, unsigned long table_size) {

	for(unsigned long i = 0; i <table_size; i++){
		node* temp_node;
		node* current_node = htable[i];
		while(current_node != NULL){
			temp_node = current_node;
			current_node = temp_node->next;
			free(temp_node->id);
			temp_node->id = NULL;
			free(temp_node->purchased_item);
			temp_node->purchased_item = NULL;
			temp_node->next = NULL;
			free(temp_node);
			temp_node = NULL;
		}
	}
	// TODO: walk through the chains in table
	//
	// TODO: free all the memory associated to each node in each chain
	//
	// TODO: free the entire table

	free(htable);
	htable= NULL; // suppress unused variable warnings
	 // TODO: delete these once you start implementation
}
