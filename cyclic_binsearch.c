/*
 * TUT111
 * Given a cyclic sorted array how would you find
 * the smallest or the largest elements.
 * 
 * Solution: Either the array is sorted or has 
 * a half which is sorted and other half which is unsorted.
 * If it is sorted return the largest element
 * If it is unsorted compare the greatest element from the 
 * sorted half to the unsorted half.
 *
 * lowest would be array[highest index +1 % array_size]
 *
 */
#include <stdio.h>
#include <assert.h>

#define MID(l,r) (l+((r-l)/2))

int test_array[10]={18,9,10,11,12,13,14,15,16,17};

/*
 * Either the array is sorted or
 * either half of the array is sorted
 * Compare the greatest elements in 
 * the sorted array with the unsorted one.
 */

int
greatest(int *array, int l , int r)
{
	int g1,g2;

	assert(l<=r);
	printf("\n %d - %d",l,r);
	/* Sorted arrays has greatest elements at the right*/
	if (array[l] <= array[r]) return array[r];

	/*If the midpoint is > l the left half is sorted - compare the right half*/
	if (array[MID(l,r)] > array[l]) {
		g1 = array[MID(l,r)];
		g2 = greatest(array,MID(l,r)+1,r);
		return (g1 > g2 ? g1 : g2);
	}
	/* If the midpoint is < l the left half is unsorted - compare the right half*/
	else {
		g1 = array[r];
		g2 = greatest(array,l,MID(l,r));
		return (g1 > g2 ? g1 : g2);
	}
}

int
main(int argc, char **argv)
{
	printf("\nGreatest %d ", greatest(test_array,0,1));	
	printf("\nGreatest %d ", greatest(test_array,1,9));	
	printf("\nGreatest %d ", greatest(test_array,0,9));	
	return 0;
}
