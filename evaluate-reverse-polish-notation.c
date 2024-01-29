**Evaluate Reverse Polish Notation**

Problem Statement 56) You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

Evaluate the expression. Return an integer that represents the value of the expression.

Note that:

The valid operators are '+', '-', '*', and '/'.
Each operand may be an integer or another expression.
The division between two integers always truncates toward zero.
There will not be any division by zero.
The input represents a valid arithmetic expression in a reverse polish notation.
The answer and all the intermediate calculations can be represented in a 32-bit integer.
 

Example 1:

Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9
Example 2:

Input: tokens = ["4","13","5","/","+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6
Example 3:

Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
Output: 22
Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
 

Constraints:

1 <= tokens.length <= 104
tokens[i] is either an operator: "+", "-", "*", or "/", or an integer in the range [-200, 200].


---------------------------------------------------------------------------------------------------------------
SOLUTION = int evalRPN(char** tokens, int tokensSize) {
    int stack[tokensSize], top = -1;

    for (int i = 0; i < tokensSize; i++) {
        if (isdigit(tokens[i][0]) || (tokens[i][0] == '-' && tokens[i][1] != '\0')) {  // Operand
            stack[++top] = atoi(tokens[i]);  // Convert to integer and push
        } else {  // Operator
            int y = stack[top--];
            int x = stack[top--];
            switch (tokens[i][0]) {
                case '+': stack[++top] = x + y; break;
                case '-': stack[++top] = x - y; break;
                case '*': stack[++top] = x * y; break;
                case '/': stack[++top] = x / y; break;  // Truncated division
            }
        }
    }

    return stack[top];  // Final result
}

-----------Explanation :- 
Purpose:

This code evaluates an arithmetic expression in Reverse Polish Notation (RPN), where operators follow their operands.
Function Breakdown:

Initialization:

Creates an integer array stack to store operands and initializes top to -1 (empty stack).
Iterating Through Tokens:

Iterates through each token in tokens:
Operand:
Checks if the token is a number (digit or negative number).
Converts it to an integer using atoi and pushes it onto the stack.
Operator:
Pops the top two operands (y and x) from the stack.
Performs the corresponding operation based on the operator using a switch statement.
Pushes the result back onto the stack.
Returning Result:

Returns the final result, which is the only value left on the stack.
Key Points:

RPN Evaluation: RPN allows for evaluation without parentheses due to the fixed operator-operand order.
Stack for Evaluation: Uses a stack to store operands and apply operators in the correct order.
Operator Handling: Pops operands before applying operators, ensuring correct precedence.
Error Handling: Doesn't explicitly handle invalid input or potential errors like division by zero.
Time Complexity: O(n), where n is the number of tokens, due to linear iteration and constant-time stack operations.
Space Complexity: O(n) for the stack in the worst case of a long expression without operators.
