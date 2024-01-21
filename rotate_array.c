**Rotate Array**

Problem Statement 6) Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

 

Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
 

Constraints:

1 <= nums.length <= 105
-231 <= nums[i] <= 231 - 1
0 <= k <= 105

--------------------------------------------------------------------------------------------------------------------------------
SOLUTIOn = void rotate(int* nums, int numsSize, int k) {
    k %= numsSize;  // Handle cases where k is larger than or equal to the array size
    if (k == 0 || numsSize == 1) {
        return;  // No rotation needed if k is 0 or the array has only one element
    }

    reverse(nums, 0, numsSize - 1);  // Reverse the entire array
    reverse(nums, 0, k - 1);         // Reverse the first k elements
    reverse(nums, k, numsSize - 1);  // Reverse the remaining elements
}

void reverse(int* nums, int start, int end) {
    while (start < end) {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
    }
}

-----------------------------Explanation:-
Purpose:

The code implements a function named rotate() that efficiently rotates the elements of an integer array by k positions to the right.
Key Functions:

rotate(int* nums, int numsSize, int k):

Takes three arguments:
nums: The integer array to be rotated.
numsSize: The size of the array.
k: The number of positions to rotate the array to the right.
Handles edge cases where k is large or the array is small.
Employs a space-efficient rotation strategy using array reversals.
reverse(int* nums, int start, int end):

Reverses the elements of the array nums between indices start and end (inclusive).
Used as a helper function within rotate().
Steps Involved in rotate():

Handle Edge Cases:

If k is 0 or the array size is 1, no rotation is needed, so the function returns.
If k is larger than or equal to the array size, it's reduced to its equivalent value within the array bounds using the modulo operator (%).
Perform Array Reversals:

The entire array is reversed using reverse(nums, 0, numsSize - 1).
The first k elements of the reversed array are reversed again using reverse(nums, 0, k - 1).
The remaining elements (from index k to the end) are reversed using reverse(nums, k, numsSize - 1).
These reversals effectively achieve the desired right rotation of the array.
Time and Space Complexity:

Time Complexity: O(n), where n is the size of the array. Each reversal operation takes linear time, and three reversals are performed.
Space Complexity: O(1), as the algorithm only uses a constant amount of extra space for temporary variables, regardless of the input size.
