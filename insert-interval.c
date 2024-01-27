**Insert Interval**

Problem Statement 51) You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.

Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

Return intervals after the insertion.

 

Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
 

Constraints:

0 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 105
intervals is sorted by starti in ascending order.
newInterval.length == 2
0 <= start <= end <= 105

--------------------------------------------------------------------------------------------------------------------
SOLUTION = #include <stdbool.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void pushinterval(int** ans, int* retsize, int** retcolsizes, int lo, int hi) {
    ans[*retsize] = malloc(2 * sizeof(int));
    ans[*retsize][0] = lo;
    ans[*retsize][1] = hi;
    *((*retcolsizes) + *retsize) = 2;
    *retsize = *retsize + 1;
}

int** insert(int** intervals, int intervalsSize, int* intervalsColSize, int* newInterval, int newIntervalSize, int* returnSize, int** returnColumnSizes){
    int** ans = malloc((intervalsSize+1) * sizeof(int*));
    *returnColumnSizes = malloc((intervalsSize+1) * sizeof(int));
    
    *returnSize = 0;

    for (int i = 0; i < intervalsSize; ++i) {
        int lo = intervals[i][0];
        int hi = intervals[i][1];

        if (newInterval[1] < lo) {
            pushinterval(ans, returnSize, returnColumnSizes, newInterval[0], newInterval[1]);
            newInterval = intervals[i];
        } else if (newInterval[0] > hi) {
            pushinterval(ans, returnSize, returnColumnSizes, lo, hi);
        } else {
            if (lo < newInterval[0]) {
                newInterval[0] = lo;
            }
            if (hi > newInterval[1]) {
                newInterval[1] = hi;
            }
        }
    }
    pushinterval(ans, returnSize, returnColumnSizes, newInterval[0], newInterval[1]);
    return ans;
}

------------------------------Explanation :- 
Purpose:

This code inserts a new interval (newInterval) into a sorted array of intervals (intervals), merging overlapping intervals as needed, and returns the new array with the inserted interval.
Function Breakdown:

pushinterval Function:

Helper function to add a new interval to the result array (ans):
Allocates memory for the interval.
Sets its start and end values.
Sets the column size for the interval.
Increments retsize to track the number of intervals added.
insert Function:

Initialization:

Allocates memory for the return array (ans) and column size array (returnColumnSizes).
Sets *returnSize to 0.
Iterating and Merging:

Iterates through intervals:
If newInterval ends before the current interval starts:
Adds newInterval to ans using pushinterval.
Sets newInterval to the current interval for potential merging later.
If newInterval starts after the current interval ends:
Adds the current interval to ans using pushinterval.
Otherwise (overlap):
Merges newInterval with the current interval by updating newInterval's start and end values.
Adding Remaining Interval:

Adds the potentially merged newInterval to ans using pushinterval.
Return New Array:

Returns ans containing the merged intervals with the inserted interval.
Key Points:

Sorting Assumption: Assumes intervals is sorted by start values.
Overlap Handling: Merges overlapping intervals by updating the start and end values of newInterval.
Memory Allocation: Allocates memory for the return array and column size array.
pushinterval Helper: Simplifies adding intervals to the result array.
Time Complexity: O(n), where n is the number of intervals, due to linear iteration.
Space Complexity: O(n) for the return array and temporary variables.
