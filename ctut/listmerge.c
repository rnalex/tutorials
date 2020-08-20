#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/**
 * Definition for singly-linked list. */
struct ListNode {
     int val;
     struct ListNode *next;
 };

void show(struct ListNode * head)
{
  if (head == NULL) {
    printf("Empty");
  }
  while (head) {
    printf("\n %d ",head->val);
    head = head->next;
  }
}


#define APPEND_ONE(tail,newnode)  \
	do { \
		if (tail == NULL) { \
			tail = newnode; \
			newnode = newnode->next; tail->next = NULL; \
		} \
		else { \
			tail->next = newnode; \
			tail = newnode; \
			newnode = newnode->next; tail->next = NULL; \
		} \
	} \
	while(0);

#define APPEND_LIST(tail,newnode)  \
	do { \
		if (tail == NULL) { \
			tail = newnode; \
			newnode = newnode->next; \
		} \
		else { \
			tail->next = newnode; \
			tail = newnode; \
			newnode = newnode->next; \
		} \
	} \
	while(0);



struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
	struct ListNode * tl1=l1;
	struct ListNode * tl2=l2;
	struct ListNode * mlh=NULL, *mlt=NULL;
	while(tl1 || tl2) {
		if (tl1 && tl2) {
			if (tl1->val < tl2->val) {
				APPEND_ONE(mlt,tl1);
			}
			else {
				APPEND_ONE(mlt,tl2);
			}
			mlt->next = NULL;
		}
		else if (tl1) {
			APPEND_LIST(mlt,tl1);
			tl1=NULL;
		}
		else if (tl2) {
			APPEND_LIST(mlt,tl2);
			tl2 = NULL;
		}
		if (mlh == NULL) {
			mlh = mlt;
		}
	}
	return mlh;
}

struct ListNode N4={4,NULL};
struct ListNode N3={3,&N4};
struct ListNode N2={2,&N3};
struct ListNode N1={1,&N2};
struct ListNode N0={0,&N1};


struct ListNode N9={7,NULL};
struct ListNode N8={6,&N9};
struct ListNode N7={5,&N8};
struct ListNode N6={1,&N7};
struct ListNode N5={0,&N6};

int 
main(int argc, char **argv)
{
  struct ListNode * head = &N0 , *head1 = &N5;
  show(head);
  show(head1);
  show(mergeTwoLists(head,head1));
}

