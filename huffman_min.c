#include<stdio.h>
#include<stdlib.h>
#include"huffman_min.h"

int main()
{
	int count;
	BTNode *temp_ptr, *temp;

	get_symbol_count();

	for(count = 0; count < symbol_count; count++)
	{
		if(count == 0)
		{
			head_ptr = getNode();
			insert_data(head_ptr);
			head_ptr -> number = count+1;
			/* Making Another Copy To Build Tree */
			new_head_ptr = getNode();
			new_head_ptr -> problty = head_ptr -> problty;
			new_head_ptr -> number = head_ptr -> number;
		}
		else
		{
			temp_ptr = getNode();
			insert_data(temp_ptr);
			temp_ptr -> number = count+1;
			arrange(temp_ptr,head_ptr);
			/* Making Another Copy To Build Tree */
			temp = getNode();
			temp -> problty = temp_ptr -> problty;
			temp -> number = temp_ptr -> number;
			arrange(temp,new_head_ptr);
		}
	}

	traverse(new_head_ptr);

	printf("Building Huffman Tree.\n");
	build_heap(new_head_ptr);
	for(count = 0; count < symbol_count; count++)
		traverse_tree(root);
	/* Done !*/
	return (0);
}


/*
   Function Definitions.
   */

void get_symbol_count()
{
	printf("Enter Symbol Count.\n");
	scanf("%d",&symbol_count);
}

BTNode * getNode()
{
	BTNode * temp;
	temp = (BTNode *)malloc(sizeof(BTNode));
	if(!temp)
	{
		printf("\nNot Enough Memory.");
		exit(-1);
	}
	else
	{
		temp -> prev = NULL;
		temp -> next = NULL;
		temp -> left = NULL;
		temp -> right = NULL;
		temp -> visited = 0;
		return temp;
	}
}

void insert_data(BTNode *node_ptr)
{
	printf("\nEnter Probability Of Symbol\t");
	scanf("%f",&node_ptr->problty);
}

void traverse(BTNode *temp)
{
	if(!temp->prev)
		printf("\tStart of The List.\n");
	printf("Probability of Symbol %d is %f\n",temp->number,temp->problty);
	if(!temp->next)
	{
		printf("\tEnd Of The List.\n");
		return;
	}
	else
		traverse(temp->next);
}

void show(BTNode *temp)
{
	fflush(stdin);
	printf("Node Probability is: %f\n",temp->problty);
	/*	if(temp->prev)
		printf("Previous Node Exists.\n");
		if(temp->next)
		printf("Next Node Exists.\n");
		*/
}


void mark_visited(BTNode * this_node)
{
	BTNode *child_l, *child_r;
	child_l = this_node -> left;
	child_r = this_node -> right;
	if(child_l->visited == 1 && child_r->visited == 1)
	{
		this_node->visited = 1;
		return;
	}
	/*	else
		{
		if(child_l->visited != 1)
		mark_visited(child_l);
		if(child_r->visited != 1)
		mark_visited(child_r);
		}
		*/

}

void traverse_tree(BTNode *this_node)
{
	BTNode *child_l, *child_r;
	child_l = this_node -> left;
	child_r = this_node -> right;
	if(this_node -> visited == 1)
	{
		return;	
	}
	if(child_l == NULL && child_r == NULL)
	{
		printf("\t is code for the symbol number %d with prob. %.3f\n",
				this_node->number,this_node->problty);
		this_node -> visited = 1;
		return;
	}
	if(child_l -> visited != 1)
	{
		printf("1");
		traverse_tree(child_l);
		mark_visited(this_node);
		return;
	}
	if(child_r -> visited !=1)
	{
		printf("0");
		traverse_tree(child_r);
		mark_visited(this_node);
		return;
	}
}


// build_heap function definition.
void build_heap(BTNode * new_head)
{
	BTNode *first, *second, *temp;

	//	printf("\nReached Here.\n");
	while(new_head_ptr->next)
	{

		first = new_head_ptr;
		/*	if(first)
			show(first);
			*/
		second = new_head_ptr -> next;
		/*	if(second)
			show(second);
			*/
		temp = getNode();
		temp -> problty = first -> problty + second -> problty;
		temp -> left = first;
		temp -> right = second;
		/*
		   if(new_head_ptr)
		   show(new_head_ptr);
		   */
		/*	if(!new_head_ptr)
			{
			root = temp;
			return;
			}
			*/
		arrange(temp,new_head_ptr);
		new_head_ptr = second -> next;
	}
	root = temp;
}


void arrange(BTNode *swap_ptr, BTNode *head)
{
	BTNode * temp, *next_node;
	temp = head;
	if(swap_ptr -> problty < head -> problty)
	{
		swap_ptr -> next = head;
		head -> prev = swap_ptr;
		if(head == head_ptr)
			head_ptr = swap_ptr;
		else if(head == new_head_ptr)
			new_head_ptr = swap_ptr;
	}
	if(swap_ptr -> problty >= head -> problty)
	{
		while(swap_ptr->problty >= temp->problty)
		{
			next_node = temp->next;
			if(next_node == NULL || next_node->problty > swap_ptr->problty)
				break;
			temp = next_node;
		}
		if(next_node != NULL)
		{
			swap_ptr -> prev = temp;
			swap_ptr -> next = next_node;
			next_node -> prev = swap_ptr;
			temp -> next = swap_ptr;
		}
		else if(next_node == NULL)
		{
			temp -> next = swap_ptr;
			swap_ptr -> prev = temp;
		}
	}
}
