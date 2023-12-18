#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "node.h"

#define MAX_QUERY_LEN 100
#define MIN_TABLE_SIZE 3
#define DEFAULT_TABLE_SIZE 1873
#define QUERY_SUCCESS_FORMAT "found sale id=%s, purchased_item=%s, cost=%.5f\n" 
#define QUERY_FAILURE_FORMAT "could not find sale with id=%s\n"
#define USAGE_STRING "%s [-s] [-t table_size] <filename>\n"

int main(int argc, char **argv) {
	int s_flag;
	unsigned long table_size = DEFAULT_TABLE_SIZE;

	int c;
	char *ptr;
    /* TODO: fill out this skeleton code calling getopt */
    while ((c = getopt(argc, argv, "st:")) != -1) {
       switch (c) {
        case 's':
            s_flag = 1;
            break;
	   	 case 't':
	        table_size = strtoul(optarg, &ptr, 10);
					if (table_size < MIN_TABLE_SIZE){
						table_size = DEFAULT_TABLE_SIZE;
					}
	        break;
       default:
            fprintf(stderr, USAGE_STRING, *argv);
            return EXIT_FAILURE;
      }
    }


	// TODO: parse opts with getopt and initialize these variables 
	// (see strtoul for parsing unsigned long)
	// handle any bad inputs (missing filename or invalid option flag
	// by printing out the USAGE_STRING to stderr and exiting with failure:

	// fprintf(stderr, USAGE_STRING, argv[0]); // you can use this line

	
	// TODO: initialze htable
	// using calloc so all buckets are initialized to NULL
	node **htable = calloc(table_size, sizeof(node*));
	if (htable == NULL) {
		return EXIT_FAILURE;
	}
	
	// TODO: get filename and call load_table;
	
	char *filename = argv[optind];
  
	if (load_table(htable, table_size, filename) != 0) {
		fprintf(stderr, "error in load_table\n");
		delete_table(htable, table_size);
		return -1;
	}
	
	char query[MAX_QUERY_LEN + 1]; 
	char *end;
	int number_success = 0;
	// read one line at a time from stdin, do a lookup for that id
	// 
	while (fgets(query, MAX_QUERY_LEN + 1, stdin) == query) {
		// replace the \n, if it exists (for hashing)
		if ((end = strchr(query, '\n'))) *end = '\0'; // don't change this line
		char* id = strtok(query, " , ");
		unsigned long hash_code = hash(id) % table_size;

		node* query_node = node_lookup(htable[hash_code], id);
		if(query_node != NULL){
			fprintf(stdout, QUERY_SUCCESS_FORMAT,query_node->id, query_node->purchased_item, query_node->cost );
			number_success +=1;

		}
		else{
			fprintf(stdout, QUERY_FAILURE_FORMAT, id);
		}
		// TODO: read a line from stdin and perform a lookup
		// if the sale is found, print its contents to stdout
		// using QUERY_SUCCESS_FORMAT
		//
		// if the sale is not found, print a message to **stdout**
		// using QUERY_FAILURE_FORMAT
		//
		// keep track of the number of successful queries
	}
	printf("%d successful queries\n", number_success);

	// if -s called then print stats
	if (s_flag == 1) {
		print_info(htable, table_size);
	}

	delete_table(htable, table_size);
	// TODO: free all allocated memory associated with the table 
	// using delete_table()
	//
	
	return EXIT_SUCCESS;
}



