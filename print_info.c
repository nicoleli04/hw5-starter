#include <stdio.h>
#include <limits.h>
#include "node.h"

#define TABLESIZE_MSG "Table size: %lu\n"
#define TOTAL_ENTRIES_MSG "Total entries: %lu\n"
#define LONGEST_MSG "Longest chain: %lu\n"
#define SHORTEST_MSG "Shortest chain: %lu\n"
#define EMPTY_MSG "Empty buckets: %lu\n"

void print_info(node **htable, unsigned long table_size) {

	unsigned long total_entries = 0;
	unsigned long longest_chain = 0;
	unsigned long shortest_chain = ULONG_MAX;
	unsigned long empty_buckets = 0;

	for(unsigned long i = 0; i < table_size; i++){
		unsigned chain_length = 0;
		node* front = htable[i];
		while(front != NULL){
			total_entries += 1;
			chain_length +=1;
			front = front->next;
			if(front == NULL){
				break;
			}

		}
		if (chain_length > longest_chain){
			longest_chain = chain_length;
		}
		if (chain_length < shortest_chain){
			shortest_chain = chain_length;
		}
		if (chain_length == 0){
			empty_buckets +=1;
		}
		
	}
	  fprintf(stdout, TABLESIZE_MSG, table_size);
		fprintf(stdout, TOTAL_ENTRIES_MSG, total_entries);
		fprintf(stdout, LONGEST_MSG, longest_chain);
		fprintf(stdout, SHORTEST_MSG, shortest_chain);
		fprintf(stdout, EMPTY_MSG, empty_buckets);
	// TODO: walk down the indices of the htable
	// iterate through each chain and update statistics
	// print out statistics at end
	//
	// NOTE: all your statistics variables should be of type
	// unsigned long
	//
	// NOTE: you may use ULONG_MAX if you want
	// (maximum value for unsigned long int)
	
}
