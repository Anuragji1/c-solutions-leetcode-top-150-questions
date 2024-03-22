**Single Number II**

Problem Statement 121) Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.

You must implement a solution with a linear runtime complexity and use only constant extra space.

 

Example 1:

Input: nums = [2,2,3,2]
Output: 3
Example 2:

Input: nums = [0,1,0,1,0,1,99]
Output: 99
 

Constraints:

1 <= nums.length <= 3 * 104
-231 <= nums[i] <= 231 - 1
Each element in nums appears exactly three times except for one element which appears once.

------------------------------------------------------------------------------------------------------
SOLUTION = int singleNumber(int* nums, int numsSize) {
    int ones = 0, twos = 0;
    for (int i = 0; i < numsSize; i++) {
        ones = (ones ^ nums[i]) & ~twos;  // Update ones, taking care of twos
        twos = (twos ^ nums[i]) & ~ones;  // Update twos, taking care of ones
    }
    return ones; // The single number is left in the ones variable
}

-----Explanation:- 
Leveraging Two Variables:

Unlike the XOR solution that used a single variable (result), this approach uses two variables: ones and twos.
These variables will hold intermediate states during the calculation to eventually isolate the single number in ones.
Iterative Updates:

The code iterates through the array elements using a for loop.
In each iteration, it updates ones and twos using bitwise operations and negation (~).
Updating ones:

The update for ones involves XOR (^) with the current element (nums[i]) and then performs a bitwise AND (&) with the negation of twos (~twos).
The XOR operation aims to include the current element in ones if it hasn't been seen before.
The AND with ~twos ensures that any bits set in ones due to encountering a duplicate element earlier (which would also be set in twos) are cleared. This effectively removes the duplicates from ones.
Updating twos:

The update for twos is similar but uses the negation of ones (~ones) in the AND operation.
The XOR aims to include the current element in twos if it's the second occurrence of a duplicate element.
The AND with ~ones guarantees that bits set in twos due to a single occurrence in the first pass (which would also be set in ones) are cleared. This isolates the second occurrences of duplicates in twos.
After the Loop:

Since all duplicates will have gone through twos and been cleared from ones due to the negation operations, ones will hold the single number that appeared only once in the array.
Key Points:

This approach avoids using the XOR property directly but leverages bitwise manipulation to achieve the same result of eliminating duplicates.
It requires understanding how bitwise operations like XOR, AND, and negation interact with each other to manipulate specific bits.
Comparison with XOR Solution:

The XOR solution (problem 120) is simpler to understand as it relies on a single property of XOR.
This bitwise manipulation approach might be less intuitive but can be more efficient in certain scenarios where multiple bits need to be tracked for duplicates.
