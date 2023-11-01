#ifndef _NODE_H
#define _NODE_H

typedef struct node {
	char *id;
	char *purchased_item;
	double cost;
	struct node *next;
} node;

extern node *node_lookup(node *front, char *id);
extern node *insert_node(node *front, char *id, char *purchased_item, double cost);
extern int load_table(node **htable, unsigned long tablesize, char *filename);
extern unsigned long hash(char *id);
extern void delete_table(node **htable, unsigned long tablesize);
extern void print_info(node **htable, unsigned long tablesize);

#endif
