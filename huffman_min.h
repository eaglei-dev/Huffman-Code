/*    Simple Huffman Code Generator.
 *    Copyright (C) 2016, eaglei-dev
 *
 *    This program is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *    You should have received a copy of the GNU General Public License
 *    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef HUFFMIN_H
#define HUFFMIN_H
typedef struct btNode
{
	/* Node Structure. */
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

/*Dynamically Create A New Node. */
BTNode * getNode();

/* Assign The User Input Data to Newly Created Data.*/
void insert_data(BTNode *);

/* Traverse The Linked List.
 * Printing The Value at Node Visited.
 */
void traverse(BTNode *);

/*Find the place for the newly created Node. */
void arrange(BTNode *, BTNode *);


/* Start Building Heap*/
void build_heap(BTNode *);

void show(BTNode *);

/* Traverse Tree to Get The Huffman Codes.*/
void traverse_tree(BTNode *);

/* Mark Visited Internal Node.*/
void mark_visited(BTNode *);

#endif /* HUFFMIN_H*/
