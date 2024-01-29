**Basic Calculator**

Problem Statement 57) Given a string s representing a valid expression, implement a basic calculator to evaluate it, and return the result of the evaluation.

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

 

Example 1:

Input: s = "1 + 1"
Output: 2
Example 2:

Input: s = " 2-1 + 2 "
Output: 3
Example 3:

Input: s = "(1+(4+5+2)-3)+(6+8)"
Output: 23
 

Constraints:

1 <= s.length <= 3 * 105
s consists of digits, '+', '-', '(', ')', and ' '.
s represents a valid expression.
'+' is not used as a unary operation (i.e., "+1" and "+(2 + 3)" is invalid).
'-' could be used as a unary operation (i.e., "-1" and "-(2 + 3)" is valid).
There will be no two consecutive operators in the input.
Every number and running calculation will fit in a signed 32-bit integer.

----------------------------------------------------------------------------------------------
SOLUTION = int number(char* s , int* i, int c){
    *i += 1;
    int n = s[*i] - '0';
    while (n >= 0 && n <= 9){
        c *= 10;
        c += n;
        *i += 1;
        n = s[*i] - '0';
    }
    return c;
}



int calculate(char* s){                    //'+' = 43, '-' = 45, '(' = 40, ')' = 41, ' ' = 32, '0' = 48
    int ans = 0;
    int len = strlen(s);
    int last_sign = 0;
    int Plus_or_Minus = 0;
    int parentheses = 0;
    int change =  0;
    int parentheses_location[1000] = {0};

    for (int i = 0 ; i < len ;){
        int c = s[i] - '0';
        switch (c) {
            case -5:last_sign = 0;
                    if (change % 2 == 1){
                        Plus_or_Minus = 1;
                    } else Plus_or_Minus = 0;
                    i++;
                    break;
            case -3:last_sign = 1;
                    if (change % 2 == 1){
                        Plus_or_Minus = 0;
                    } else Plus_or_Minus = 1;
                    i++;
                    break;
            case -8:if (last_sign == 1){
                        parentheses_location[parentheses]++;
                        change++;
                    }
                    parentheses++;
                    i++;
                    break;
            case -7:parentheses--;
                    if (parentheses_location[parentheses] == 1){
                        parentheses_location[parentheses]--;
                        change--;
                    }
                    i++;
                    break;
            case -16:i++;
                     break;
            default:if (Plus_or_Minus == 0){
                        ans += number(s ,&i, c);
                    } else ans -= number(s ,&i, c);
                    break;
        }
    }
    return ans;
}

---------Explanation :- 
Purpose:

This code calculates the value of a simple arithmetic expression containing digits, spaces, parentheses, plus signs, and minus signs.
Function Breakdown:

Initialization:

Initializes variables for the answer (ans), string length (len), tracking signs and parentheses (last_sign, Plus_or_Minus, parentheses, change, parentheses_location).
Iterating Through Characters:

Iterates through each character c in the string s:
Operator Handling:
Handles +, -, (, and ) using a switch statement, updating last_sign, Plus_or_Minus, parentheses, and change accordingly.
Tracks sign changes within parentheses using change and parentheses_location.
Number Handling:
If c is a digit, calls number to convert it and subsequent digits into a number and adds/subtracts it to ans based on Plus_or_Minus.
Space Handling:
Ignores spaces.
Returning Result:

Returns the final calculated value ans.
Key Points:

Iterative Approach: Evaluates the expression sequentially without recursion.
Sign Tracking: Uses variables to track the last sign and whether to add or subtract based on parentheses.
Parentheses Handling: Tracks sign changes within parentheses to handle nested expressions correctly.
Error Handling: Doesn't explicitly handle invalid input or potential errors like division by zero.
Time Complexity: O(n), where n is the string length, due to linear iteration.
Space Complexity: O(n) for the worst-case expression with many nested parentheses.
