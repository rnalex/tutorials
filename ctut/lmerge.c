/*
 * RN Alex
 * Append 2 lists which are sorted.
 * Tutorial: TUT102
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct Node {
  struct Node * next;
  unsigned int data;
}Node;

struct Node A,B,C,D,E;
struct Node A1,B1,C1,D1,E1;

Node E = {NULL,25};
Node D = {&E,14};
Node C = {&D,8};
Node B = {&C,5};
Node A = {&B,1};
Node F1 = {NULL,30};
Node E1 = {&F1,27};
Node D1 = {&E1,22};
Node C1 = {&D1,13};
Node B1 = {&C1,4};
Node A1 = {&B1,1};

Node *l1 = &A;
Node *l2 = &A1;
Node *l3 = NULL;

void
show(Node * list)
{
	printf("\n--------------------------------------------");
	while(list) {
		printf("\n %d ", list->data);
		list = list->next;
	}
}
Node *
list_pop(Node **list)
{
	Node * node = NULL;
	if (list && *list) {
		node = *list;
		*list = (*list)->next;
	}
	return node;
}

void
list_append(Node **list, Node **list_end , Node *node)
{
	if (list == NULL || node == NULL) {
		return;
	}
	if (*list == NULL) {
		*list = *list_end = node;
		node->next=NULL;
	}
	else {
		(*list_end)->next = node;
		*list_end = node;
		node->next = NULL;
	}
		
}
void
sorted_merge(Node **list1 , Node **list2 ,Node **list3 )
{
	Node * list3_tail = NULL;

	while (*list1 && *list2) {
		if ((*list1)->data == (*list2)->data) {
			/* Remove both from respective list and add to list3 */
			list_append(list3, &list3_tail,list_pop(list1));
			list_append(list3, &list3_tail,list_pop(list2));
		}
		else if ((*list1)->data < (*list2)->data) {
			list_append(list3,&list3_tail,list_pop(list1));
		}
		else {
			list_append(list3,&list3_tail,list_pop(list2));
		}

	}

	if (*list1) {
		if (list3_tail) {
			list3_tail->next = *list1;
		} 
		else {
			list3_tail = *list1;
		}
		*list1 = NULL;
	}
	else if (*list2) {
		if (list3_tail) {
			list3_tail->next = *list2;
		}
		else {
			list3_tail = *list2;
		}
		*list2 = NULL;
	}
}

int
main(int argc , char **argv)
{
	show(l1);
	show(l2);
	sorted_merge(&l1,&l2,&l3);
	show(l3);
	return 0;
}
