**BITWISE AND of Numbers Range**

Problem Statement) Given two integers left and right that represent the range [left, right], return the bitwise AND of all numbers in this range, inclusive.

 

Example 1:

Input: left = 5, right = 7
Output: 4
Example 2:

Input: left = 0, right = 0
Output: 0
Example 3:

Input: left = 1, right = 2147483647
Output: 0
 

Constraints:

0 <= left <= right <= 231 - 1

--------------------------------------------------------------------------------------------------------------------------------------------
SOLUTION = int rangeBitwiseAnd(int left, int right) {
    int count = 0;
    while (left != right) {
        left >>= 1;
        right >>= 1;
        count++;
    }
    return left << count;
}

------Explanation :- 
Initialization:

The code creates an integer variable count initialized to 0. This variable will track the number of common leading bits (most significant identical bits) between left and right.
Finding the Common Prefix:

It enters a while loop that continues as long as left is not equal to right. This ensures that the loop iterates until both numbers have the same binary prefix.
In each iteration:
Right Shifts: The loop performs right shifts (>>=) on both left and right by 1 position. This effectively removes the least significant bit (LSB) from each number and promotes the common prefix towards the most significant positions.
Increment Counter: The count variable is incremented by 1 after each right shift. This keeps track of the number of common bits identified so far.
Returning the Result:

Once the loop terminates (when left and right become equal), it signifies that the common prefix has been found.
The function returns left left-shifted (<<) by count positions. Since left now represents the common prefix due to the right shifts, left-shifting it by count effectively retrieves the largest bitwise AND value within the specified range.
Example:

Consider the input left = 5 (0101 in binary) and right = 7 (0111 in binary).

Initially, count is 0.
In the first iteration, both left and right are right-shifted by 1, resulting in left = 2 (0010) and right = 3 (0011). count becomes 1.
The loop continues iterating, right-shifting both numbers again. Now, left and right become 1 (0001) and count becomes 2.
Since left and right are now equal, the loop terminates.
The function returns left << count, which is 1 << 2, resulting in 4 (0100 in binary). This is the largest bitwise AND value (common prefix) between 5 and 7.
