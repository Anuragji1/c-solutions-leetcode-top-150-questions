**Merge Intervals**

Problem Statement 50) Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 

Constraints:

1 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 104

----------------------------------------------------------------------------------------------------------------------
SOLUTION = /**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int asscending(const void* nums1, const void* nums2){
    if(((int**)nums1)[0][0] == ((int**)nums2)[0][0]){
        return ((int**)nums1)[0][1] - ((int**)nums2)[0][1];
    }
    return ((int**)nums1)[0][0] - ((int**)nums2)[0][0];
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
*returnSize =0;
if(intervalsSize == 0){return NULL;}
//perform quick sort on the given array 
qsort(intervals,intervalsSize,sizeof(intervals[0]),asscending);
//we will declare return array 
int** return_array = (int**)malloc(sizeof(int*)*intervalsSize);
int* return_array_ele = NULL;
int trip_cond =0;
//we will iterate the entrie sequnce of array to find out the slots which are overlapping
for(int idx =0 ;idx < intervalsSize; idx++){
    //condtion to consider if we are searching for the first time 
    //or there is discontinuation in the determination of the 
    //consequent array sequence elements
    if(trip_cond == 0){
        return_array_ele = intervals[idx];
        trip_cond = 1;
        continue;
    }
    //condtion to check the continutiot of the array elements
    if(return_array_ele[0] <= intervals[idx][0] && return_array_ele[1] >= intervals[idx][0]){
        return_array_ele[1] = return_array_ele[1] > intervals[idx][1] ? return_array_ele[1] : intervals[idx][1];
    }
    else{
        return_array[(*returnSize)++] = return_array_ele;
        trip_cond =0;
        idx--;
    }
}

return_array[(*returnSize)++] = return_array_ele;
//we need to now intialize the columnsizes data 
returnColumnSizes[0] = (int*)malloc(sizeof(int)*(*returnSize));
for(int idx =0 ; idx < (*returnSize); idx++){
    returnColumnSizes[0][idx] = 2;
}
return return_array;
}

-------------------------------Explanation :-
Purpose:

This code merges overlapping intervals within a 2D array of intervals (intervals) and returns a new array with the merged intervals.
Function Breakdown:

asscending Function:

Compares two intervals for sorting in ascending order, prioritizing start values and then end values.
merge Function:

Initialization:

Sets *returnSize to 0 for tracking the size of the merged array.
Handles empty input: returns NULL.
Sorts intervals in ascending order using qsort and asscending.
Allocates memory for the return array (return_array) and a temporary element pointer (return_array_ele).
Sets a flag trip_cond for tracking merging progress.
Iterating and Merging:

Iterates through intervals:
If trip_cond is 0 (starting a new merged interval):
Sets return_array_ele to the current interval.
Sets trip_cond to 1.
If the current interval overlaps with return_array_ele:
Merges them by updating return_array_ele[1] to the larger end value.
Otherwise:
Adds return_array_ele to return_array.
Resets trip_cond to 0 for the next interval.
Decrements idx to re-check the current interval for merging.
Handling Last Interval:

Adds the last merged interval to return_array.
Setting Column Sizes:

Allocates memory for returnColumnSizes[0] to store column sizes.
Sets all column sizes to 2 (each interval has two elements).
Return Merged Array:

Returns return_array containing the merged intervals.
Key Points:

Sorting for Efficiency: Sorts intervals for efficient merging.
Overlap Detection: Uses two pointers and conditions to detect overlapping intervals.
Merging Logic: Merges overlapping intervals by updating the end value of the first interval.
Memory Allocation: Allocates memory for the return array and column size array.
Time Complexity: O(n log n) due to sorting, where n is the number of intervals.
Space Complexity: O(n) for the return array and temporary variables.
