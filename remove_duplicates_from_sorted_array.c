**Remove Duplicates from Sorted Array**

Problem Statement 3) Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.

Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:

Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially. The remaining elements of nums are not important as well as the size of nums.
Return k.
Custom Judge:

The judge will test your solution with the following code:

int[] nums = [...]; // Input array
int[] expectedNums = [...]; // The expected answer with correct length

int k = removeDuplicates(nums); // Calls your implementation

assert k == expectedNums.length;
for (int i = 0; i < k; i++) {
    assert nums[i] == expectedNums[i];
}
If all assertions pass, then your solution will be accepted.

 

Example 1:

Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
Example 2:

Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
 

Constraints:

1 <= nums.length <= 3 * 104
-100 <= nums[i] <= 100
nums is sorted in non-decreasing order.

-----------------------------------------------------------------------------------------------------------------------------------
SOLUTION = int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0) {
        return 0; // Handle empty array case
    }

    int writeIndex = 1;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] != nums[i - 1]) {
            nums[writeIndex++] = nums[i];
        }
    }

    return writeIndex;
}

------------------------------------------Explanation :-
Problem:

Given a sorted array nums, remove duplicate elements from it such that each element appears only once, and return the new length of the array.
Key Idea:

Use two pointers to maintain a "write" index and scan for unique elements.
Code Breakdown:

Handle Empty Array:

If numsSize is 0, return 0 as there are no elements.
Initialization:

Set writeIndex to 1, indicating the starting position for writing unique elements.
Main Loop:

Iterate through the array (i from 1 to numsSize - 1):
Compare the current element nums[i] with the previous one:
If they are different (nums[i] != nums[i - 1]), it means nums[i] is unique:
Write it to the writeIndex position: nums[writeIndex++] = nums[i]
Increment writeIndex to prepare for the next unique element.
Return New Length:

The final writeIndex represents the number of unique elements in the array.
Return writeIndex, which is the new length of the array without duplicates.
Time and Space Complexity:

Time: O(n), due to iterating through the array once.
Space: O(1), as the removal is done in-place without additional arrays.
