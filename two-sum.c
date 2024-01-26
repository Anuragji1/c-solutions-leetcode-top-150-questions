**Two Sum**

Problem Statemnet 45) Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
 

Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.

-------------------------------------------------------------------------------------------------------------------------------
  SOLUTION = /**
 * Note: The returned array must be malloced, assume caller calls free().
 */

struct intPair {
    int x;
    int order;
};

int compare(const void *a, const void *b) {
    struct intPair *p = (struct intPair *) a;
    struct intPair *q = (struct intPair *) b;
    return p->x - q->x;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i, j, *output;
    output = malloc(2 * sizeof(int));
    *returnSize = 2;
    struct intPair *arr = malloc(numsSize * sizeof(struct intPair));
    for (i = 0; i < numsSize; ++i) {
        arr[i].x = nums[i];
        arr[i].order = i;
    }
    qsort(arr, numsSize, sizeof(struct intPair), compare);
    i = 0;
    j = numsSize - 1;
    while (arr[i].x + arr[j].x != target) {
        while (arr[i].x + arr[j].x < target) {
            ++i;
        }
        while (arr[i].x + arr[j].x > target) {
            --j;
        }
    }
    output[0] = arr[i].order;
    output[1] = arr[j].order;
    free(arr);
    return output;
}

----------------------------------Explanation:-
  Purpose:

This code finds the indices of two numbers within a given array nums that add up to a specific target value.
Function Breakdown:

Structure and Comparison Function:

intPair structure stores an integer x and its original index order.
compare function compares two intPair structures based on their x values, used for sorting.
twoSum Function:

Initialization:

Allocate memory for the output array output to store the two indices.
Allocate memory for arr to store intPair elements, preserving original indices.
Fill arr with values and indices from nums.
Sorting:

Sort arr based on x values using qsort and the compare function.
Two Pointer Approach:

Use two pointers, i and j, starting at the beginning and end of the sorted arr:
While arr[i].x + arr[j].x != target:
If the sum is less than target, move i to the right to increase the sum.
If the sum is greater than target, move j to the left to decrease the sum.
Find and Return Indices:

Once the target sum is found, store the original indices from arr[i].order and arr[j].order into output.
Free the allocated memory for arr.
Return output containing the indices of the two numbers that sum to target.
Key Points:

Sorting and Two Pointers: Combines sorting with the two-pointer technique for efficient searching.
Preserving Indices: Uses intPair to maintain original indices after sorting.
Time Complexity: O(n log n) due to sorting, where n is the array size.
Space Complexity: O(n) for temporary arrays.
