**Roman to Integer**

Problem Statement 17) Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer.

 

Example 1:

Input: s = "III"
Output: 3
Explanation: III = 3.
Example 2:

Input: s = "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.
Example 3:

Input: s = "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 

Constraints:

1 <= s.length <= 15
s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
It is guaranteed that s is a valid roman numeral in the range [1, 3999].

-------------------------------------------------------------------------------------------------------
SOLUTION = int romanToInt(char * s)
{
    int I = 1;
    int V = 5;
    int X = 10;
    int L = 50;
    int C = 100;
    int D = 500;
    int M = 1000;
    int sum = 0;
    int i = 0;
    while (s[i])
    {
        if (s[i] == 'C' && s[i + 1] == 'M')
        {
            i += 2;
            sum += (D + 4 * C);
        }
        else if (s[i] == 'X' && s[i + 1] == 'C')
        {
            i += 2;
            sum += (L + 4 * X);
        }
        else if (s[i] == 'I' && s[i + 1] == 'X')
        {
            i += 2;
            sum += (V + 4 * I); 
        }
        else if (s[i] == 'C' && s[i + 1] == 'D')
        {
            i += 2;
            sum += 4 * C;
        }
        else if (s[i] == 'X' && s[i + 1] == 'L')
        {
            i += 2;
            sum += 4 * X; 
        }
        else if (s[i] == 'I' && s[i + 1] == 'V')
        {
            i += 2;
            sum += 4 * I; 
        }
        else if (s[i] == 'I')
        {
            sum += I;
            i++;
        }    
        else if (s[i] == 'V')
        {
            sum += V;
            i++;
        }
        else if (s[i] == 'X')
        {
            sum += X;
            i++;
        }
        else if (s[i] == 'L')
        {
            sum += L;
            i++;
        }
        else if (s[i] == 'C')
        {
            sum += C;
            i++;
        }
        else if (s[i] == 'D')
        {
            sum += D;
            i++;
        }
        else if (s[i] == 'M')
        {
            sum += M;
            i++;
        }  
    }
    return sum;
}

------------------------Explanation :-
Variables:

I, V, ..., M: Integers representing the values of Roman numerals.
sum: Stores the accumulated integer value as we parse the Roman numeral string.
i: Iterates through the characters in the string.
Logic:

Loop through the string: The code iterates through each character in the string s.
Handle special cases:
It checks for specific combinations of two characters that represent larger values:
CM, XC, IV, CD, XL, and IX each have special meanings and are handled individually.
Handle individual characters:
If the character is not part of a special case, it checks individual characters:
I, V, X, L, C, D, and M are added to the sum based on their corresponding values.
Return the sum: After iterating through the entire string, the sum variable contains the final integer value derived from the Roman numeral, which is returned.
Key Points:

The code efficiently handles both single characters and special combinations for accurate conversion.
It relies on pre-defined values for each Roman numeral symbol and applies the appropriate logic based on their combinations.
