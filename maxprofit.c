/*
 * Find the buying and selling dates which can make the maximum profit
 * for a sequence of days of stocks.
 *
 * Tutorial: TUT105
 *
 */ 
#include <stdio.h>
#include <assert.h>

/*
 * We want to find out the values which generates the maximum profits from
 * a set of stock quotes from a date range.
 *
 */

	void
find_max_profit_ranges(int *ranges, int rangelength, int * low , int *high)
{
	int count,minimum_seen_so_far, minimum_associated_with_profit,maximum_asociated_with_profit,profit;

	assert(low && high);

	minimum_seen_so_far = minimum_associated_with_profit = maximum_asociated_with_profit = ranges[0];
	profit = 0;

	for (count = 1; count < rangelength; ++count) {
		if ((ranges[count] - minimum_seen_so_far) > profit) {
			minimum_associated_with_profit = minimum_seen_so_far;
			profit = ranges[count] - minimum_seen_so_far;
			maximum_asociated_with_profit = ranges[count];
		}
		if (ranges[count] < minimum_seen_so_far) {
			minimum_seen_so_far = ranges[count];
		}
		//printf("\n min %d profit %d",minimum_seen_so_far,profit);
	}

	*low = minimum_associated_with_profit;
	*high = maximum_asociated_with_profit;
	printf("\n Profit = %d ", profit);
}

	int
main(char **argv, int argc)
{
	int data[]={5,0,12,1,1,13,9,6};
	int low, high;
	find_max_profit_ranges(data,sizeof(data)/sizeof(data[0]),&low,&high);
	printf("\n low %d high %d", low , high);
	return 0;
}
