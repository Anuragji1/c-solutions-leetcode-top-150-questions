**Search in Related Sorted Array**

Problem Statement 109) There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
Example 3:

Input: nums = [1], target = 0
Output: -1
 

Constraints:

1 <= nums.length <= 5000
-104 <= nums[i] <= 104
All values of nums are unique.
nums is an ascending array that is possibly rotated.
-104 <= target <= 104

------------------------------------------------------------------------------------------------------
SOLUTION = 

int search(int* nums, int numsSize, int target)
{
    int lo, hi;
    
    for (lo = 0, hi = numsSize - 1; lo <= hi;) {
        int mid = (lo + hi) / 2;
        
        if (nums[mid] == target) {
            return mid;
        }
        
        if (nums[lo] <= nums[mid]) {
            // we are on the left of the peak
            if (nums[lo] <= target && target < nums[mid]) {
                // go left
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        } else {
            // we are on the right of the peak
            if (nums[mid] < target && target <= nums[hi]) {
                // go right
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        
    }

    return -1;
}

--------Explanation :-
This code implements a binary search function search that can be used to find the target element (target) in a rotated sorted array (nums). A rotated sorted array is an array where the elements of a sorted array have been rotated some number of times. Here's a breakdown of the code:

Explanation:

Initialization:

Declare two integer variables:
lo: Initialized to 0, representing the index of the first element in the search range.
hi: Initialized to numsSize - 1, representing the index of the last element in the search range.
Binary Search Loop:

Use a while loop to continue searching as long as lo is less than or equal to hi:
Calculate the middle index mid as the average of lo and hi.
Target Found:

If nums[mid] == target, the target element is found at the middle index. Return mid as the search is successful.
Identify Array Partition:

Check if the left half of the array (nums[lo] <= nums[mid]) is sorted (increasing order):
If it is, there are two possibilities:
If nums[lo] <= target && target < nums[mid], the target element lies within the sorted left half. Update hi to mid - 1 to focus the search on the left half.
Otherwise (target >= nums[mid]), the target element cannot be in the left half as it's sorted and increasing. Update lo to mid + 1 to search the right half.
Right Half Search:

If the left half is not sorted (nums[lo] > nums[mid]), it means we're on the right side of the rotation point (peak). There are two possibilities:
If nums[mid] < target && target <= nums[hi], the target element might be in the sorted right half. Update lo to mid + 1 to search the right half.
Otherwise (target > nums[hi]), the target element cannot be in the right half as it's sorted and increasing. Update hi to mid - 1 to search the left half.
Search Exausted:

If the loop completes without finding the target, it means the target is not present in the array.
Return -1 to indicate the search was unsuccessful.
