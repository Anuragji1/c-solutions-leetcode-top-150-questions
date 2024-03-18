**Add Binary**

Problem Statement 117) Given two binary strings a and b, return their sum as a binary string.

 

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
 

Constraints:

1 <= a.length, b.length <= 104
a and b consist only of '0' or '1' characters.
Each string does not contain leading zeros except for the zero itself.

-----------------------------------------------------------------------------------------------------------------
SOLUTION = char* addBinary(char* a, char* b)
{
    int i, j, k, c = 0;
    char *res;
    
    i = strlen(a);
    j = strlen(b);
    k = i > j ? i : j;
    k += 2;

    res = malloc(k * sizeof(char));
    
    i--;
    j--;
    res[--k] = '\0';
    
    while (--k >= 0) {
        c += i >= 0 ? a[i--] - '0': 0;
        c += j >= 0 ? b[j--] - '0': 0;
        
        res[k] = c % 2 + '0';
        c /= 2;
    }
    
    if (res[0] == '0')
       memmove(res, res + 1, strlen(res) * sizeof(char));
    
    return res;
}

----Explanation :-
This code implements the addBinary function that takes two binary strings (a and b) and returns their binary sum. Here's a breakdown of how it works:

Steps:

Length Calculation:

It finds the lengths of the input strings a and b using strlen.
It determines the maximum length (k) by considering the larger of the two lengths and adding 1 (for potential carry) to ensure enough space for the result.
Result String Allocation:

It allocates memory for the result string (res) using malloc. The size is k * sizeof(char) to accommodate characters and a null terminator.
Iterative Addition:

It initializes variables i, j, and k for iterating through the input strings and the result string, respectively.
It starts from the least significant bits (ends of the strings) and iterates until k becomes negative (including space for the null terminator).
In each iteration:
It adds the values of the current characters from both strings (considering '0' as 0 and subtracting '0' to convert to integer values). It also adds the carry (c) from the previous iteration.
It calculates the remainder (c % 2) to get the current bit of the result (c % 2 + '0').
It updates the carry (c /= 2) for the next iteration.
Handling Leading Zero:

After the loop, it checks if the first character of the result (res[0]) is '0'. This indicates no carry-over from the addition.
If there's a leading zero, it uses memmove to shift the string left by one character, effectively removing the leading zero.
Return Result:

The function returns the pointer to the allocated memory (res) containing the binary sum of the input strings.
Key Points:

The code efficiently handles strings of different lengths by padding with zeros (implicitly) during the addition process.
It avoids unnecessary string manipulations by calculating the maximum length upfront and allocating sufficient memory.
The use of memmove ensures safe memory manipulation when removing the leading zero.
