**Happy Number**

Problem Statement 46) Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:

Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy.
Return true if n is a happy number, and false if not.

 

Example 1:

Input: n = 19
Output: true
Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
Example 2:

Input: n = 2
Output: false
 

Constraints:

1 <= n <= 231 - 1

--------------------------------------------------------------------------------------------------------------------------------------
SOLUTION = bool isHappy(int n) {
    int slow = n, fast = n;
    do {
        slow = getNext(slow);
        fast = getNext(getNext(fast));
    } while (slow != fast);
    return slow == 1;
}

int getNext(int n) {
    int sum = 0, tmp;
    while (n > 0) {
        tmp = n % 10;
        sum += tmp * tmp;
        n /= 10;
    }
    return sum;
}

----------------------------------Explanation :-
Purpose:

This code determines whether a given number n is a happy number. A happy number is defined as a number that eventually reaches 1 when repeatedly replaced by the sum of the squares of its digits.
Function Breakdown:

getNext Function:

This function calculates the next number in the happy number sequence:
It takes an integer n as input.
It initializes a sum variable sum to 0.
It iterates through each digit of n:
It extracts the last digit using n % 10.
It squares the digit and adds it to sum.
It removes the last digit from n using n /= 10.
It returns the calculated sum, which is the next number in the sequence.
isHappy Function:

Initialization:

It creates two variables, slow and fast, both initialized to n. These variables will iterate through the sequence at different speeds.
Floyd's Cycle-Finding Algorithm:

It enters a do-while loop:
It updates slow to the next number in the sequence using getNext(slow).
It updates fast to the number two steps ahead using getNext(getNext(fast)).
The loop continues as long as slow and fast are not equal.
Happy Number Check:

If the loop terminates with slow equal to fast, it checks if slow (and therefore fast) is equal to 1. If so, it returns true because the sequence has reached 1, indicating a happy number.
If the loop terminates with slow not equal to 1, it means the sequence has entered a cycle, and the number is not happy. It returns false.
Key Points:

Cycle Detection: Leverages Floyd's cycle-finding algorithm to efficiently detect cycles in the sequence.
Happy Number Property: Relies on the property that happy numbers eventually reach 1, while non-happy numbers enter a cycle.
Time Complexity: Average-case O(log n), worst-case O(n), depending on the length of the cycle.
Space Complexity: O(1), using constant extra space.
