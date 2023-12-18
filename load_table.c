#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"

#define MAX_LINELEN 100 
#define FILE_OPEN_ERR_MSG "error in load_table while opening file %s\n"
#define DUPLICATE_ID_MSG "load_table duplicate entry: %s\n"
#define INSERTION_ERROR_MSG "load_table could not create node for %s\n"

int load_table(node **htable, unsigned long int table_size, char *filename) {

	if(filename == NULL){
		fprintf(stderr, FILE_OPEN_ERR_MSG, filename);
		return -1;
	}
	

	FILE* fp = fopen(filename, "r");
	if (fp == NULL){
		fprintf(stderr, FILE_OPEN_ERR_MSG, filename);
		fclose(fp);
		return -1;
	}
	// TODO: open the file and check that it was successful

	// TODO: loop through the file and read one line at a time using fgets
	// see manual page for fgets for information on parameters
	char buf[MAX_LINELEN + 1]; // input buffer for fgets
	while (fgets(buf, MAX_LINELEN + 1, fp) == buf) {
    char *id = strtok(buf, " , ");
    char* item = strtok(NULL, " , ");
    double cost = atof(strtok(NULL, " , "));

		unsigned long hash_code = hash(id) % table_size;
		node *front = htable[hash_code];
		node* new_node;

		if (node_lookup(front, id) != NULL){
			fprintf(stderr, DUPLICATE_ID_MSG, id);
		}
		else{
			if((new_node = insert_node(front, id, item, cost)) == NULL){
				fprintf(stderr, INSERTION_ERROR_MSG, id);
				return -1;
			}
		}
		htable[hash_code] = new_node;

	}
	fclose(fp);
	return 0;

}
