/*
 * TUT115
 * Find if there are matching parantheses in a string
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_STACK_SIZE 16

int stack_elements=0;
char stack[MAX_STACK_SIZE];

int
is_stack_empty()
{
	return (stack_elements == 0);
}

int 
is_stack_full()
{
	return (stack_elements == MAX_STACK_SIZE);
}

void
push(char *stack, char element)
{
	assert(stack && (!is_stack_full()));
	stack[stack_elements++] = element; 
}

char
pop(char *stack)
{
	assert(stack && (!is_stack_empty()));
	return stack[stack_elements--];
}

char
peek(char *stack)
{
	assert(!is_stack_empty(stack));
	return stack[stack_elements-1];
}

#define MAX_TOKENS 3
char lmatch[]={'{','(','['};
char rmatch[]={'}',')',']'};

int
is_member_of(char *str, char ch)
{
	int i;
	for(i=0; i < MAX_TOKENS;++i) {
		if (ch == str[i]) {
			return i;
		}
	}
	return -1;
}

int
is_matching_paran(char *str, char *lmatch , char *rmatch)
{

	assert(str);
	int len = strlen(str);
	int i=0;

	for (i=0; i < len; ++ i) {
		int ret = is_member_of(lmatch,str[i]);
		//printf("\n%c %d ",str[i],ret);
		if (ret  >= 0  ) {
			push(stack, str[i]);
		}
		else {
			ret = is_member_of(rmatch,str[i]);
			if (ret  >= 0 )  {
				if (!is_stack_empty(stack) && peek(stack) == lmatch[ret]) {
					pop(stack);
				}
				else return 0;
			}
		}
	}

	return is_stack_empty(stack);
}

int
main(int argc, char **argv)
{

	assert(is_stack_empty());
	push(stack,'A'); 
	push(stack,'B'); 

	assert(stack_elements == 2);
	printf("\n %c ",peek(stack));
	pop(stack);

	printf("\n %c ",peek(stack));
	pop(stack);
	assert(is_stack_empty());

	char str[]="1+2*(1+3){12-4}";
	assert(is_matching_paran(str,lmatch,rmatch));

	char str1[]="1+2*((1+3){12-4}";
	assert(!is_matching_paran(str1,lmatch,rmatch));

	char str2[]="1+2*(1+3){12-4}}";
	assert(!is_matching_paran(str2,lmatch,rmatch));
}
