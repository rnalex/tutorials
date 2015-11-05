/* Author: RN Alex
 * Tutorial TUT114
 *
 * Find the median of 2 lists which are sorted.
 * Partion the list into 4 parts by comaring the
 * middle of the two lists. We can eliminate n/2
 * of the elements which are too low and too high
 * Now the solution space reduces to n/2 and 2 lists
 * Recursively solving this will get to the median.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

unsigned int ll1[]={2,4,6,9,10,11,14,19};
unsigned int ll2[]={1,5,7,11,12,13,15,20};
/* 1 2 4 5 6 7 9 10 11 12 13 14 15 19 20 */

#define MID(l,r) (l+(r-l)/2)

int
mid_element(unsigned int *ll, int left , int right)
{
        return (ll1[MID(left,right)]);
}
int
find_median(unsigned int *l1,int l1l,int l1r, unsigned int *l2, int l2l, int l2r)
{

        if (mid_element(l1,l1l,l1r) == mid_element(l2,l2l,l2r)) {
                return mid_element(l1,l1l,l1r);
        }
        else if (mid_element(l1,l1l,l1r) < mid_element(l2,l2l,l2r)) {
                return find_median(l1,MID(l1l,l1r),l1r,l2,l2l,MID(l2l,l2r));
        }
        else {
                return find_median(l1,l1l,MID(l1l,l1r),l2,MID(l2l,l2r),l2r);

        }

}

int
main(int argc , char **argv)
{
	int i=0;
	for(i=0;i<8;++i) {
		printf("\n median = %d",find_median(ll1,0,i,ll2,0,i));
	}
	return 0;
}

