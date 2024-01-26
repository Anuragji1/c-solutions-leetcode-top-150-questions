**Longest Consecutive Sequence**longest-consecutive-sequence

Problem Statemnet 48) Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

 

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109

----------------------------------------------------------------------------------------------------------------------
SOLUTION = int comp (const void* a, const void*b) {
    return *(int*)a  - *(int*)b;
}

int longestConsecutive(int* nums, int numsSize){
    
    if (numsSize == 0)
        return 0;
    qsort (nums, numsSize, sizeof(int), comp);

    int max = 1;
    int temp = 1;
    int i = 0;
    while (i < numsSize -1) {
        while (i < numsSize -1 && nums[i+1] == nums[i]+1){
            temp ++;
            i++;
        }
        if (temp > max)
            max = temp;
        if (i < numsSize -1 && nums[i] == nums[i+1])
            i++;
        else {
            temp = 1;
            i++;
        }
    }
    
    return max;
}

---------------------------Explanation :-
Purpose:

This code finds the length of the longest consecutive sequence (consecutive numbers in increasing order) within an array nums.
Function Breakdown:

comp Function:

Comparison function for sorting integers in ascending order, used by qsort.
longestConsecutive Function:

Handling Empty Array:

Returns 0 if numsSize is 0.
Sorting:

Sorts nums in ascending order using qsort and comp.
Finding Consecutive Sequences:

Initializes max to 1 (minimum length) and temp to 1 (current sequence length).
Iterates through nums using i:
Inner while loop: Extends the current sequence as long as consecutive elements are found:
Increments temp and i for each consecutive element.
Updates max if the current sequence is longer.
Skips duplicates using if (i < numsSize - 1 && nums[i] == nums[i+1]).
Resets temp to 1 for a new sequence and increments i.
Return Longest Sequence Length:

Returns max, representing the length of the longest consecutive sequence.
Key Points:

Sorting for Efficiency: Sorts the array to efficiently identify consecutive sequences.
Single Iteration: Finds the longest sequence in a single pass after sorting.
Time Complexity: O(n log n) due to sorting, where n is the array size.
Space Complexity: O(1), using constant extra space.
