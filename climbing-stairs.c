**Climbing Stairs**

Problem Solving 129) You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
 

Constraints:

1 <= n <= 45

---------------------------------------------------------------------------------
SOLUTION = int climbStairs(int n)
{
    if (n < 1)
        return 1;
    else if (n < 4)
        return n;
    else if (n > 45)
        return -1;
    
    int first = 2;
    int second = 3;
    while (3 < n--)
    {
        int temp = first + second;
        first = second;
        second = temp;
    }

    return second;
}

----Explanation :-
Dynamic Programming Approach:

Base Cases:

The code handles two base cases:
If n is less than 1 (negative stairs), it returns 1. This might be specific to the problem being solved and could be adjusted depending on the intended behavior for negative inputs.
If n is less than 4, it simply returns n. There's only one way to climb 1 or 2 stairs, and 3 stairs can be climbed in two ways (1+2 or 2+1).
Handling Large n (Optional):

The code includes an optional check for n greater than 45. If enabled, it returns -1 in this case. This could be a way to handle potential overflow issues for very large n values, depending on the integer size used.
Dynamic Programming:

The core calculation leverages dynamic programming, a technique for solving problems by breaking them down into smaller subproblems and storing the results to avoid redundant calculations.
It initializes two variables:
first starting with 2 (number of ways to climb 2 stairs).
second starting with 3 (number of ways to climb 3 stairs).
It enters a while loop that continues as long as n is greater than 3.
In each iteration:
A temporary variable temp is used to store the total number of ways to climb n stairs. This is calculated by adding the number of ways to climb n-1 stairs (stored in second) and the number of ways to climb n-2 stairs (stored in first).
The value in first is then updated to the previous value of second.
The value in second is updated to the newly calculated total ways (temp).
By the end of the loop, second will hold the total number of ways to climb n stairs.
Return the Result:

After the loop completes, the function returns the value stored in second, which represents the number of distinct ways to climb n stairs.
