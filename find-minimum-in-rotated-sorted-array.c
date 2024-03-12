**Find Minimum In Rotated Sorted Array**

Problem Statement 111) Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:

[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums of unique elements, return the minimum element of this array.

You must write an algorithm that runs in O(log n) time.

 

Example 1:

Input: nums = [3,4,5,1,2]
Output: 1
Explanation: The original array was [1,2,3,4,5] rotated 3 times.
Example 2:

Input: nums = [4,5,6,7,0,1,2]
Output: 0
Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4 times.
Example 3:

Input: nums = [11,13,15,17]
Output: 11
Explanation: The original array was [11,13,15,17] and it was rotated 4 times. 
 

Constraints:

n == nums.length
1 <= n <= 5000
-5000 <= nums[i] <= 5000
All the integers of nums are unique.
nums is sorted and rotated between 1 and n times.

------------------------------------------------------------------------------------------------------------------
SOLUTION = int findMin(int* nums, int numsSize) {
    int left = 0, right = numsSize - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        // If the middle element is greater than the rightmost element,
        // the minimum must be in the second half (including the middle)
        if (nums[mid] > nums[right]) {
            left = mid + 1;
        } else {
            // Otherwise, the minimum must be in the first half (including the middle)
            right = mid;
        }
    }

    // At this point, left == right, and they point to the minimum element
    return nums[left];
}

---------Explanation :-
This code implements the findMin function to find the minimum element in a rotated sorted array (nums). A rotated sorted array is an array where the elements of an originally sorted array have been rotated some number of times. Here's a breakdown of the code:

Initialization:

Declare two integer variables:
left: Initialized to 0, representing the index of the first element in the search range.
right: Initialized to numsSize - 1, representing the index of the last element in the search range.
Binary Search Loop:

Use a while loop to continue searching as long as left is less than right:
Calculate the middle index mid as the average of left and right.
Identify Minimum Location:

The key idea is to exploit the property of a rotated sorted array. The minimum element will always be on the side of the array where the middle element (nums[mid]) is greater than the rightmost element (nums[right]).
If nums[mid] > nums[right], it means the minimum element must be in the second half of the array (including the middle element). Update left to mid + 1 to focus the search on the right half.
Otherwise (nums[mid] <= nums[right]), the minimum element must be in the first half of the array (including the middle element). Update right to mid to focus the search on the left half.
Minimum Found:

The loop continues until left and right converge on the same index. At this point, both left and right will point to the minimum element in the rotated sorted array.
Return Minimum:

Return the value at the converged index (nums[left]) as the minimum element.
