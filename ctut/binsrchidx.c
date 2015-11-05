/*
 * Find the index of a entry in a sorted array
 * TUT113
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
int
find_index(int *array, int l , int r, int data)
{
	int ret=-1;
	if (l > r) return ret;
	else {
		int mid = l + (r-l)/2;
		if (array[mid] == data) return mid;
		else if (array[mid] > data) return find_index(array,l,mid-1,data);
		else return find_index(array,mid+1,r,data);
	}
	return -1;
}
int 
find_index_iterative(int *array, int l , int r, int data)
{
	int ret=-1;
	if (l > r ) return ret;
	else {
		while (l <= r ) {
			int mid = l + (r-l)/2;
			//printf("\n %d %d %d %d %d", l, mid, r, data,array[mid]);
			if ((l == r) && array[mid]!=data) return -1;
			if (array[mid] == data) return mid;
			else if (array[mid] > data) {
				r = mid - 1;
			}	
			else  l = mid +1; 
		}
	}
}

int test_array[10]={1,2,3,4,5,6,7,8,9,10};

int
main(int argc, char **argv)
{
	int i,j;
	for(i=0;i<=9;++i) {
		for(j=0;j < (i-1);++j) {
			assert(find_index(test_array,i-j,i,i+1) == i);
			//printf("\n%d %d %d = %d ",i-j,i,i+1,find_index(test_array,i-j,i,i+1));
			//printf("\n%d %d %d = %d ",i-j,i,i+1,find_index_iterative(test_array,i-j,i,i+1));
			assert(find_index_iterative(test_array,i-j,i,i+1) == i);
		}
	}
	printf("\nFind index %d ", find_index(test_array,0,9,8));
	return 0;

}
