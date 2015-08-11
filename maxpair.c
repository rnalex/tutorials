/*
 * Author: RN Alex
 * TUT106
 * Find all the pairs which can add up to a given number
 * k in a sorted list.
 *
 */
#include <stdio.h>
#include <assert.h>
	void
show_buf(int *buf, int buflen)
{
	int *bufp = buf;
	while(bufp < buf + buflen) {
		printf("\n %d ", *bufp);
		bufp++;
	}
}
	int
find_pair(int * buf , int buflen, int *first_pair , int *second_pair , int total)
{
	int i , j , solution, retval;

	i =0 ; j = buflen -1;
	retval = -1;

	while( i < j  && i >= 0 &&  j < buflen) {
		solution = buf[i]+buf[j];
		if (solution == total) {
			*first_pair = i;
			*second_pair = j;
			printf("\n Total %d = [%d + %d]",total,buf[i],buf[j]);
			++i;
			--j;
		}
		else if (solution > total) {
			--j;
		}
		else if (solution < total) {
			++i;
		}
	}
}

int test_buf[]={ 0 , 2 , 3 , 9 , 12 , 18, 19};
int k = 12;
#define BUFLEN (sizeof(test_buf)/sizeof(test_buf[0]))

	int
main(int argc, char *argv) 
{
	int pair1=0,pair2=0;
	show_buf(test_buf, BUFLEN);
	printf("\n Pair for k = %d  - [ %d %d] - %s , ", k , pair1, pair2, find_pair(test_buf,BUFLEN,&pair1,&pair2,k)==-1?"Not fond": "found");
}


