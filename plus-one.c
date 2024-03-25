**Plus One**

Problem Statement 124) You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.

 

Example 1:

Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].
Example 2:

Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
Incrementing by one gives 4321 + 1 = 4322.
Thus, the result should be [4,3,2,2].
Example 3:

Input: digits = [9]
Output: [1,0]
Explanation: The array represents the integer 9.
Incrementing by one gives 9 + 1 = 10.
Thus, the result should be [1,0].
 

Constraints:

1 <= digits.length <= 100
0 <= digits[i] <= 9
digits does not contain any leading 0's.

..-----------------------------------------------------------------------------------------
SOLUTION = /**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
int i, niner = 0;
	for(i = digitsSize - 1; i >= 0; i--) {
		if(digits[i] != 9)
			break;
		niner++;
	}
	if(niner != digitsSize) { 			// Case 1: One or more 9's
		*returnSize = digitsSize;
		for(i = digitsSize - 1; i >= 0; i--) {
			if(digits[i] == 9 && digits[i-1] == 9) {
				digits[i] = 0;
			} else if(digits[i] == 9 && digits[i-1] != 9) {
				digits[i] = 0;
			} else {
				digits[i]++;
				break;
			}
		}
		return digits;
	} else {							// Case 2: All 9's
		*returnSize = digitsSize + 1;
		int * digitsPlusOne = (int*)malloc((digitsSize + 1) * sizeof(int));
		digitsPlusOne[0] = 1;
		int i;
		for(i = 1; i < *returnSize; i++)
			digitsPlusOne[i] = 0;
		return digitsPlusOne;
	}
	return NULL;
}

------Explanation :-
Steps:

Initialization:

Two integer variables are declared:
i for loop iteration.
niner to count the number of consecutive 9s encountered while iterating from the end of the digits array.
Finding the Carry Digit:

It uses a for loop that iterates backward from the last digit (digitsSize - 1) to the first digit (0).
In each iteration, it checks if the current digit (digits[i]) is not equal to 9.
If it's not 9, it means the carry digit (the digit to be added) is 1, and the loop can break.
If it is 9, it increments the niner counter to track the number of consecutive 9s encountered.
Handling Cases:

The code checks the value of niner to determine which case applies:

Case 1: One or More 9s (Not All 9s):

If niner is not equal to digitsSize (meaning there are non-9 digits before the consecutive 9s), the function performs the following:
Sets returnSize to the original digitsSize (no additional digit needed).
It iterates through the digits array again, starting from the end.
If it encounters a sequence of 9s (digits[i] == 9 and digits[i-1] == 9), it sets the current digit to 0 (carrying over the 1).
If it encounters a single 9 (digits[i] == 9 and digits[i-1] != 9), it sets the current digit to 0 (carrying over the 1) and breaks the loop (since the previous digit will be incremented in the next step).
If it encounters a non-9 digit, it increments the current digit (digits[i]++) and breaks the loop (no further carry needed).
The function returns the modified digits array itself (no need for allocation).
Case 2: All 9s:

If niner is equal to digitsSize (meaning all digits are 9s), the function performs the following:
Sets returnSize to digitsSize + 1 to accommodate the additional digit (carry becomes 1).
Allocates memory for a new integer array digitsPlusOne of size digitsSize + 1 using malloc.
Sets the first element of digitsPlusOne to 1 (the carry digit).
Initializes all other elements of digitsPlusOne to 0.
The function returns the newly allocated digitsPlusOne array.
No Change Necessary:

If the loop completes without encountering any non-9 digits (all digits are 9s), the function returns NULL (indicating an edge case that might need special handling depending on the specific use case).
