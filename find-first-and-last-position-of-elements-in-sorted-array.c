**Find First and Last Position of Element in Sorted Array**

Problem Statement 110) Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109

----------------------------------------------------------------------------------------------------------------------------------------------------------
SOLUTION = int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;  // Initialize return size to 2 (for first and last indices)
    int* result = malloc(sizeof(int) * 2);  // Allocate memory for the result array
    result[0] = -1;  // Initialize first index to -1 (not found)
    result[1] = -1;  // Initialize last index to -1 (not found)

    // Find the first occurrence of target using binary search
    int left = 0, right = numsSize - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            result[0] = mid;  // Found first occurrence
            right = mid - 1;  // Search for earlier occurrences on the left
        } else if (nums[mid] < target) {
            left = mid + 1;  // Search on the right
        } else {
            right = mid - 1;  // Search on the left
        }
    }

    // Find the last occurrence of target using binary search
    left = 0, right = numsSize - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            result[1] = mid;  // Found last occurrence
            left = mid + 1;  // Search for later occurrences on the right
        } else if (nums[mid] < target) {
            left = mid + 1;  // Search on the right
        } else {
            right = mid - 1;  // Search on the left
        }
    }

    return result;
}

----Explanation:- This code implements the searchRange function, which finds the first and last occurrences of a target element (target) in a sorted array (nums). It efficiently searches for both occurrences using separate binary searches and returns an array containing the indices.

Initialization:

Set *returnSize to 2, indicating the result array will hold the first and last occurrence indices.
Allocate memory for the result array (result) using malloc to store the two indices.
Initialize both elements in the result array to -1, representing the target not found.
Find First Occurrence:

Perform a binary search using a while loop similar to a standard binary search:
Search within the range left to right.
Calculate the middle index mid.
If nums[mid] == target:
Update result[0] to mid as the first occurrence is found.
Update right to mid - 1 to search for earlier occurrences on the left side in the next iteration.
Otherwise, update search range based on comparison with target:
If nums[mid] < target, search the right half by setting left to mid + 1.
If nums[mid] > target, search the left half by setting right to mid - 1.
Find Last Occurrence:

Perform another binary search similar to the first one, but with a slight modification:
After finding an occurrence at mid, update left to mid + 1 to search for later occurrences on the right side in the next iteration.
Return Result:

The result array now holds the first occurrence in result[0] and the last occurrence in result[1]. If no occurrences were found, both elements will remain -1.
Return the result array containing the indices.
Key Points:

The code performs two separate binary searches, one to find the first occurrence and another to find the last occurrence.
The modification in the second search ensures that the last occurrence is captured by continuing the search to the right side after finding a match.
