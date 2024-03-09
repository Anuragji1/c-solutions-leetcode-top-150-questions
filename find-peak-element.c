**Find Peak Element**

Problem Statement 108) A peak element is an element that is strictly greater than its neighbors.

Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.

You must write an algorithm that runs in O(log n) time.

 

Example 1:

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
Example 2:

Input: nums = [1,2,1,3,5,6,4]
Output: 5
Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.
 

Constraints:

1 <= nums.length <= 1000
-231 <= nums[i] <= 231 - 1
nums[i] != nums[i + 1] for all valid i.

-----------------------------------------------------------------------------------------------------------------------------------------------
SOLUTION = #include <stdio.h>

int findPeakElement(int* nums, int numsSize) {
    int left = 0, right = numsSize - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;  // Prevent potential integer overflow

        if (nums[mid] > nums[mid + 1]) {
            // Peak exists in the left half (including mid)
            right = mid;
        } else {
            // Peak exists in the right half (excluding mid)
            left = mid + 1;
        }
    }
    return left;  // At this point, left == right, indicating a peak element
}

-----------Explanation :- This code implements the findPeakElement function which finds the index of a peak element in a mountain-shaped array (nums). A mountain-shaped array is defined as an array where the elements increase strictly from the beginning to a peak element, and then strictly decrease to the end.

Explanation:

Initialization:

Declare two integer variables:
left: Initialized to 0, representing the index of the first element in the search range.
right: Initialized to numsSize - 1, representing the index of the last element in the search range.
Binary Search Loop:

Use a while loop to continue searching as long as left is less than right:
Calculate the middle index mid as the average of left and right, with a correction to prevent potential integer overflow during division. This is done using left + (right - left) / 2.
Identify Peak Location:

Check the element at the middle index (mid) and the element to its right (mid + 1):
If nums[mid] > nums[mid + 1], it means the peak is in the left half of the remaining search range (including the middle element). Update right to mid to focus the search on the left half.
Otherwise (nums[mid] <= nums[mid + 1]), the peak is in the right half of the remaining search range (excluding the middle element). Update left to mid + 1 to focus the search on the right half.
Return Peak Index:

The loop continues until left and right converge on the same index. At this point, left will point to the peak element's index.
Return the value of left as the index of the peak element in the array.
Key Points:

The code utilizes a binary search approach to efficiently find the peak element by repeatedly halving the search range based on the comparison between the middle element and its neighbor to the right.
The condition nums[mid] > nums[mid + 1] effectively identifies which half of the search range must contain the peak element.
