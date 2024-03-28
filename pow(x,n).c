**Pow(x,n)**

Problem Solving 127)Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

 

Example 1:

Input: x = 2.00000, n = 10
Output: 1024.00000
Example 2:

Input: x = 2.10000, n = 3
Output: 9.26100
Example 3:

Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
 

Constraints:

-100.0 < x < 100.0
-231 <= n <= 231-1
n is an integer.
Either x is not zero or n > 0.
-104 <= xn <= 104

---------------------------------------------------------------------------------------------------
SOLUTION = double myPow(double x, int n){
    bool   neg = n < 0;
    double a   = 1.0;
    long   l   = n;
    
    if (neg) l = -l;
    
    while (l > 0) {
        double t = x;
        long   c = 2;
        while (c < l) {
            t = t*t;
            c = c*2;
        }

        a = a*t;
        l = l - c/2;
    }
    
    return neg ? 1.0/a : a;
}

-----Explanation :-
Handling Negative Exponents:

It declares a boolean variable neg to check if the exponent (n) is negative.
If n is negative, it sets neg to true and converts n to its absolute value by assigning it to a long variable l. This is done because negative exponents are handled separately later.
Iterative Exponentiation:

It initializes a double variable a to 1.0 (accumulator for the result).
The core calculation happens in a while loop that continues as long as l (the absolute value of the exponent) is greater than 0.
In each iteration:
Base Case: If l is 1, it means x needs to be raised to the power of 1, which is simply x itself. So, it multiplies a by x and exits the loop (handled within the while condition).
Efficient Squaring: It initializes a double variable t to x. This variable will store the intermediate squared values of x.
Another while loop is nested within the outer loop to perform efficient squaring. This inner loop keeps multiplying t by itself as long as c (a counter variable) is less than l.
The key optimization here is that instead of calculating x multiplied by itself repeatedly, it squares the current value in t and updates the counter (c) by multiplying it by 2 in each iteration. This effectively reduces the number of multiplications required.
Once the inner loop terminates (when c becomes greater than or equal to l), t holds x raised to a power that is close to, but not necessarily equal to, l.
The value in t is then multiplied into the accumulator a.
To calculate the remaining exponent, l is subtracted by half of c (because the inner loop might have overshot the exact power needed).
Handling Negative Exponents:

After the outer loop completes, a will hold the result of x raised to the power of l.
If the original exponent n was negative (neg is true), it calculates the reciprocal of a (1.0 divided by a) to account for the negative exponent.
Return the Result:

Finally, the function returns the value in a (if n was positive or zero) or 1.0 divided by a (if n was negative).
