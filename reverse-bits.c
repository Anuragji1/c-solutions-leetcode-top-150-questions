**Reverse Bits**

Problem Statement 118) Reverse bits of a given 32 bits unsigned integer.

Note:

Note that in some languages, such as Java, there is no unsigned integer type. In this case, both input and output will be given as a signed integer type. They should not affect your implementation, as the integer's internal binary representation is the same, whether it is signed or unsigned.
In Java, the compiler represents the signed integers using 2's complement notation. Therefore, in Example 2 above, the input represents the signed integer -3 and the output represents the signed integer -1073741825.
 

Example 1:

Input: n = 00000010100101000001111010011100
Output:    964176192 (00111001011110000010100101000000)
Explanation: The input binary string 00000010100101000001111010011100 represents the unsigned integer 43261596, so return 964176192 which its binary representation is 00111001011110000010100101000000.
Example 2:

Input: n = 11111111111111111111111111111101
Output:   3221225471 (10111111111111111111111111111111)
Explanation: The input binary string 11111111111111111111111111111101 represents the unsigned integer 4294967293, so return 3221225471 which its binary representation is 10111111111111111111111111111111.
 

Constraints:

The input must be a binary string of length 32

-----------------------------------------------------------------------------------------------
SOLUTION = uint32_t reverseBits(uint32_t n) {
    uint32_t rev = 0;
    int i;
    for (i = 0; i < 32; i++) {
        rev = (rev << 1) | (n & 1);
        n >>= 1;
    }
    return rev;
}


-------Explanation :- 
Initialization:

It declares a variable rev of type uint32_t to store the reversed bits. It's initialized to 0.
An integer variable i is used for the loop counter.
Bit Manipulation Loop:

The code iterates 32 times (since there are 32 bits in a uint32_t) using a for loop.
In each iteration:
Shift Left: It left-shifts (<< 1) the current value in rev by one position. This effectively creates space to insert the reversed bit at the least significant position (rightmost) of rev.
Get Least Significant Bit: It performs a bitwise AND operation (&) between n and 1 (which is 0000...0001 in binary). This isolates the least significant bit (LSB) of n.
OR with Reversed Bit: It performs a bitwise OR operation (|) between the left-shifted rev and the isolated LSB of n. This inserts the LSB of n (which is now the most significant bit (MSB) of the reversed value) into the least significant position of rev.
Right Shift: It right-shifts (>> 1) the value in n by one position. This effectively removes the processed LSB from n for the next iteration.
Return Reversed Bits:

After the loop completes, rev will hold the reversed bits of the original n.
The function returns rev.
