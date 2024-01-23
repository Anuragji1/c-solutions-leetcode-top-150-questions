**3Sum**

Problem Statement 29) Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
Example 2:

Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.
Example 3:

Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.
 

Constraints:

3 <= nums.length <= 3000
-105 <= nums[i] <= 105

--------------------------------------------------------------------------------------------
SOLUTION = 

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void swap (int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition (int* a, int low, int high) {
    
    int pivot = a[high];
    int j = low -1;
    int i = low;
    
    for (; i < high; i++) {
        if (a[i] <= pivot) {
            j += 1;
            swap(&a[i], &a[j]);
        }
    }
    swap (&a[j+1], &a[high]);
    return j+1;
}

void quick_sort (int* a, int low, int high) {
    
    if (low < high) {
        int pivot = partition(a, low, high);
        quick_sort (a, low, pivot -1);
        quick_sort (a, pivot+1, high);
    }
}


int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
 
    if (numsSize < 3) {
        int** r = (int**) malloc(sizeof(int*));
        *returnSize = 0;
        return r;
    }
    
    int** a = (int**) malloc(numsSize*numsSize* sizeof(int*));
    memset (a, 0, numsSize* sizeof(int*));
    int* size = (int*) malloc (numsSize*numsSize* sizeof(int));
    *returnSize = 0;
    
    int low = 1;
    int high = numsSize -1;
    
    quick_sort (nums, 0, numsSize-1);
    
    for (int i = 0; i < numsSize; i++) {
        if (i > 0 && nums[i-1] == nums[i])
            continue;
        low = i+1;
        high = numsSize -1;
        while (low < high) {
            if (nums[i] + nums[low] + nums[high] == 0) {
                a[*returnSize] = (int*) malloc (3*sizeof(int));
                memset(a[*returnSize], 0, 3*sizeof(int));
                a[*returnSize][0] = nums[i];
                a[*returnSize][1] = nums[low];
                a[*returnSize][2] = nums[high];
                size[*returnSize] = 3;
                *returnSize += 1;
                low ++;
                while (low < high && nums[low -1] == nums[low])
                    low ++;
            } else if (nums[i] + nums[low] + nums[high] > 0)
                high --;
            else if (nums[i] + nums[low] + nums[high] < 0)
                low ++;
        }
    }
    
    int** ret = (int**) realloc (a, (*returnSize)*sizeof(int*));
    *returnColumnSizes = (int*)realloc(size, (*returnSize)*sizeof(int));
        
    return ret;
}

--------------------Explanation :-
Function Overview:

threeSum aims to find all unique triplets in a given array of integers that sum to 0.
It returns an array of arrays (each inner array representing a triplet) and an array storing the column sizes of the triplets.
It employs sorting and two-pointer techniques for efficient solution.
Breakdown:

Helper Functions:

swap: Swaps two integer values.
partition: Partitions an array around a pivot for quick sorting.
quick_sort: Implements the quick sort algorithm to sort the input array.
Main Algorithm:

Handles small cases: If the array size is less than 3, returns an empty result.
Sorts the array: Uses quick_sort to arrange elements in ascending order, facilitating efficient triplet search.
Iterates through the array:
Manages duplicates: Skips elements already considered to avoid redundant triplets.
Employs two-pointer technique:
Uses low and high pointers to scan towards each other from both ends.
Calculates the sum of the current element and elements at low and high.
If the sum is 0:
Stores the triplet in a dynamically allocated array.
Moves low forward, skipping duplicates.
If the sum is positive:
Decreases high to reduce the sum.
If the sum is negative:
Increases low to increase the sum.
Resizes and returns results:
Reallocates memory for the result arrays (a and size) to fit the actual number of triplets found.
Returns the pointer to the array of triplets and the array of column sizes.
