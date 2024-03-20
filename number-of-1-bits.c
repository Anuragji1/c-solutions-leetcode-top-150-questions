**Number of 1 Bits**

Problem Statement 119) Write a function that takes the binary representation of an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).

Note:

Note that in some languages, such as Java, there is no unsigned integer type. In this case, the input will be given as a signed integer type. It should not affect your implementation, as the integer's internal binary representation is the same, whether it is signed or unsigned.
In Java, the compiler represents the signed integers using 2's complement notation. Therefore, in Example 3, the input represents the signed integer. -3.
 

Example 1:

Input: n = 00000000000000000000000000001011
Output: 3
Explanation: The input binary string 00000000000000000000000000001011 has a total of three '1' bits.
Example 2:

Input: n = 00000000000000000000000010000000
Output: 1
Explanation: The input binary string 00000000000000000000000010000000 has a total of one '1' bit.
Example 3:

Input: n = 11111111111111111111111111111101
Output: 31
Explanation: The input binary string 11111111111111111111111111111101 has a total of thirty one '1' bits.
 

Constraints:

The input must be a binary string of length 32.


-------------------------------------------------------------------------------------------------------------
SOLUTION = int hammingWeight(uint32_t n) {
    int count = 0;
    while (n > 0) {
        count += n & 1;  // Check the rightmost bit
        n >>= 1;          // Shift right to examine the next bit
    }
    return count;
}

---------Explanation :- 
This code implements the hammingWeight function to count the number of set bits (1s) in a 32-bit unsigned integer (uint32_t) named n. Here's a breakdown of how it works:

Explanation:

Initialization:

It declares an integer variable count to store the number of set bits. It's initialized to 0.
Bit Counting Loop:

The code uses a while loop that continues as long as n is greater than 0 (i.e., there are still bits to process).
In each iteration:
Bitwise AND: It performs a bitwise AND operation (&) between n and 1 (which is 0000...0001 in binary). This isolates the least significant bit (LSB) of n. Any set bit in n will result in a 1 after the AND operation.
Increment Count: It adds the result of the AND operation (n & 1) to the count variable. Since the result is either 1 (if the bit was set) or 0 (if the bit was not set), this effectively counts the number of set bits encountered so far.
Right Shift: It right-shifts (>>) the value in n by one position. This removes the processed LSB from n for the next iteration of the loop.
Return Count:

After the loop completes, count will hold the total number of set bits in the original n.
The function returns count.
