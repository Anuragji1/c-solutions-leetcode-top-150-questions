**Single Number**

Problem Statement 120) Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

 

Example 1:

Input: nums = [2,2,1]
Output: 1
Example 2:

Input: nums = [4,1,2,1,2]
Output: 4
Example 3:

Input: nums = [1]
Output: 1
 

Constraints:

1 <= nums.length <= 3 * 104
-3 * 104 <= nums[i] <= 3 * 104
Each element in the array appears twice except for one element which appears only once.

------------------------------------------------------------------------------------------------
SOLUTION = int singleNumber(int* nums, int numsSize) {
    int result = 0;
    for (int i = 0; i < numsSize; i++) {
        result ^= nums[i]; // XOR each element with the result
    }
    return result;
}


--------Explanation :-
Key Points:

XOR Property: The code leverages a key property of the bitwise XOR operator (^):
XORing a number with itself results in 0.
XORing a number with 0 results in the number itself.
Applying XOR: By XORing all elements in the array, pairs of duplicate elements cancel each other out, leaving only the single number as the result.
Steps:

Initialization:

It initializes a variable result to 0, which will eventually hold the single number.
XORing Elements:

It iterates through each element in the array using a for loop.
In each iteration, it performs a bitwise XOR (^) between result and the current element nums[i].
Due to the XOR property, duplicate elements cancel out, and the single number's bits remain in result.
Return Result:

After the loop, result contains the single number that appeared only once in the array.
The function returns result.
Example:

Consider the array nums = [2, 5, 2, 1, 5]. Here's how the XOR calculations proceed:

result = 0 ^ 2 = 2
result = 2 ^ 5 = 7
result = 7 ^ 2 = 5
result = 5 ^ 1 = 4
result = 4 ^ 5 = 1 (final result)
