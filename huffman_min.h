#ifndef HUFFMIN_H
#define HUFFMIN_H
typedef struct btNode
{
	/* Binary Tree Node Structure. */
	struct btNode *left;
	struct btNode *prev;
	float problty;
	int number;
	int visited;
	struct btNode *next;
	struct btNode *right;
}BTNode;

BTNode *head_ptr, *new_head_ptr, *root;

/*Print Author Data */
void print_data();

/*Number Of Input Symbols */
int symbol_count;

/* Get The Symbol Count From User.*/
void get_symbol_count();

/*Dynamically Create A New Binary Node. */
BTNode * getNode();

/* Assign The User Input Data to Newly Created Data.*/
void insert_data(BTNode *);

/* Traverse The Linked List.
 * Printing The Value at Node Visited.
 */
void traverse(BTNode *);

/*Find the place for the newly created Node. */
void arrange(BTNode *, BTNode *);


/* Start Building Binary Heap*/
void build_heap(BTNode *);

void show(BTNode *);

/* Traverse Tree to Get The Huffman Codes.*/
void traverse_tree(BTNode *);

/* Mark Visited Internal Node.*/
void mark_visited(BTNode *);

#endif /* HUFFMIN_H*/
