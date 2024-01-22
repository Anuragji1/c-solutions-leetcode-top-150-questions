**Integer to Roman**

Problem Statement 18) Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two one's added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given an integer, convert it to a roman numeral.

 

Example 1:

Input: num = 3
Output: "III"
Explanation: 3 is represented as 3 ones.
Example 2:

Input: num = 58
Output: "LVIII"
Explanation: L = 50, V = 5, III = 3.
Example 3:

Input: num = 1994
Output: "MCMXCIV"
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 

Constraints:

1 <= num <= 3999

-----------------------------------------------------------------------------------------------------------------------------------------
SOLUTION = #include <stdio.h>
#include <string.h>

char* intToRoman(int num) {
    char* symbol[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int value[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

    char* roman = (char*)malloc(20 * sizeof(char));  // Allocate memory for the result
    memset(roman, 0, 20);  // Initialize all characters to '\0'

    int i = 0;
    while (num > 0) {
        while (num >= value[i]) {
            num -= value[i];
            strcat(roman, symbol[i]);  // Append the symbol to the result string
        }
        i++;
    }

    return roman;
}


--------------------Explanation :-
Key elements:

Symbol array: symbol stores an array of strings representing Roman numerals in descending order of value (e.g., "M", "CM", "D", ...).
Value array: value holds an array of integers corresponding to the values of each Roman numeral symbol in the same order.
Result string: roman is a dynamically allocated character array to store the converted Roman numeral string.
Algorithm:

Initialization:

Allocate memory for the roman string and initialize all characters to null terminator (\0).
Set an index i to 0 to iterate through the symbol and value arrays.
Looping and Conversion:

While the remaining integer num is greater than 0:
Within the current symbol symbol[i], keep subtracting its corresponding value (value[i]) from num until it's no longer possible.
For each subtraction, append the current symbol symbol[i] to the roman string.
Increment the index i to move to the next symbol and value in the arrays.
Returning the Result:

After the loop finishes, the roman string contains the converted Roman numeral representation of the original integer num. This string is then returned as the function's result.
