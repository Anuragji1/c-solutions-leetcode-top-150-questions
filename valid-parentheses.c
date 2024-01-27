**Valid Parentheses**

Problem Statement 53) Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
 

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.

-----------------------------------------------------------------------------------------------------------
SOLUTION = bool isValid(char* s) {
    int len = strlen(s);
    if (len % 2 != 0) {  // Odd length string can't be valid
        return false;
    }

    char stack[len];
    int top = -1;

    for (int i = 0; i < len; i++) {
        char ch = s[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            // Push opening brackets onto the stack
            stack[++top] = ch;
        } else {
            if (top == -1) {
                // No matching opening bracket
                return false;
            }
            char match;
            switch (ch) {
                case ')': match = '('; break;
                case '}': match = '{'; break;
                case ']': match = '['; break;
            }
            if (stack[top--] != match) {
                // Mismatched brackets
                return false;
            }
        }
    }

    return top == -1;  // True if all brackets are matched
}

-------------------------------------Explanation :-
Purpose:

This code determines whether a given string s containing parentheses, braces, and brackets has balanced brackets.
Function Breakdown:

Initialization:

Finds the length of s using strlen.
If len is odd, returns false immediately (odd-length strings cannot be balanced).
Creates a character array stack of size len to keep track of opening brackets.
Initializes top to -1 to represent an empty stack.
Iterating and Matching Brackets:

Iterates through each character ch in s:
If ch is an opening bracket ((, {, or [):
Pushes it onto the stack.
If ch is a closing bracket (), }, or ]):
Checks if the stack is empty (top == -1):
If so, returns false (no matching opening bracket).
Determines the corresponding opening bracket using a switch statement.
Pops the top element from the stack.
If the popped element doesn't match the expected opening bracket, returns false (mismatched brackets).
Checking for Balanced Brackets:

Returns true if the stack is empty (top == -1), indicating all brackets are matched.
Key Points:

Stack for Tracking: Uses a stack to keep track of opening brackets and match them with corresponding closing brackets.
Mismatch Detection: Detects mismatched brackets by comparing popped opening brackets with closing brackets.
Early Termination: Returns false early for odd-length strings and empty stacks (no matching opening bracket).
Time Complexity: O(n), where n is the length of s, due to linear iteration.
Space Complexity: O(n) for the stack in the worst case (all opening brackets).
