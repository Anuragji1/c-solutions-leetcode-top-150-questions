**Merge Sorted Array**

Problem Statement 1) You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

 

Example 1:

Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
Example 2:

Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
Explanation: The arrays we are merging are [1] and [].
The result of the merge is [1].
Example 3:

Input: nums1 = [0], m = 0, nums2 = [1], n = 1
Output: [1]
Explanation: The arrays we are merging are [] and [1].
The result of the merge is [1].
Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.
 

Constraints:

nums1.length == m + n
nums2.length == n
0 <= m, n <= 200
1 <= m + n <= 200
-109 <= nums1[i], nums2[j] <= 109

--------------------------------------------------------------------------------------------------------------------------------
SOLUTION = void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int i = m - 1, j = n - 1, k = m + n - 1;

    // Merge from the end of nums1 and nums2 into nums1
    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k--] = nums1[i--];
        } else {
            nums1[k--] = nums2[j--];
        }
    }

    // Copy remaining elements from nums2, if any
    while (j >= 0) {
        nums1[k--] = nums2[j--];
    }
}

-----------------------Explanation:-
Problem:

Given two sorted arrays nums1 and nums2, merge them into a single sorted array within nums1 without using extra space.
Key Idea:

Use a three-pointer approach to efficiently merge elements in a single pass.
Code Breakdown:

Initialization:

Set pointers i to the end of the valid part of nums1 (m - 1), j to the end of nums2 (n - 1), and k to the end of the merged array (m + n - 1).
Merging Loop:

Iterate while both i and j are within their respective arrays:
Compare the elements at nums1[i] and nums2[j]:
If nums1[i] is greater, copy it to nums1[k] and decrement i and k.
Otherwise, copy nums2[j] to nums1[k] and decrement j and k.
Copying Remaining Elements:

If any elements remain in nums2, copy them directly to the remaining space in nums1.
Time and Space Complexity:

Time: O(m + n), due to iterating through both arrays once.
Space: O(1), as the merging is done in-place without additional arrays.
