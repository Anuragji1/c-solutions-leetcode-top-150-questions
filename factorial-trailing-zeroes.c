**Factorial Trailing Zeroes**

Problem Statement 125) Given an integer n, return the number of trailing zeroes in n!.

Note that n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1.

 

Example 1:

Input: n = 3
Output: 0
Explanation: 3! = 6, no trailing zero.
Example 2:

Input: n = 5
Output: 1
Explanation: 5! = 120, one trailing zero.
Example 3:

Input: n = 0
Output: 0
 

Constraints:

0 <= n <= 104

-----------------------------------------------------------------------------------------
SOLUTION = int trailingZeroes(int n) {
    int count = 0;
    // Keep dividing n by 5 until it becomes 0
    while (n >= 5) {
        count += n / 5;
        n /= 5;
    }
    return count;
}

-----Explanation :-
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
